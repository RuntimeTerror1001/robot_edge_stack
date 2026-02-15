// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from stack_msgs:msg/NetworkHealth.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "stack_msgs/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "stack_msgs/msg/detail/network_health__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace stack_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stack_msgs
cdr_serialize(
  const stack_msgs::msg::NetworkHealth & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stack_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  stack_msgs::msg::NetworkHealth & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stack_msgs
get_serialized_size(
  const stack_msgs::msg::NetworkHealth & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stack_msgs
max_serialized_size_NetworkHealth(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace stack_msgs

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stack_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, stack_msgs, msg, NetworkHealth)();

#ifdef __cplusplus
}
#endif

#endif  // STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
