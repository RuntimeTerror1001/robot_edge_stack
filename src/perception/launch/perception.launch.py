#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('perception'),
        'config',
        'perception_config.yaml'
    )

    return LaunchDescription([
        Node(
            package='perception',
            executable='perception_node',
            name='perception_node',
            output='screen',
            parameters=[config],
        )
    ])