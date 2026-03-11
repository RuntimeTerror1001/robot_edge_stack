#!/bin/bash

# Inject network latency between laptop and jetson
# Run on: Laptop
# Effect: Adds fixed delay to all packets

set -e

INTERFACE=${1:-enp8s0}
DELAY=${2:-100ms}

echo "Adding ${DELAY} latency to ${INTERFACE}"
echo "This simulates a slow/distant network connection."

# Remove any existing rules
sudo tc qdisc del dev ${INTERFACE} root 2>/dev/null || true

# Add delay
sudo tc qdisc add dev ${INTERFACE} root netem delay ${DELAY}

echo "Latency Injected"
echo ""
echo "Current tc rules:"
tc qdisc show dev ${INTERFACE}
echo ""
echo "Expected Behavior:"
echo "   - Network monitor will show RTT ~${DELAY}"
echo "   - Bandwidth manager may trigger DEGRADED if quality_score drops"
echo "   - Perception continues runnning (latency doesn't affect bandwidth)"
echo ""
echo "To remove: ./clear_chaos.sh"