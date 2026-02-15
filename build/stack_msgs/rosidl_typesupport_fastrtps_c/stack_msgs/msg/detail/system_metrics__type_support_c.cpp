// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice
#include "stack_msgs/msg/detail/system_metrics__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "stack_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "stack_msgs/msg/detail/system_metrics__struct.h"
#include "stack_msgs/msg/detail/system_metrics__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_stack_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_stack_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_stack_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _SystemMetrics__ros_msg_type = stack_msgs__msg__SystemMetrics;

static bool _SystemMetrics__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SystemMetrics__ros_msg_type * ros_message = static_cast<const _SystemMetrics__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: cpu_percent
  {
    cdr << ros_message->cpu_percent;
  }

  // Field name: cpu_temp_celsius
  {
    cdr << ros_message->cpu_temp_celsius;
  }

  // Field name: gpu_percent
  {
    cdr << ros_message->gpu_percent;
  }

  // Field name: gpu_temp_celsius
  {
    cdr << ros_message->gpu_temp_celsius;
  }

  // Field name: gpu_freq_mhz
  {
    cdr << ros_message->gpu_freq_mhz;
  }

  // Field name: ram_used_mb
  {
    cdr << ros_message->ram_used_mb;
  }

  // Field name: ram_total_mb
  {
    cdr << ros_message->ram_total_mb;
  }

  // Field name: ram_percent
  {
    cdr << ros_message->ram_percent;
  }

  // Field name: is_throttled
  {
    cdr << (ros_message->is_throttled ? true : false);
  }

  // Field name: power_draw_mw
  {
    cdr << ros_message->power_draw_mw;
  }

  // Field name: system_healthy
  {
    cdr << (ros_message->system_healthy ? true : false);
  }

  return true;
}

static bool _SystemMetrics__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SystemMetrics__ros_msg_type * ros_message = static_cast<_SystemMetrics__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: cpu_percent
  {
    cdr >> ros_message->cpu_percent;
  }

  // Field name: cpu_temp_celsius
  {
    cdr >> ros_message->cpu_temp_celsius;
  }

  // Field name: gpu_percent
  {
    cdr >> ros_message->gpu_percent;
  }

  // Field name: gpu_temp_celsius
  {
    cdr >> ros_message->gpu_temp_celsius;
  }

  // Field name: gpu_freq_mhz
  {
    cdr >> ros_message->gpu_freq_mhz;
  }

  // Field name: ram_used_mb
  {
    cdr >> ros_message->ram_used_mb;
  }

  // Field name: ram_total_mb
  {
    cdr >> ros_message->ram_total_mb;
  }

  // Field name: ram_percent
  {
    cdr >> ros_message->ram_percent;
  }

  // Field name: is_throttled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_throttled = tmp ? true : false;
  }

  // Field name: power_draw_mw
  {
    cdr >> ros_message->power_draw_mw;
  }

  // Field name: system_healthy
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->system_healthy = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stack_msgs
size_t get_serialized_size_stack_msgs__msg__SystemMetrics(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SystemMetrics__ros_msg_type * ros_message = static_cast<const _SystemMetrics__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name cpu_percent
  {
    size_t item_size = sizeof(ros_message->cpu_percent);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name cpu_temp_celsius
  {
    size_t item_size = sizeof(ros_message->cpu_temp_celsius);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gpu_percent
  {
    size_t item_size = sizeof(ros_message->gpu_percent);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gpu_temp_celsius
  {
    size_t item_size = sizeof(ros_message->gpu_temp_celsius);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gpu_freq_mhz
  {
    size_t item_size = sizeof(ros_message->gpu_freq_mhz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ram_used_mb
  {
    size_t item_size = sizeof(ros_message->ram_used_mb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ram_total_mb
  {
    size_t item_size = sizeof(ros_message->ram_total_mb);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ram_percent
  {
    size_t item_size = sizeof(ros_message->ram_percent);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_throttled
  {
    size_t item_size = sizeof(ros_message->is_throttled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name power_draw_mw
  {
    size_t item_size = sizeof(ros_message->power_draw_mw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name system_healthy
  {
    size_t item_size = sizeof(ros_message->system_healthy);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SystemMetrics__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_stack_msgs__msg__SystemMetrics(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_stack_msgs
size_t max_serialized_size_stack_msgs__msg__SystemMetrics(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: cpu_percent
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: cpu_temp_celsius
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gpu_percent
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gpu_temp_celsius
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gpu_freq_mhz
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ram_used_mb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ram_total_mb
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ram_percent
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: is_throttled
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: power_draw_mw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: system_healthy
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = stack_msgs__msg__SystemMetrics;
    is_plain =
      (
      offsetof(DataType, system_healthy) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SystemMetrics__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_stack_msgs__msg__SystemMetrics(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SystemMetrics = {
  "stack_msgs::msg",
  "SystemMetrics",
  _SystemMetrics__cdr_serialize,
  _SystemMetrics__cdr_deserialize,
  _SystemMetrics__get_serialized_size,
  _SystemMetrics__max_serialized_size
};

static rosidl_message_type_support_t _SystemMetrics__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SystemMetrics,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, stack_msgs, msg, SystemMetrics)() {
  return &_SystemMetrics__type_support;
}

#if defined(__cplusplus)
}
#endif
