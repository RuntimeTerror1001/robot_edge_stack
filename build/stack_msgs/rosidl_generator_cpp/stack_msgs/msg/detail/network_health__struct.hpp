// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stack_msgs:msg/NetworkHealth.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__STRUCT_HPP_
#define STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__STRUCT_HPP_

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
# define DEPRECATED__stack_msgs__msg__NetworkHealth __attribute__((deprecated))
#else
# define DEPRECATED__stack_msgs__msg__NetworkHealth __declspec(deprecated)
#endif

namespace stack_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NetworkHealth_
{
  using Type = NetworkHealth_<ContainerAllocator>;

  explicit NetworkHealth_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->interface_name = "";
      this->rtt_avg = 0.0f;
      this->rtt_min = 0.0f;
      this->rtt_max = 0.0f;
      this->rtt_stddev = 0.0f;
      this->packet_loss_percent = 0.0f;
      this->available_bandwidth = 0.0f;
      this->utilized_bandwidth = 0.0f;
      this->quality_score = 0;
      this->is_stable = false;
    }
  }

  explicit NetworkHealth_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    interface_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->interface_name = "";
      this->rtt_avg = 0.0f;
      this->rtt_min = 0.0f;
      this->rtt_max = 0.0f;
      this->rtt_stddev = 0.0f;
      this->packet_loss_percent = 0.0f;
      this->available_bandwidth = 0.0f;
      this->utilized_bandwidth = 0.0f;
      this->quality_score = 0;
      this->is_stable = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _interface_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _interface_name_type interface_name;
  using _rtt_avg_type =
    float;
  _rtt_avg_type rtt_avg;
  using _rtt_min_type =
    float;
  _rtt_min_type rtt_min;
  using _rtt_max_type =
    float;
  _rtt_max_type rtt_max;
  using _rtt_stddev_type =
    float;
  _rtt_stddev_type rtt_stddev;
  using _packet_loss_percent_type =
    float;
  _packet_loss_percent_type packet_loss_percent;
  using _available_bandwidth_type =
    float;
  _available_bandwidth_type available_bandwidth;
  using _utilized_bandwidth_type =
    float;
  _utilized_bandwidth_type utilized_bandwidth;
  using _quality_score_type =
    uint8_t;
  _quality_score_type quality_score;
  using _is_stable_type =
    bool;
  _is_stable_type is_stable;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__interface_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->interface_name = _arg;
    return *this;
  }
  Type & set__rtt_avg(
    const float & _arg)
  {
    this->rtt_avg = _arg;
    return *this;
  }
  Type & set__rtt_min(
    const float & _arg)
  {
    this->rtt_min = _arg;
    return *this;
  }
  Type & set__rtt_max(
    const float & _arg)
  {
    this->rtt_max = _arg;
    return *this;
  }
  Type & set__rtt_stddev(
    const float & _arg)
  {
    this->rtt_stddev = _arg;
    return *this;
  }
  Type & set__packet_loss_percent(
    const float & _arg)
  {
    this->packet_loss_percent = _arg;
    return *this;
  }
  Type & set__available_bandwidth(
    const float & _arg)
  {
    this->available_bandwidth = _arg;
    return *this;
  }
  Type & set__utilized_bandwidth(
    const float & _arg)
  {
    this->utilized_bandwidth = _arg;
    return *this;
  }
  Type & set__quality_score(
    const uint8_t & _arg)
  {
    this->quality_score = _arg;
    return *this;
  }
  Type & set__is_stable(
    const bool & _arg)
  {
    this->is_stable = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stack_msgs::msg::NetworkHealth_<ContainerAllocator> *;
  using ConstRawPtr =
    const stack_msgs::msg::NetworkHealth_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stack_msgs::msg::NetworkHealth_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stack_msgs::msg::NetworkHealth_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stack_msgs__msg__NetworkHealth
    std::shared_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stack_msgs__msg__NetworkHealth
    std::shared_ptr<stack_msgs::msg::NetworkHealth_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NetworkHealth_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->interface_name != other.interface_name) {
      return false;
    }
    if (this->rtt_avg != other.rtt_avg) {
      return false;
    }
    if (this->rtt_min != other.rtt_min) {
      return false;
    }
    if (this->rtt_max != other.rtt_max) {
      return false;
    }
    if (this->rtt_stddev != other.rtt_stddev) {
      return false;
    }
    if (this->packet_loss_percent != other.packet_loss_percent) {
      return false;
    }
    if (this->available_bandwidth != other.available_bandwidth) {
      return false;
    }
    if (this->utilized_bandwidth != other.utilized_bandwidth) {
      return false;
    }
    if (this->quality_score != other.quality_score) {
      return false;
    }
    if (this->is_stable != other.is_stable) {
      return false;
    }
    return true;
  }
  bool operator!=(const NetworkHealth_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NetworkHealth_

// alias to use template instance with default allocator
using NetworkHealth =
  stack_msgs::msg::NetworkHealth_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stack_msgs

#endif  // STACK_MSGS__MSG__DETAIL__NETWORK_HEALTH__STRUCT_HPP_
