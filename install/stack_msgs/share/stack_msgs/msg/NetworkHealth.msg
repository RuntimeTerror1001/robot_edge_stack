# Network health metrics for bandwidth management

std_msgs/Header header

# Network interface being monitored
string interface_name

# Latency metrics (milliseconds)
float32 rtt_avg
float32 rtt_min
float32 rtt_max
float32 rtt_stddev

# Packet loss (percentage 0-100)
float32 packet_loss_percent

# Bandwidth estimates (Mbps)
float32 available_bandwidth
float32 utilized_bandwidth

# Connection quality score (0-100, 100 = perfect)
uint8 quality_score

# Is network stable enough for high-bandwidth operations?
bool is_stable
