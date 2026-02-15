// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__STRUCT_HPP_
#define STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__stack_msgs__msg__SystemMetrics __attribute__((deprecated))
#else
# define DEPRECATED__stack_msgs__msg__SystemMetrics __declspec(deprecated)
#endif

namespace stack_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SystemMetrics_
{
  using Type = SystemMetrics_<ContainerAllocator>;

  explicit SystemMetrics_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cpu_percent = 0.0f;
      this->cpu_temp_celsius = 0.0f;
      this->gpu_percent = 0.0f;
      this->gpu_temp_celsius = 0.0f;
      this->gpu_freq_mhz = 0ul;
      this->ram_used_mb = 0ul;
      this->ram_total_mb = 0ul;
      this->ram_percent = 0.0f;
      this->is_throttled = false;
      this->power_draw_mw = 0ul;
      this->system_healthy = false;
    }
  }

  explicit SystemMetrics_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cpu_percent = 0.0f;
      this->cpu_temp_celsius = 0.0f;
      this->gpu_percent = 0.0f;
      this->gpu_temp_celsius = 0.0f;
      this->gpu_freq_mhz = 0ul;
      this->ram_used_mb = 0ul;
      this->ram_total_mb = 0ul;
      this->ram_percent = 0.0f;
      this->is_throttled = false;
      this->power_draw_mw = 0ul;
      this->system_healthy = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _cpu_percent_type =
    float;
  _cpu_percent_type cpu_percent;
  using _cpu_temp_celsius_type =
    float;
  _cpu_temp_celsius_type cpu_temp_celsius;
  using _gpu_percent_type =
    float;
  _gpu_percent_type gpu_percent;
  using _gpu_temp_celsius_type =
    float;
  _gpu_temp_celsius_type gpu_temp_celsius;
  using _gpu_freq_mhz_type =
    uint32_t;
  _gpu_freq_mhz_type gpu_freq_mhz;
  using _ram_used_mb_type =
    uint32_t;
  _ram_used_mb_type ram_used_mb;
  using _ram_total_mb_type =
    uint32_t;
  _ram_total_mb_type ram_total_mb;
  using _ram_percent_type =
    float;
  _ram_percent_type ram_percent;
  using _is_throttled_type =
    bool;
  _is_throttled_type is_throttled;
  using _power_draw_mw_type =
    uint32_t;
  _power_draw_mw_type power_draw_mw;
  using _system_healthy_type =
    bool;
  _system_healthy_type system_healthy;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__cpu_percent(
    const float & _arg)
  {
    this->cpu_percent = _arg;
    return *this;
  }
  Type & set__cpu_temp_celsius(
    const float & _arg)
  {
    this->cpu_temp_celsius = _arg;
    return *this;
  }
  Type & set__gpu_percent(
    const float & _arg)
  {
    this->gpu_percent = _arg;
    return *this;
  }
  Type & set__gpu_temp_celsius(
    const float & _arg)
  {
    this->gpu_temp_celsius = _arg;
    return *this;
  }
  Type & set__gpu_freq_mhz(
    const uint32_t & _arg)
  {
    this->gpu_freq_mhz = _arg;
    return *this;
  }
  Type & set__ram_used_mb(
    const uint32_t & _arg)
  {
    this->ram_used_mb = _arg;
    return *this;
  }
  Type & set__ram_total_mb(
    const uint32_t & _arg)
  {
    this->ram_total_mb = _arg;
    return *this;
  }
  Type & set__ram_percent(
    const float & _arg)
  {
    this->ram_percent = _arg;
    return *this;
  }
  Type & set__is_throttled(
    const bool & _arg)
  {
    this->is_throttled = _arg;
    return *this;
  }
  Type & set__power_draw_mw(
    const uint32_t & _arg)
  {
    this->power_draw_mw = _arg;
    return *this;
  }
  Type & set__system_healthy(
    const bool & _arg)
  {
    this->system_healthy = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stack_msgs::msg::SystemMetrics_<ContainerAllocator> *;
  using ConstRawPtr =
    const stack_msgs::msg::SystemMetrics_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stack_msgs::msg::SystemMetrics_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stack_msgs::msg::SystemMetrics_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stack_msgs__msg__SystemMetrics
    std::shared_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stack_msgs__msg__SystemMetrics
    std::shared_ptr<stack_msgs::msg::SystemMetrics_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SystemMetrics_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->cpu_percent != other.cpu_percent) {
      return false;
    }
    if (this->cpu_temp_celsius != other.cpu_temp_celsius) {
      return false;
    }
    if (this->gpu_percent != other.gpu_percent) {
      return false;
    }
    if (this->gpu_temp_celsius != other.gpu_temp_celsius) {
      return false;
    }
    if (this->gpu_freq_mhz != other.gpu_freq_mhz) {
      return false;
    }
    if (this->ram_used_mb != other.ram_used_mb) {
      return false;
    }
    if (this->ram_total_mb != other.ram_total_mb) {
      return false;
    }
    if (this->ram_percent != other.ram_percent) {
      return false;
    }
    if (this->is_throttled != other.is_throttled) {
      return false;
    }
    if (this->power_draw_mw != other.power_draw_mw) {
      return false;
    }
    if (this->system_healthy != other.system_healthy) {
      return false;
    }
    return true;
  }
  bool operator!=(const SystemMetrics_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SystemMetrics_

// alias to use template instance with default allocator
using SystemMetrics =
  stack_msgs::msg::SystemMetrics_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stack_msgs

#endif  // STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__STRUCT_HPP_
