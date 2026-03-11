#!/bin/bash

# Remove all network chaos rules
# Run on: Laptop

set -e

INTERFACE=${1:-enp8s0}

echo "Removing all tc rules from ${INTERFACE}"

sudo tc qdisc del dev ${INTERFACE} root 2>/dev/null || true

echo "Network clear"
echo ""
echo "Current tc rules:"
tc qdisc show dev ${INTERFACE}
echo ""
echo "Network is back to normal"