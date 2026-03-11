#!/bin/bash

# Inject packet loss between laptop and Jetson
# Run on: Laptop
# Effect: Randomly drops packets at specified percentage

set -e

INTERFACE=${1:-enp8s0}
LOSS=${2:-5%}

echo "Adding ${LOSS} packet loss to ${INTERFACE}"
echo "This simulates an unreliable wireless connection."

# Remove any existing rules
sudo tc qdisc del dev ${INTERFACE} root 2>/dev/null || true

# Add packet loss
sudo tc qdisc add dev ${INTERFACE} root netem loss ${LOSS}

echo "Packet loss injected"
echo ""
echo "Current tc rules:"
tc qdisc show dev ${INTERFACE}
echo ""
echo "Expected behavior:"
echo "   - Network monitor will show packet_loss_percent ~${LOSS}"
echo "   - At >2% loss: DEGRADED mode (FPS 15 -> 10)"
echo "   - At >5% loss: CRITICAL mode (FPS 10 -> 5)"
echo "   - Camera stream may stutter/freeze briefly"
echo ""
echo "To remove: ./clear_chaos.sh"