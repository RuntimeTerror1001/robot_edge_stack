// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__TRAITS_HPP_
#define STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stack_msgs/msg/detail/system_metrics__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace stack_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SystemMetrics & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: cpu_percent
  {
    out << "cpu_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_percent, out);
    out << ", ";
  }

  // member: cpu_temp_celsius
  {
    out << "cpu_temp_celsius: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_temp_celsius, out);
    out << ", ";
  }

  // member: gpu_percent
  {
    out << "gpu_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_percent, out);
    out << ", ";
  }

  // member: gpu_temp_celsius
  {
    out << "gpu_temp_celsius: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_temp_celsius, out);
    out << ", ";
  }

  // member: gpu_freq_mhz
  {
    out << "gpu_freq_mhz: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_freq_mhz, out);
    out << ", ";
  }

  // member: ram_used_mb
  {
    out << "ram_used_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.ram_used_mb, out);
    out << ", ";
  }

  // member: ram_total_mb
  {
    out << "ram_total_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.ram_total_mb, out);
    out << ", ";
  }

  // member: ram_percent
  {
    out << "ram_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.ram_percent, out);
    out << ", ";
  }

  // member: is_throttled
  {
    out << "is_throttled: ";
    rosidl_generator_traits::value_to_yaml(msg.is_throttled, out);
    out << ", ";
  }

  // member: power_draw_mw
  {
    out << "power_draw_mw: ";
    rosidl_generator_traits::value_to_yaml(msg.power_draw_mw, out);
    out << ", ";
  }

  // member: system_healthy
  {
    out << "system_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.system_healthy, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SystemMetrics & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: cpu_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_percent, out);
    out << "\n";
  }

  // member: cpu_temp_celsius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_temp_celsius: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_temp_celsius, out);
    out << "\n";
  }

  // member: gpu_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gpu_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_percent, out);
    out << "\n";
  }

  // member: gpu_temp_celsius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gpu_temp_celsius: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_temp_celsius, out);
    out << "\n";
  }

  // member: gpu_freq_mhz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gpu_freq_mhz: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_freq_mhz, out);
    out << "\n";
  }

  // member: ram_used_mb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ram_used_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.ram_used_mb, out);
    out << "\n";
  }

  // member: ram_total_mb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ram_total_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.ram_total_mb, out);
    out << "\n";
  }

  // member: ram_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ram_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.ram_percent, out);
    out << "\n";
  }

  // member: is_throttled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_throttled: ";
    rosidl_generator_traits::value_to_yaml(msg.is_throttled, out);
    out << "\n";
  }

  // member: power_draw_mw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "power_draw_mw: ";
    rosidl_generator_traits::value_to_yaml(msg.power_draw_mw, out);
    out << "\n";
  }

  // member: system_healthy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "system_healthy: ";
    rosidl_generator_traits::value_to_yaml(msg.system_healthy, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SystemMetrics & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace stack_msgs

namespace rosidl_generator_traits
{

[[deprecated("use stack_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stack_msgs::msg::SystemMetrics & msg,
  std::ostream & out, size_t indentation = 0)
{
  stack_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stack_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const stack_msgs::msg::SystemMetrics & msg)
{
  return stack_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stack_msgs::msg::SystemMetrics>()
{
  return "stack_msgs::msg::SystemMetrics";
}

template<>
inline const char * name<stack_msgs::msg::SystemMetrics>()
{
  return "stack_msgs/msg/SystemMetrics";
}

template<>
struct has_fixed_size<stack_msgs::msg::SystemMetrics>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<stack_msgs::msg::SystemMetrics>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<stack_msgs::msg::SystemMetrics>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__TRAITS_HPP_
