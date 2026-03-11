#!/bin/bash

# Limit available bandwidth between laptop and Jetson
# Run on: Laptop
# Effect: Caps network throughput

set -e

INTERFACE=${1:-enp8s0}
RATE=${2:-1mbit} # e.g., 1mbit, 500kbit, 100kbit

echo "Limiting bandwidth on ${INTERFACE} to ${RATE}"
echo "This simulates a congestion/low-bandwidth connection"

# Remove any existing rules
sudo tc qdisc del dev ${INTERFACE} root 2>/dev/null || true

# Add rate limit
sudo tc qdisc add dev ${INTERFACE} root tbf rate ${RATE} burst 32kbit latency 400ms

echo "Bandwidth limit applied"
echo ""
echo "Current tc rules"
tc qdisc show dev ${INTERFACE}
echo ""
echo "Expected behavior:"
echo "   - Netowrk monitor available_bandwidth will drop below ${RATE}"
echo "   - If bandwidth < 10Mbps: triggers DEGRADED mode"
echo "   - Camera stream will become choppy/delayed"
echo "   - Perception FPS will drop: 15 -> 10 -> 5"
echo ""
echo "To remove: ./clear_chaos.sh"