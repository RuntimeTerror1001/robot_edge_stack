#!/usr/bin/env python3
"""
Watchdog Node - Monitors liveness of all critical nodes.
Restarts Docker containers if nodes become unresponsive.

Runs on: Jetson
Subscribes: All critical topics
Publishes: /system/health_status
"""

import subprocess
import time
from dataclasses import dataclass
from typing import Dict
from enum import Enum

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from sensor_msgs.msg import Image
from std_msgs.msg import String

class NodeHealth(Enum):
    HEALTHY = "HEALTHY"
    DEGRADED = "DEGRADED"
    DEAD = "DEAD"

@dataclass
class TopicWatcher:
    """Tracks health of a single topic."""
    topic_name: str
    docker_service: str
    staleness_threshold_sec: float
    last_received_time: float = 0.0
    health: NodeHealth = NodeHealth.DEAD

class WatchdogNode(Node):
    """
    Monitors all critical topics for staleness.
    Restarts corresponding Docker containers when nodes die.
    
    Recovery behavior:
        - HEALTHY: Messages arriving within threshold
        - DEGRADED: Messages late but still arriving
        - DEAD: No messages for > threshold → restart container
    """

    # Restart Cooldown (Doesn't restart same container repeatedly)
    RESTART_COOLDOWN_SEC = 30.0

    def __init__(self):
        super().__init__("watchdog")

        # Parameters
        self.declare_parameter('check_interval_sec', 2.0)
        self.declare_parameter('compose_project_dir', '/ws')
        
        self.compose_dir = self.get_parameter('compose_project_dir').value

        # Track last restart time per service (prevent restart loops)
        self.last_restart_time: Dict[str, float] = {}

        # Define topics to watch
        # Maps topic -> (docker service, staleness threshold)
        self.watchers: Dict[str, TopicWatcher] = {
            '/front_camera/image_raw': TopicWatcher(
                topic_name='/front_camera/image_raw',
                docker_service='camera_front',
                staleness_threshold_sec=3.0
            ),

            '/rear_camera/image_raw': TopicWatcher(
                topic_name='rear_camera/image_raw',
                docker_service='camera_rear',
                staleness_threshold_sec=3.0
            ),

            '/heartbeat': TopicWatcher(
                topic_name='/heartbeat',
                docker_service='skeleton',
                staleness_threshold_sec=5.0
            ),
        }

        # QoS - best effort
        qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=1
        )

        # Subscribe to all watched topics
        self.create_subscription(
            Image, '/front_camera/image_raw',
            lambda msg: self._touch('/front_camera/image_raw'), qos
        )
        self.create_subscription(
            Image, '/rear_camera/image_raw',
            lambda msg: self._touch('/rear_camera/image_raw'), qos
        )
        self.create_subscription(
            String, '/heartbeat',
            lambda msg: self._touch('/heartbeat'), qos
        )

        # Health Status Publisher
        self.health_pub = self.create_publisher(
            String, '/system/health_status', 10
        )

        # Check timer
        interval = self.get_parameter('check_interval_sec').value
        self.create_timer(interval, self.check_health)

        self.get_logger().info('Watchdog Started.')

    def _touch(self, topic: str) -> None:
        """Update last received time for a topic."""
        if topic in self.watchers:
            self.watchers[topic].last_received_time = time.time()
    
    def _get_node_health(self, watcher: TopicWatcher) -> NodeHealth:
        """
        Determine health of a node based on topic staleness.
        
        Returns:
            NodeHealth enum value
        """
        if watcher.last_received_time == 0.0:
            # Never received a message
            return NodeHealth.DEAD
        
        age = time.time() - watcher.last_received_time

        if age <= watcher.staleness_threshold_sec:
            return NodeHealth.HEALTHY
        elif age <= watcher.staleness_threshold_sec * 2:
            return NodeHealth.DEGRADED
        else:
            return NodeHealth.DEAD
        
    def _restart_service(self, service_name: str) -> bool:
        """
        Restart a Docker Compose service.
        
        Args:
            service_name: Name of the service in docker-compose.yaml

        Returns:
            True if restart succeeded, False otherwise
        """
        # Check cooldown
        last_restart = self.last_restart_time.get(service_name, 0.0)
        if time.time() - last_restart < self.RESTART_COOLDOWN_SEC:
            self.get_logger().warn(
                f'Skipping restart of {service_name} - cooldown active'
                f'({self.RESTART_COOLDOWN_SEC}s)'
            )
            return False
        
        self.get_logger().warn(f'Restarting Service: {service_name}')

        try:
            result = subprocess.run(
                [
                    'docker', 'compose',
                    '--project-directory', self.compose_dir,
                    '-f', f'{self.compose_dir}/docker/compose/robot.compose.yaml',
                    'restart', service_name
                ],
                capture_output=True,
                text=True,
                timeout=30.0
            )

            if result.returncode == 0:
                self.get_logger().info(
                    f'Successfully restarted {service_name}'
                )
                self.last_restart_time[service_name] = time.time()
                return True
            else:
                self.get_logger().error(
                    f'Failed to restart {service_name}: {result.stderr}'
                )
                return False
        
        except subprocess.TimeoutExpired:
            self.get_logger().error(
                f'Restart of {service_name} timed out'
            )
            return False
        except Exception as e:
            self.get_logger().error(
                f'Restart exception for {service_name}: {e}'
            )
            return False
        
    def check_health(self) -> None:
        """
        Main watchdog loop,
        Check all topics, take action if any are dead.
        """
        status_lines = []
        any_dead = False

        for topic, watcher in self.watchers.items():
            health = self._get_node_health(watcher)
            watcher.health = health

            age = time.time() - watcher.last_received_time
            status_lines.append(
                f'{topic}: {health.value} (age: {age:.1f}s)'
            )

            if health == NodeHealth.DEAD:
                any_dead = True
                self.get_logger().error(
                    f'Node DEAD: {topic} -> restarting {watcher.docker_service}'
                )
                self._restart_service(watcher.docker_service)
            
            elif health == NodeHealth.DEGRADED:
                self.get_logger().warn(
                    f'Node DEGRADED: {topic} (age: {age:.1f}s)'
                )
        
        overall = 'DEGRADED' if any_dead else 'HEALTHY'
        status_msg = String()
        status_msg.data = f'{overall} | ' + ' | '.join(status_lines)
        self.health_pub.publish(status_msg)

        #Log summary
        self.get_logger().info(f'System: {overall}')

def main(args=None):
    rclpy.init(args=args)
    node = WatchdogNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()