# System resource metrics for Jetson Orin Nano

std_msgs/Header header

# CPU metrics
float32 cpu_percent          # Overall CPU usage (0-100)
float32 cpu_temp_celsius     # CPU temperature

# GPU metrics (Jetson-specific)
float32 gpu_percent          # GPU usage (0-100)
float32 gpu_temp_celsius     # GPU temperature
uint32 gpu_freq_mhz          # Current GPU frequency

# Memory metrics (MB)
uint32 ram_used_mb
uint32 ram_total_mb
float32 ram_percent          # 0-100

# Thermal throttling status
bool is_throttled

# Power metrics (milliwatts)
uint32 power_draw_mw

# System health flag
bool system_healthy          # False if any critical threshold exceeded
