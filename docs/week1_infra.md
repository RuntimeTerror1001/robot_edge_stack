# Week 1 – Infrastructure Bringup (Iron Skeleton)

## Goal
Establish a headless, production-style robot compute stack on Jetson Orin Nano with:
- static Ethernet networking
- explicit FastDDS discovery (no multicast)
- containerized ROS 2 nodes
- systemd-based auto-start on boot

## Hardware / Network
- Jetson Orin Nano (SSD boot, JetPack 6.1, L4T R36.4.2)
- Laptop operator station
- Gigabit Ethernet switch
- Static IPs on Ethernet interfaces

## Architecture Decisions
- ROS 2 runs **only inside Docker containers** on the robot
- FastDDS Discovery Server used instead of multicast
- Discovery config driven by XML (CLIENT on robot, SUPER_CLIENT on laptop)
- `docker compose` used for robot bringup
- `systemd` used to ensure autonomous boot

## What Works (Validated)
- Cold boot → containers start automatically
- `/heartbeat` topic visible on laptop without manual intervention
- Reboot-safe behavior
- Headless operation confirmed

## Known Gotchas
- ROS 2 CLI daemon on laptop may need restart after discovery changes
- Use `ros2 topic list --no-daemon` when validating bringup

## Next Step
- Add USB camera container
- Publish `/camera_front/image_raw`
- Visualize in Foxglove
