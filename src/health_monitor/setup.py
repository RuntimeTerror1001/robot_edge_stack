from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'health_monitor'

setup(
    name=package_name,
    version='0.1.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'config'),
            glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='you@example.com',
    description='Network and system health monitoring for robot edge compute stack',
    license='Apache-2.0',
    extras_require={
        'test': ['pytest'],
    },
    entry_points={
        'console_scripts': [
            'network_monitor = health_monitor.network_monitor_node:main',
            'system_metrics  = health_monitor.system_metrics_node:main',
            'watchdog        = health_monitor.watchdog_node:main',
        ],
    },
)