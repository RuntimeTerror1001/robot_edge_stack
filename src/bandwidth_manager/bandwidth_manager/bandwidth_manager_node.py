#!/usr/bin/env python3
"""
Bandwidth Manager Node
Monitors network health and system metrics, then dynamically adjusts
the perception node's target_fps via ROS 2 parameter service.

Runs on: Jetson
Subscribes: /network/health, /system/health
Controls:   /perception_node target_fps parameter
"""

import os
import yaml
import time

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.srv import SetParameters

from stack_msgs.msg import NetworkHealth, SystemMetrics

# Mode -> target FPS sent to the perception node
FPS_MAP = {
    'NORMAL': 15,
    'DEGRADED': 10,
    'CRITICAL': 5
}

class BandwidthManagerNode(Node):
    
    def __init__(self):
        super().__init__('bandwidth_manager')

        # Parameters
        self.declare_parameter('config_file', '')
        self.declare_parameter('perception_node_name', '/perception_node')

        config_file = self.get_parameter('config_file').value
        self.perception_node = self.get_parameter('perception_node_name').value

        self.config = self._load_config(config_file)

        # State
        self.current_mode = 'NORMAL'
        self.network_msg: NetworkHealth | None = None
        self.system_msg: SystemMetrics | None = None
        self._last_mode_change_time = 0.0

        # Subsciptions
        self.create_subscription(
            NetworkHealth,
            '/network/health',
            self._on_network_health,
            10
        )
        self.create_subscription(
            SystemMetrics,
            '/system/metrics',
            self._on_system_metrics,
            10
        )

        # Client
        self._param_client = self.create_client(
            SetParameters,
            f'{self.perception_node}/set_parameters'
        )

        # Evaluation Timer
        period = self.config['evaluation_period_sec']
        self.create_timer(period, self._evaluate)

        self.get_logger().info(
            f'Bandwidth manager started | '
            f'evaluation every {period}s | '
            f'perception node: {self.perception_node}'
        )
        self._log_thresholds()

    def _load_config(self, config_file: str) -> dict:
        defaults = {
            'evaluation_period_sec': 2.0,
            'mode_change_cooldown_sec': 5.0,
            'thresholds': {
                'quality_degraded': 70,
                'quality_critical': 40,
                'packet_loss_degraded': 2.0,
                'packet_loss_critical': 5.0,
                'bandwidth_low_mbps': 10.0,
                'cpu_high': 80.0,
                'gpu_high': 85.0,
                'temp_critical': 85.0
            },
        }

        if config_file and os.path.exists(config_file):
            try:
                with open(config_file) as f:
                    overrides = yaml.safe_load(f) or {}
                    # Deep merge thresholds
                    defaults['thresholds'].update(
                        overrides.pop('thresholds', {})
                    )
                    defaults.update(overrides)
                    self.get_logger().info(f'Loaded config: {config_file}')
            except Exception as e:
                self.get_logger().warn(f'Config load failed ({e}), using defaults')
        
        else:
            self.get_logger().info('Using default configuration')

        return defaults
    
    def _log_thresholds(self):
        t = self.config['thresholds']
        self.get_logger().info(
            f'Thresholds - quality: degraded<{t["quality_degraded"]} '
            f'critical<{t["quality_critical"]} '
            f'loss: degraded>{t["packet_loss_degraded"]}% '
            f'critical>{t["packet_loss_critical"]}%'
        )

    def _on_network_health(self, msg: NetworkHealth) -> None:
        self.network_msg = msg
    
    def _on_system_metrics(self, msg: SystemMetrics) -> None:
        self.system_msg = msg

    def _evaluate(self) -> None:
        if self.network_msg is None:
            self.get_logger().warn('Waiting for /network/health...', once=True)
            return
        if self.system_msg is None:
            self.get_logger().warn('Waiting for /system/metrics...', once=True)
            return
        
        required_mode = self._determine_mode()

        if required_mode != self.current_mode:
            now = time.monotonic()
            cooldown = self.config['mode_change_cooldown_sec']
            if now - self._last_mode_change_time < cooldown:
                return
            self._apply_mode(required_mode)

    def _determine_mode(self) -> str:
        net = self.network_msg
        sys = self.system_msg
        t = self.config['thresholds']

        # CRITICAL: severe network failure OR thermal/system emergency
        if (net.quality_score < t['quality_critical'] or
            net.packet_loss_percent > t['packet_loss_critical'] or
            sys.cpu_temp_celsius >= t['temp_critical'] or
            sys.gpu_temp_celsius >= t['temp_critical'] or
            sys.is_throttled):
            return 'CRITICAL'
        
        # DEGRADED: network or compute under meaningful pressure

        # Only check bandwidth if non-zero
        bandwidth_degraded = (net.available_bandwidth > 0.0 and 
                              net.available_bandwidth < t['bandwidth_low_mbps'])
        
        if (net.quality_score        < t['quality_degraded']       or
            net.packet_loss_percent  > t['packet_loss_degraded']   or
            bandwidth_degraded                                     or
            sys.cpu_percent          > t['cpu_high']               or
            sys.gpu_percent          > t['gpu_high']               or
            not net.is_stable):
            return 'DEGRADED'

        return 'NORMAL'
    
    def _apply_mode(self, new_mode: str) -> None:
        old_mode = self.current_mode
        self.current_mode = new_mode
        self._last_mode_change_time = time.monotonic()

        target_fps = FPS_MAP[new_mode]

        self.get_logger().info(
            f'Mode: {old_mode} -> {new_mode} | '
            f'setting target_fps={target_fps} on {self.perception_node}'
        )
        self._log_reason(new_mode)
        self._set_perception_fps(target_fps)

    def _log_reason(self, mode: str) -> None:
        net = self.network_msg
        sys = self.system_msg
        t = self.config['thresholds']
        reasons = []

        if mode != 'NORMAL':
            if net.quality_score < t.get(f'quality_{mode.lower()}', 100):
                reasons.append(f'quality={net.quality_score}')
            if net.packet_loss_percent > t.get(f'packet_loss_{mode.lower()}', 0.0):
                reasons.append(f'loss={net.packet_loss_percent:.1f}%')
            if net.available_bandwidth > 0.0 and net.available_bandwidth < t['bandwidth_low_mbps']:
                reasons.append(f'bandwidth={net.available_bandwidth:.1f}Mbps')
        
        if not net.is_stable:
            reasons.append('network_unstable')
        if sys.is_throttled:
            reasons.append('thermal_throttled')
        if sys.cpu_percent > t['cpu_high']:
            reasons.append(f'cpu={sys.cpu_percent:.1f}%')
        if sys.gpu_percent > t['gpu_high']:
            reasons.append(f'gpu={sys.gpu_percent:.1f}%')

        if reasons:
            self.get_logger().info(f'  Reason: {", ".join(reasons)}')
        else:
            self.get_logger().info('  Reason: conditions improved')

    def _set_perception_fps(self, fps: int) -> None:
        """
        Set target_fps on the perception node via async parameter client.
        Creates the client on first use (perception node need not be alive at startup).
        """
        try:
            if not self._param_client.service_is_ready():
                self.get_logger().info('Waiting for parameter service...')
                return

            # Convert paramter object to message
            param_msg = Parameter('target_fps', Parameter.Type.INTEGER, fps).to_parameter_msg()   

            # Create request
            request = SetParameters.Request()
            request.parameters = [param_msg]

            # Call asynchronously
            future = self._param_client.call_async(request)
            future.add_done_callback(lambda f: self._on_param_set(f, fps))  

        except Exception as e:
            self.get_logger().error(f'Failed to call parameter service: {e}')

    def _on_param_set(self, future, fps: int) -> None:
        try:
            result = future.result()
            if result and all(r.successful for r in result.results):
                self.get_logger().info(f'   target_fps = {fps} confirmed')
            else:
                reasons = [r.reason for r in result.results if not r.successful]
                self.get_logger().warn(f'   Parameter set failed: {reasons}')
        
        except Exception as e:
            self.get_logger().error(f'   Parameter service error: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = BandwidthManagerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
