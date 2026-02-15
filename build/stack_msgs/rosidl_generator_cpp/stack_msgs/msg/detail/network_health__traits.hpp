// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stack_msgs:msg/NetworkHealth.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__TRAITS_HPP_
#define STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stack_msgs/msg/detail/network_health__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace stack_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NetworkHealth & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: interface_name
  {
    out << "interface_name: ";
    rosidl_generator_traits::value_to_yaml(msg.interface_name, out);
    out << ", ";
  }

  // member: rtt_avg
  {
    out << "rtt_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_avg, out);
    out << ", ";
  }

  // member: rtt_min
  {
    out << "rtt_min: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_min, out);
    out << ", ";
  }

  // member: rtt_max
  {
    out << "rtt_max: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_max, out);
    out << ", ";
  }

  // member: rtt_stddev
  {
    out << "rtt_stddev: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_stddev, out);
    out << ", ";
  }

  // member: packet_loss_percent
  {
    out << "packet_loss_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_loss_percent, out);
    out << ", ";
  }

  // member: available_bandwidth
  {
    out << "available_bandwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.available_bandwidth, out);
    out << ", ";
  }

  // member: utilized_bandwidth
  {
    out << "utilized_bandwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.utilized_bandwidth, out);
    out << ", ";
  }

  // member: quality_score
  {
    out << "quality_score: ";
    rosidl_generator_traits::value_to_yaml(msg.quality_score, out);
    out << ", ";
  }

  // member: is_stable
  {
    out << "is_stable: ";
    rosidl_generator_traits::value_to_yaml(msg.is_stable, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NetworkHealth & msg,
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

  // member: interface_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "interface_name: ";
    rosidl_generator_traits::value_to_yaml(msg.interface_name, out);
    out << "\n";
  }

  // member: rtt_avg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtt_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_avg, out);
    out << "\n";
  }

  // member: rtt_min
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtt_min: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_min, out);
    out << "\n";
  }

  // member: rtt_max
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtt_max: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_max, out);
    out << "\n";
  }

  // member: rtt_stddev
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rtt_stddev: ";
    rosidl_generator_traits::value_to_yaml(msg.rtt_stddev, out);
    out << "\n";
  }

  // member: packet_loss_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "packet_loss_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.packet_loss_percent, out);
    out << "\n";
  }

  // member: available_bandwidth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "available_bandwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.available_bandwidth, out);
    out << "\n";
  }

  // member: utilized_bandwidth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "utilized_bandwidth: ";
    rosidl_generator_traits::value_to_yaml(msg.utilized_bandwidth, out);
    out << "\n";
  }

  // member: quality_score
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quality_score: ";
    rosidl_generator_traits::value_to_yaml(msg.quality_score, out);
    out << "\n";
  }

  // member: is_stable
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_stable: ";
    rosidl_generator_traits::value_to_yaml(msg.is_stable, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NetworkHealth & msg, bool use_flow_style = false)
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
  const stack_msgs::msg::NetworkHealth & msg,
  std::ostream & out, size_t indentation = 0)
{
  stack_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stack_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const stack_msgs::msg::NetworkHealth & msg)
{
  return stack_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stack_msgs::msg::NetworkHealth>()
{
  return "stack_msgs::msg::NetworkHealth";
}

template<>
inline const char * name<stack_msgs::msg::NetworkHealth>()
{
  return "stack_msgs/msg/NetworkHealth";
}

template<>
struct has_fixed_size<stack_msgs::msg::NetworkHealth>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<stack_msgs::msg::NetworkHealth>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<stack_msgs::msg::NetworkHealth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__TRAITS_HPP_
