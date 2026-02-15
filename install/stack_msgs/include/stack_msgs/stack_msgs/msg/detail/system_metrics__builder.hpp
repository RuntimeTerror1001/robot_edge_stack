// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__BUILDER_HPP_
#define STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stack_msgs/msg/detail/system_metrics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stack_msgs
{

namespace msg
{

namespace builder
{

class Init_SystemMetrics_system_healthy
{
public:
  explicit Init_SystemMetrics_system_healthy(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  ::stack_msgs::msg::SystemMetrics system_healthy(::stack_msgs::msg::SystemMetrics::_system_healthy_type arg)
  {
    msg_.system_healthy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_power_draw_mw
{
public:
  explicit Init_SystemMetrics_power_draw_mw(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_system_healthy power_draw_mw(::stack_msgs::msg::SystemMetrics::_power_draw_mw_type arg)
  {
    msg_.power_draw_mw = std::move(arg);
    return Init_SystemMetrics_system_healthy(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_is_throttled
{
public:
  explicit Init_SystemMetrics_is_throttled(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_power_draw_mw is_throttled(::stack_msgs::msg::SystemMetrics::_is_throttled_type arg)
  {
    msg_.is_throttled = std::move(arg);
    return Init_SystemMetrics_power_draw_mw(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_ram_percent
{
public:
  explicit Init_SystemMetrics_ram_percent(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_is_throttled ram_percent(::stack_msgs::msg::SystemMetrics::_ram_percent_type arg)
  {
    msg_.ram_percent = std::move(arg);
    return Init_SystemMetrics_is_throttled(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_ram_total_mb
{
public:
  explicit Init_SystemMetrics_ram_total_mb(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_ram_percent ram_total_mb(::stack_msgs::msg::SystemMetrics::_ram_total_mb_type arg)
  {
    msg_.ram_total_mb = std::move(arg);
    return Init_SystemMetrics_ram_percent(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_ram_used_mb
{
public:
  explicit Init_SystemMetrics_ram_used_mb(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_ram_total_mb ram_used_mb(::stack_msgs::msg::SystemMetrics::_ram_used_mb_type arg)
  {
    msg_.ram_used_mb = std::move(arg);
    return Init_SystemMetrics_ram_total_mb(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_gpu_freq_mhz
{
public:
  explicit Init_SystemMetrics_gpu_freq_mhz(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_ram_used_mb gpu_freq_mhz(::stack_msgs::msg::SystemMetrics::_gpu_freq_mhz_type arg)
  {
    msg_.gpu_freq_mhz = std::move(arg);
    return Init_SystemMetrics_ram_used_mb(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_gpu_temp_celsius
{
public:
  explicit Init_SystemMetrics_gpu_temp_celsius(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_gpu_freq_mhz gpu_temp_celsius(::stack_msgs::msg::SystemMetrics::_gpu_temp_celsius_type arg)
  {
    msg_.gpu_temp_celsius = std::move(arg);
    return Init_SystemMetrics_gpu_freq_mhz(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_gpu_percent
{
public:
  explicit Init_SystemMetrics_gpu_percent(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_gpu_temp_celsius gpu_percent(::stack_msgs::msg::SystemMetrics::_gpu_percent_type arg)
  {
    msg_.gpu_percent = std::move(arg);
    return Init_SystemMetrics_gpu_temp_celsius(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_cpu_temp_celsius
{
public:
  explicit Init_SystemMetrics_cpu_temp_celsius(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_gpu_percent cpu_temp_celsius(::stack_msgs::msg::SystemMetrics::_cpu_temp_celsius_type arg)
  {
    msg_.cpu_temp_celsius = std::move(arg);
    return Init_SystemMetrics_gpu_percent(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_cpu_percent
{
public:
  explicit Init_SystemMetrics_cpu_percent(::stack_msgs::msg::SystemMetrics & msg)
  : msg_(msg)
  {}
  Init_SystemMetrics_cpu_temp_celsius cpu_percent(::stack_msgs::msg::SystemMetrics::_cpu_percent_type arg)
  {
    msg_.cpu_percent = std::move(arg);
    return Init_SystemMetrics_cpu_temp_celsius(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

class Init_SystemMetrics_header
{
public:
  Init_SystemMetrics_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SystemMetrics_cpu_percent header(::stack_msgs::msg::SystemMetrics::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SystemMetrics_cpu_percent(msg_);
  }

private:
  ::stack_msgs::msg::SystemMetrics msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stack_msgs::msg::SystemMetrics>()
{
  return stack_msgs::msg::builder::Init_SystemMetrics_header();
}

}  // namespace stack_msgs

#endif  // STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__BUILDER_HPP_
