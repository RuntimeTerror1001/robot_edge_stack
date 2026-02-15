#!/usr/bin/env python3
"""
QoS Controller
Provides pre-built QoS profiles for each bandwidth mode.
Used by manager_node when adjusting subscriptions/publishers.
"""

from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy

class QoSController:
    """
    Maps bandwidth modes to appropriate ROS 2 QoS profiles.

    NORMAL   → RELIABLE,    depth=10  (full quality, no drops)
    DEGRADED → BEST_EFFORT, depth=3   (low latency over delivery guarantee)
    CRITICAL → BEST_EFFORT, depth=1   (bare minimum traffic)
    """

    PROFILES = {
        'NORMAL': QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
            durability=DurabilityPolicy.VOLATILE
        ),
        'DEGRADED': QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=3,
            durability=DurabilityPolicy.VOLATILE
        ),
        'CRITICAL': QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
            durability=DurabilityPolicy.VOLATILE
        )
    }

    @classmethod
    def get_profile(cls, mode:str) -> QoSProfile:
        if mode not in cls.PROFILES:
            raise ValueError(f'Unknown Mode: {mode}. Expected one of {list(cls.PROFILES)}')
        return cls.PROFILES[mode]