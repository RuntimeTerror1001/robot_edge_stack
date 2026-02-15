#!/usr/bin/env python3
"""
Network Monitor Node
Measures network conditions between laptop and Jetson.
Runs on: Laptop
"""

import re
import subprocess
import time
from dataclasses import dataclass

import rclpy
from rclpy.node import Node
from stack_msgs.msg import NetworkHealth

@dataclass
class PingResult:
    rtt_min: float = -1.0
    rtt_avg: float = -1.0
    rtt_max: float = -1.0
    rtt_stddev: float = -1.0
    packet_loss: float = 100.0

class NetworkMonitorNode(Node):

    def __init__(self):
        super().__init__('network_monitor_node')

        self.declare_parameter('jetson_ip', '192.168.1.100')
        self.declare_parameter('ethernet_interface', 'enp8s0')
        self.declare_parameter('publish_rate_hz', 1.0)
        self.declare_parameter('ping_count', 5)
        
        self.jetson_ip = self.get_parameter('jetson_ip').value
        self.ethernet_interface = self.get_parameter('ethernet_interface').value
        self.ping_count = self.get_parameter('ping_count').value

        # Bandwidth tracking via proc/net/dev
        # Tracks both RX (available) & TX (utilized)
        self.last_rx_bytes = 0
        self.last_tx_bytes = 0
        self.last_bw_measure_time = 0.0
        self.last_measure_time = time.time()

        self.pub = self.create_publisher(
            NetworkHealth,
            '/network/health',
            10
        )

        rate = self.get_parameter('publish_rate_hz').value
        timer_period = max(1.0 / rate, float(self.ping_count) + 2.0)
        if timer_period > 1.0 / rate:
            self.get_logger().warn(
                f'Timer period adjusted to {timer_period:.1f}s to accommodate '
                f'ping_count={self.ping_count}. Lower ping_count to increase rate.'
            )
        self.create_timer(timer_period, self.measure_and_publish)

        self.get_logger().info(
            f'Network monitor started | target: {self.jetson_ip} | '
            f'interface: {self.ethernet_interface}'
        )

    def measure_latency_and_loss(self) -> PingResult:
        """
        Run ping and parse all RTT values + packet loss.

        Parses:
            rtt min/avg/max/mdev = 0.1/0.4/0.9/0.1 ms
            5 packets transmitted, 4 received, 20% packet loss
        """
        result = PingResult()

        try:
            proc = subprocess.run(
                [
                    'ping',
                    '-c', str(self.ping_count),
                    '-W', '1',
                    self.jetson_ip
                ],
                capture_output=True,
                text=True,
                timeout=float(self.ping_count) + 2.0
            )

            # Parse packet loss
            # Example: "5 packets transmitted, 4 received, 20% packet loss"
            loss_match = re.search(
                r'(\d+)% packet loss',
                proc.stdout
            )
            if loss_match:
                result.packet_loss = float(loss_match.group(1)) 

            # Parse average latency
            # Example: "rtt min/avg/max/mdev = 0.1/0.4/0.9/0.1 ms"
            rtt_match = re.search(
                r'rtt min/avg/max/mdev = '
                r'([\d.]+)/([\d.]+)/([\d.]+)/([\d.]+) ms',
                proc.stdout
            )
            if rtt_match:
                result.rtt_min    = float(rtt_match.group(1))
                result.rtt_avg    = float(rtt_match.group(2))
                result.rtt_max    = float(rtt_match.group(3))
                result.rtt_stddev = float(rtt_match.group(4))
        
        except subprocess.TimeoutExpired:
            self.get_logger().error('Ping timed out')
        except Exception as e:
            self.get_logger().error(f'Ping failed: {e}')
        
        return result
        
    def measure_bandwidth(self) -> tuple[float, float]:
        """
        Calculate RX and TX rates from /proc/net/dev.

        Returns:
            Tuple of (rx_mbps, tx_mbps). Returns (0.0, 0.0) on first call
            or error (avoids garbage values from cumulative counter).
        """
        try:
            with open('/proc/net/dev', 'r') as f:
                lines = f.readlines()

            # Find ethernet interface line
            rx_bytes = tx_bytes = 0
            for line in lines:
                if self.ethernet_interface in line:
                    # Format: interface: rx_bytes rx_packets rx_errs ... tx_bytes ...
                    fields = line.split()
                    rx_bytes = int(fields[1])
                    tx_bytes = int(fields[9])
                    break
                        
            now = time.time()

            # First run: store baseline, return 0 to avoid reporting the full
            # cumulative counter since boot as a single-interval rate
            if self.last_bw_measure_time == 0.0:
                self.last_rx_bytes = rx_bytes
                self.last_tx_bytes = tx_bytes
                self.last_bw_measure_time = now
                return 0.0, 0.0

            elapsed = now - self.last_bw_measure_time
            if elapsed <= 0:
                return 0.0, 0.0
            
            rx_mbps = ((rx_bytes - self.last_rx_bytes) * 8) / (elapsed * 1_000_000)
            tx_mbps = ((tx_bytes - self.last_tx_bytes) * 8) / (elapsed * 1_000_000)

            # Update State
            self.last_rx_bytes = rx_bytes
            self.last_tx_bytes = tx_bytes
            self.last_measure_time = now

            return max(0.0, rx_mbps), max(0.0, tx_mbps)
        
        except Exception as e:
            self.get_logger().warn(f'Bandwidth Measure failed: {e}')
            return 0.0, 0.0
        
    def compute_quality_score(self, ping: PingResult, rx_mbps: float) -> int:
        """
        Derive a 0-100 quality score from loss, latency, and bandwidth.

        Deductions:
            - Packet loss: 2 points per 1% loss
            - High latency: 1 point per 10ms over 50ms baseline
            - Low bandwidth: 10 points if RX < 10 Mbps
        """
        score = 100.0

        score -= ping.packet_loss * 2.0

        if ping.rtt_avg > 50.0:
            score -= (ping.rtt_avg - 50.0) / 10.0
        
        if 0.0 < rx_mbps < 10.0:
            score -= 10.0

        return max(0, min(100, int(score)))
        
    def measure_and_publish(self) -> None:
        """Main measurement loop."""
        ping = self.measure_latency_and_loss()
        rx_mbps, tx_mbps = self.measure_bandwidth()
        quality = self.compute_quality_score(ping, rx_mbps)

        msg = NetworkHealth()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.interface_name = self.ethernet_interface
        msg.rtt_min = ping.rtt_min
        msg.rtt_avg = ping.rtt_avg
        msg.rtt_max = ping.rtt_max
        msg.rtt_stddev = ping.rtt_stddev
        msg.packet_loss_percent = ping.packet_loss
        msg.available_bandwidth = rx_mbps
        msg.utilized_bandwidth = tx_mbps
        msg.quality_score = quality
        msg.is_stable = quality >= 70 and ping.packet_loss < 2.0

        self.pub.publish(msg)

        self.get_logger().info(
            f'RTT: {ping.rtt_avg:.1f}ms (min={ping.rtt_min:.1f} max={ping.rtt_max:.1f} '
            f'dev={ping.rtt_stddev:.1f}) | '
            f'Loss: {ping.packet_loss:.1f}% | '
            f'RX: {rx_mbps:.1f}Mbps TX: {tx_mbps:.1f}Mbps | '
            f'Quality: {quality}/100 | Stable: {msg.is_stable}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = NetworkMonitorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()