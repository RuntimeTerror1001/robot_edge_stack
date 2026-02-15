#!/usr/bin/env python3
"""
System Metrics Node
Publishes hardware utilization from Jetson.
Runs on: Jetson
"""

import re
import subprocess
from dataclasses import dataclass, field

import psutil
import rclpy
from rclpy.node import Node
from stack_msgs.msg import SystemMetrics

# Thresholds for deriving system_healthy
CPU_CRITICAL = 95.0
GPU_CRITICAL = 95.0
TEMP_CRITICAL = 85.0
RAM_CRITICAL = 95.0

@dataclass
class TegrastatsReading:
    """Parsed output from a single tegrastats sample."""
    gpu_percent:      float = 0.0
    gpu_freq_mhz:     int   = 0
    gpu_temp_celsius: float = 0.0
    cpu_temp_celsius: float = 0.0
    power_draw_mw:    int   = 0
    is_throttled:     bool  = False

class SystemMetricsNode(Node):

    def __init__(self):
        super().__init__('system_metrics_node')

        self.declare_parameter('publish_rate_hz', 1.0)

        self.pub = self.create_publisher(
            SystemMetrics,
            '/system/metrics',
            10
        )

        rate = self.get_parameter('publish_rate_hz').value
        self.create_timer(1.0 / rate, self.publish_metrics)

        self.get_logger().info('System Metrics Node started.')

    def _read_tegrastats(self) -> TegrastatsReading:
        """
        Run tegrastats for one sample and parse all relevant fields.

        tegrastats is a continuous stream; we kill it after one line via timeout.
        The captured output lives in TimeoutExpired.stdout — this is intentional.

        Example line:
            RAM 1879/7773MB CPU [6%@1190,...] GR3D_FREQ 45%@765
            GPU@46.5C CPU@47.5C VDD_IN 3728mW/3728mW
        """
        reading = TegrastatsReading()
        output = ''

        try:
            # Tegrastats streams forever; timeout kills it after 1 sample
            subprocess.run(
                ['tegrastats', '--interval', '200'],
                capture_output=True,
                text=True,
                timeout=0.5
            )
        except subprocess.TimeoutExpired as e:
            raw = e.stdout or b''
            output = raw.decode('utf-8', errors='replace') if isinstance(raw, bytes) else raw
        except FileNotFoundError:
            self.get_logger().warn('tegrastats not found — are you on a Jetson?')
            return reading
        except Exception as e:
            self.get_logger().warn(f'tegrastats error: {e}')
            return reading

        if not output:
            return reading
        
        # GPU Utilization and Frequency: GR3D_FREQ 45%@765
        gpu_match = re.search(r'GR3D_FREQ (\d+)%@(\d+)', output)
        if gpu_match:
            reading.gpu_percent = float(gpu_match.group(1))
            reading.gpu_freq_mhz = int(gpu_match.group(2))

        # GPU Temperature: gpu@46.5C
        gpu_temp_match = re.search(r'gpu@([\d.]+)C', output)
        if gpu_temp_match:
            reading.gpu_temp_celsius = float(gpu_temp_match.group(1))

        # CPU Temperature: cpu@47.5C
        cpu_temp_match = re.search(r'cpu@([\d.]+)C', output)
        if cpu_temp_match:
            reading.cpu_temp_celsius = float(cpu_temp_match.group(1))

        # Power Draw: VDD_IN 3728mW/3728mW
        power_match = re.search(r'VDD_IN (\d+)mW', output)
        if power_match:
            reading.power_draw_mw = int(power_match.group(1))

        reading.is_throttled = self._is_cpu_throttled()

        return reading
    
    def _is_cpu_throttled(self) -> bool:
        """
        Check if the CPU is being thermally throttled by comparing
        the current frequency to the maximum allowed frequency.
        Uses policy0 (big core cluster on Orin Nano).
        """
        try:
            base = '/sys/devices/system/cpu/cpufreq/policy0'
            with open(f'{base}/scaling_cur_freq') as f:
                cur = int(f.read().strip())
	    with open(f'{base}/scaling_min_freq') as f:
	        min_freq = int(f.read().strip())
            with open(f'{base}/scaling_max_freq') as f:
                max_freq = int(f.read().strip())

            # Governer idles down to min_freq normally - is not throttling.
	    # Only flag throttled if pinned at min while max is much higher
  	    # And we can't scale up (i.e. something is forcing down).
	    # Cross-check : if cur is at min but temp is cool, its is idling.
	    try:
	        with open('/sys/class/thermal/thermal_zone1/temp') as f:
		    temp_mc = int(f.read().strip())  # millicelsius
		temp_c = temp_mc / 1000.0
		# At idle temps (<65C), min freq = governor choice, not throttle
		if temp_c < 65.0:
		    return False
	    except Exception:
		pass

            return cur <= min_freq and max_freq > min_freq * 2

        except Exception:
            return False
        
    def publish_metrics(self) -> None:
        """Collect & Publish all metrics."""
        tegra = self._read_tegrastats()
        vm = psutil.virtual_memory()

        ram_used_mb = int(vm.used / 1024 / 1024)
        ram_total_mb = int(vm.total / 1024 / 1024)
        cpu_percent = float(psutil.cpu_percent(interval=None))
        ram_percent = float(vm.percent)

        system_healthy = not (
            cpu_percent >= CPU_CRITICAL or
            tegra.gpu_percent >= GPU_CRITICAL or
            tegra.cpu_temp_celsius >= TEMP_CRITICAL or
            tegra.gpu_temp_celsius >= TEMP_CRITICAL or
            ram_percent >= RAM_CRITICAL or
            tegra.is_throttled
        )

        msg = SystemMetrics()
        msg.header.stamp       = self.get_clock().now().to_msg()
        msg.cpu_percent        = cpu_percent
        msg.cpu_temp_celsius   = tegra.cpu_temp_celsius
        msg.gpu_percent        = tegra.gpu_percent
        msg.gpu_temp_celsius   = tegra.gpu_temp_celsius
        msg.gpu_freq_mhz       = tegra.gpu_freq_mhz
        msg.ram_used_mb        = ram_used_mb
        msg.ram_total_mb       = ram_total_mb
        msg.ram_percent        = ram_percent
        msg.is_throttled       = tegra.is_throttled
        msg.power_draw_mw      = tegra.power_draw_mw
        msg.system_healthy     = system_healthy

        self.pub.publish(msg)

        self.get_logger().info(
            f'CPU: {cpu_percent:.1f}% @ {tegra.cpu_temp_celsius:.1f}°C | '
            f'GPU: {tegra.gpu_percent:.1f}% @ {tegra.gpu_freq_mhz}MHz '
            f'{tegra.gpu_temp_celsius:.1f}°C | '
            f'RAM: {ram_used_mb}/{ram_total_mb}MB ({ram_percent:.1f}%) | '
            f'Power: {tegra.power_draw_mw}mW | '
            f'Throttled: {tegra.is_throttled} | '
            f'Healthy: {system_healthy}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = SystemMetricsNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
