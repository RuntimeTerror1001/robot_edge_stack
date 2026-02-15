// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__STRUCT_H_
#define STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/SystemMetrics in the package stack_msgs.
/**
  * System resource metrics for Jetson Orin Nano
 */
typedef struct stack_msgs__msg__SystemMetrics
{
  std_msgs__msg__Header header;
  /// CPU metrics
  /// Overall CPU usage (0-100)
  float cpu_percent;
  /// CPU temperature
  float cpu_temp_celsius;
  /// GPU metrics (Jetson-specific)
  /// GPU usage (0-100)
  float gpu_percent;
  /// GPU temperature
  float gpu_temp_celsius;
  /// Current GPU frequency
  uint32_t gpu_freq_mhz;
  /// Memory metrics (MB)
  uint32_t ram_used_mb;
  uint32_t ram_total_mb;
  /// 0-100
  float ram_percent;
  /// Thermal throttling status
  bool is_throttled;
  /// Power metrics (milliwatts)
  uint32_t power_draw_mw;
  /// System health flag
  /// False if any critical threshold exceeded
  bool system_healthy;
} stack_msgs__msg__SystemMetrics;

// Struct for a sequence of stack_msgs__msg__SystemMetrics.
typedef struct stack_msgs__msg__SystemMetrics__Sequence
{
  stack_msgs__msg__SystemMetrics * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stack_msgs__msg__SystemMetrics__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__STRUCT_H_
