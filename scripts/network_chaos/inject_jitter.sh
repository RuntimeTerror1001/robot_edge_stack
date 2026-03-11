#!/bin/bash

# Inject network jitter (variable latency) between laptop and Jetson
# Run on: Laptop
# Effect: Adds random variance to packet timing

set -e

INTERFACE=${1:-enp8s0}
BASE_DELAY=${2:-50ms}
JITTER=${3:-25ms}

echo "Adding jitter to ${INTERFACE}: ${BASE_DELAY} +- ${JITTER}"
echo "This simulates congested/unstable network."

# Remove any existing rules
sudo tc qdisc del dev ${INTERFACE} root 2>/dev/null || true

# Add jitter (delay with random variance)
sudo tc qdisc add dev ${INTERFACE} root netem delay ${BASE_DELAY} ${JITTER}

echo "Jitter injected"
echo ""
echo "Current tc rules:"
tc qdisc show dev ${INTERFACE}
echo ""
echo "Expected behavior:"
echo "   - Network monitor will show variable RTT (min/max/stddev)"
echo "   - is_stable may toggle False if variance is high"
echo "   - May trigger DEGRADED mode if quality score drops"
echo ""
echo "To remove: ./clear_chaos.sh"