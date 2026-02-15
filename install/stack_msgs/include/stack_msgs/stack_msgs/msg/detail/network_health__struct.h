// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stack_msgs:msg/NetworkHealth.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__STRUCT_H_
#define STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__STRUCT_H_

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
// Member 'interface_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/NetworkHealth in the package stack_msgs.
/**
  * Network health metrics for bandwidth management
 */
typedef struct stack_msgs__msg__NetworkHealth
{
  std_msgs__msg__Header header;
  /// Network interface being monitored
  rosidl_runtime_c__String interface_name;
  /// Latency metrics (milliseconds)
  float rtt_avg;
  float rtt_min;
  float rtt_max;
  float rtt_stddev;
  /// Packet loss (percentage 0-100)
  float packet_loss_percent;
  /// Bandwidth estimates (Mbps)
  float available_bandwidth;
  float utilized_bandwidth;
  /// Connection quality score (0-100, 100 = perfect)
  uint8_t quality_score;
  /// Is network stable enough for high-bandwidth operations?
  bool is_stable;
} stack_msgs__msg__NetworkHealth;

// Struct for a sequence of stack_msgs__msg__NetworkHealth.
typedef struct stack_msgs__msg__NetworkHealth__Sequence
{
  stack_msgs__msg__NetworkHealth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stack_msgs__msg__NetworkHealth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__STRUCT_H_
