// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stack_msgs:msg/NetworkHealth.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__BUILDER_HPP_
#define STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stack_msgs/msg/detail/network_health__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stack_msgs
{

namespace msg
{

namespace builder
{

class Init_NetworkHealth_is_stable
{
public:
  explicit Init_NetworkHealth_is_stable(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  ::stack_msgs::msg::NetworkHealth is_stable(::stack_msgs::msg::NetworkHealth::_is_stable_type arg)
  {
    msg_.is_stable = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_quality_score
{
public:
  explicit Init_NetworkHealth_quality_score(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_is_stable quality_score(::stack_msgs::msg::NetworkHealth::_quality_score_type arg)
  {
    msg_.quality_score = std::move(arg);
    return Init_NetworkHealth_is_stable(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_utilized_bandwidth
{
public:
  explicit Init_NetworkHealth_utilized_bandwidth(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_quality_score utilized_bandwidth(::stack_msgs::msg::NetworkHealth::_utilized_bandwidth_type arg)
  {
    msg_.utilized_bandwidth = std::move(arg);
    return Init_NetworkHealth_quality_score(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_available_bandwidth
{
public:
  explicit Init_NetworkHealth_available_bandwidth(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_utilized_bandwidth available_bandwidth(::stack_msgs::msg::NetworkHealth::_available_bandwidth_type arg)
  {
    msg_.available_bandwidth = std::move(arg);
    return Init_NetworkHealth_utilized_bandwidth(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_packet_loss_percent
{
public:
  explicit Init_NetworkHealth_packet_loss_percent(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_available_bandwidth packet_loss_percent(::stack_msgs::msg::NetworkHealth::_packet_loss_percent_type arg)
  {
    msg_.packet_loss_percent = std::move(arg);
    return Init_NetworkHealth_available_bandwidth(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_rtt_stddev
{
public:
  explicit Init_NetworkHealth_rtt_stddev(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_packet_loss_percent rtt_stddev(::stack_msgs::msg::NetworkHealth::_rtt_stddev_type arg)
  {
    msg_.rtt_stddev = std::move(arg);
    return Init_NetworkHealth_packet_loss_percent(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_rtt_max
{
public:
  explicit Init_NetworkHealth_rtt_max(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_rtt_stddev rtt_max(::stack_msgs::msg::NetworkHealth::_rtt_max_type arg)
  {
    msg_.rtt_max = std::move(arg);
    return Init_NetworkHealth_rtt_stddev(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_rtt_min
{
public:
  explicit Init_NetworkHealth_rtt_min(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_rtt_max rtt_min(::stack_msgs::msg::NetworkHealth::_rtt_min_type arg)
  {
    msg_.rtt_min = std::move(arg);
    return Init_NetworkHealth_rtt_max(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_rtt_avg
{
public:
  explicit Init_NetworkHealth_rtt_avg(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_rtt_min rtt_avg(::stack_msgs::msg::NetworkHealth::_rtt_avg_type arg)
  {
    msg_.rtt_avg = std::move(arg);
    return Init_NetworkHealth_rtt_min(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_interface_name
{
public:
  explicit Init_NetworkHealth_interface_name(::stack_msgs::msg::NetworkHealth & msg)
  : msg_(msg)
  {}
  Init_NetworkHealth_rtt_avg interface_name(::stack_msgs::msg::NetworkHealth::_interface_name_type arg)
  {
    msg_.interface_name = std::move(arg);
    return Init_NetworkHealth_rtt_avg(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

class Init_NetworkHealth_header
{
public:
  Init_NetworkHealth_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NetworkHealth_interface_name header(::stack_msgs::msg::NetworkHealth::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NetworkHealth_interface_name(msg_);
  }

private:
  ::stack_msgs::msg::NetworkHealth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stack_msgs::msg::NetworkHealth>()
{
  return stack_msgs::msg::builder::Init_NetworkHealth_header();
}

}  // namespace stack_msgs

#endif  // STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__BUILDER_HPP_
