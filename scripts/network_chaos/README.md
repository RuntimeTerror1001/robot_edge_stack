# Network Chaos Engineering Scripts

Inject realistic network degradation to test the adaptive bandwidth management system.

**Run these on the LAPTOP**, not the Jetson. They affect the laptop's Ethernet interface to degrade the link between laptop and Jetson.

## Prerequisites
```bash
# Verify your interface name
ip link show

# If not enp8s0, pass your interface name as first argument to all scripts
```

## Usage

### Make scripts executable (one-time)
```bash
chmod +x *.sh
```

### Test 1: High Latency (Slow Network)
```bash
./inject_latency.sh enp8s0 100ms
```

**Expected:** RTT jumps to ~100ms, but bandwidth and packet loss stay normal. System stays in NORMAL mode.

### Test 2: Packet Loss (Unreliable Connection)
```bash
./inject_loss.sh enp8s0 5%
```

**Expected:** 
- packet_loss_percent shows ~5%
- Triggers CRITICAL mode (>5% threshold)
- FPS drops: 15 → 5
- Camera stream stutters

### Test 3: Network Jitter (Unstable Connection)
```bash
./inject_jitter.sh enp8s0 50ms 30ms
```

**Expected:**
- RTT varies between 20-80ms
- rtt_stddev increases
- is_stable may toggle to False
- May trigger DEGRADED mode

### Test 4: Bandwidth Limit (Congestion)
```bash
./inject_bandwidth_limit.sh enp8s0 1mbit
```

**Expected:**
- available_bandwidth drops below 1 Mbps
- Triggers DEGRADED mode (< 10 Mbps threshold)
- FPS drops: 15 → 10
- Camera stream becomes very choppy

### Clear All Rules
```bash
./clear_chaos.sh
```

Returns network to normal operation.

## Demo Workflow

**Full adaptive behavior demonstration:**
```bash
# Terminal 1 (Laptop): Monitor network health
ros2 topic echo /network/health

# Terminal 2 (Jetson): Monitor bandwidth manager
make jetson-logs s=bandwidth_manager

# Terminal 3 (Jetson): Monitor perception FPS
make jetson-logs s=perception

# Terminal 4 (Laptop): Inject chaos
./inject_loss.sh enp8s0 2%   # NORMAL → DEGRADED (FPS 15→10)
sleep 10
./inject_loss.sh enp8s0 6%   # DEGRADED → CRITICAL (FPS 10→5)
sleep 10
./clear_chaos.sh             # CRITICAL → NORMAL (FPS 5→15)
```

Watch the logs in Terminals 1-3 to see:
1. Network monitor detecting degradation
2. Bandwidth manager switching modes
3. Perception FPS dropping in response

## Monitoring Commands
```bash
# Network health
ros2 topic echo /network/health

# System metrics
ros2 topic echo /system/metrics

# Bandwidth manager mode
ros2 topic echo /bandwidth_manager/status  # if you added this topic

# Perception detections (includes FPS)
ros2 topic hz /perception/detections

# Current tc rules
tc qdisc show dev enp8s0
```

## Notes

- **These scripts require sudo** — they modify kernel network settings
- **Only affects the laptop's interface** — Jetson is unmodified
- **Changes are temporary** — rebooting the laptop clears all rules
- **Test one rule at a time** — combining latency + loss + jitter can make debugging confusing
- **Camera topics** (`/front_camera/image_raw`) will show degradation first, then perception adapts

## Troubleshooting

**"Cannot find device"**
```bash
# Check your interface name
ip link show
# Use the correct name (might be eth0, eno1, etc.)
./inject_loss.sh eth0 5%
```

**Rules don't seem to apply**
```bash
# Verify rules are active
tc qdisc show dev enp8s0

# If "qdisc noqueue", something cleared them
# Re-run the inject script
```

**Network completely broken**
```bash
# Nuclear option - clear everything
sudo tc qdisc del dev enp8s0 root
sudo systemctl restart NetworkManager
```