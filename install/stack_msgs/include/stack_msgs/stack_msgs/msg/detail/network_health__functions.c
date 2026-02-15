// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stack_msgs:msg/NetworkHealth.idl
// generated code does not contain a copyright notice
#include "stack_msgs/msg/detail/network_health__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `interface_name`
#include "rosidl_runtime_c/string_functions.h"

bool
stack_msgs__msg__NetworkHealth__init(stack_msgs__msg__NetworkHealth * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    stack_msgs__msg__NetworkHealth__fini(msg);
    return false;
  }
  // interface_name
  if (!rosidl_runtime_c__String__init(&msg->interface_name)) {
    stack_msgs__msg__NetworkHealth__fini(msg);
    return false;
  }
  // rtt_avg
  // rtt_min
  // rtt_max
  // rtt_stddev
  // packet_loss_percent
  // available_bandwidth
  // utilized_bandwidth
  // quality_score
  // is_stable
  return true;
}

void
stack_msgs__msg__NetworkHealth__fini(stack_msgs__msg__NetworkHealth * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // interface_name
  rosidl_runtime_c__String__fini(&msg->interface_name);
  // rtt_avg
  // rtt_min
  // rtt_max
  // rtt_stddev
  // packet_loss_percent
  // available_bandwidth
  // utilized_bandwidth
  // quality_score
  // is_stable
}

bool
stack_msgs__msg__NetworkHealth__are_equal(const stack_msgs__msg__NetworkHealth * lhs, const stack_msgs__msg__NetworkHealth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // interface_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->interface_name), &(rhs->interface_name)))
  {
    return false;
  }
  // rtt_avg
  if (lhs->rtt_avg != rhs->rtt_avg) {
    return false;
  }
  // rtt_min
  if (lhs->rtt_min != rhs->rtt_min) {
    return false;
  }
  // rtt_max
  if (lhs->rtt_max != rhs->rtt_max) {
    return false;
  }
  // rtt_stddev
  if (lhs->rtt_stddev != rhs->rtt_stddev) {
    return false;
  }
  // packet_loss_percent
  if (lhs->packet_loss_percent != rhs->packet_loss_percent) {
    return false;
  }
  // available_bandwidth
  if (lhs->available_bandwidth != rhs->available_bandwidth) {
    return false;
  }
  // utilized_bandwidth
  if (lhs->utilized_bandwidth != rhs->utilized_bandwidth) {
    return false;
  }
  // quality_score
  if (lhs->quality_score != rhs->quality_score) {
    return false;
  }
  // is_stable
  if (lhs->is_stable != rhs->is_stable) {
    return false;
  }
  return true;
}

bool
stack_msgs__msg__NetworkHealth__copy(
  const stack_msgs__msg__NetworkHealth * input,
  stack_msgs__msg__NetworkHealth * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // interface_name
  if (!rosidl_runtime_c__String__copy(
      &(input->interface_name), &(output->interface_name)))
  {
    return false;
  }
  // rtt_avg
  output->rtt_avg = input->rtt_avg;
  // rtt_min
  output->rtt_min = input->rtt_min;
  // rtt_max
  output->rtt_max = input->rtt_max;
  // rtt_stddev
  output->rtt_stddev = input->rtt_stddev;
  // packet_loss_percent
  output->packet_loss_percent = input->packet_loss_percent;
  // available_bandwidth
  output->available_bandwidth = input->available_bandwidth;
  // utilized_bandwidth
  output->utilized_bandwidth = input->utilized_bandwidth;
  // quality_score
  output->quality_score = input->quality_score;
  // is_stable
  output->is_stable = input->is_stable;
  return true;
}

stack_msgs__msg__NetworkHealth *
stack_msgs__msg__NetworkHealth__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stack_msgs__msg__NetworkHealth * msg = (stack_msgs__msg__NetworkHealth *)allocator.allocate(sizeof(stack_msgs__msg__NetworkHealth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stack_msgs__msg__NetworkHealth));
  bool success = stack_msgs__msg__NetworkHealth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stack_msgs__msg__NetworkHealth__destroy(stack_msgs__msg__NetworkHealth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stack_msgs__msg__NetworkHealth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stack_msgs__msg__NetworkHealth__Sequence__init(stack_msgs__msg__NetworkHealth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stack_msgs__msg__NetworkHealth * data = NULL;

  if (size) {
    data = (stack_msgs__msg__NetworkHealth *)allocator.zero_allocate(size, sizeof(stack_msgs__msg__NetworkHealth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stack_msgs__msg__NetworkHealth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stack_msgs__msg__NetworkHealth__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
stack_msgs__msg__NetworkHealth__Sequence__fini(stack_msgs__msg__NetworkHealth__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      stack_msgs__msg__NetworkHealth__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

stack_msgs__msg__NetworkHealth__Sequence *
stack_msgs__msg__NetworkHealth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stack_msgs__msg__NetworkHealth__Sequence * array = (stack_msgs__msg__NetworkHealth__Sequence *)allocator.allocate(sizeof(stack_msgs__msg__NetworkHealth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stack_msgs__msg__NetworkHealth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stack_msgs__msg__NetworkHealth__Sequence__destroy(stack_msgs__msg__NetworkHealth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stack_msgs__msg__NetworkHealth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stack_msgs__msg__NetworkHealth__Sequence__are_equal(const stack_msgs__msg__NetworkHealth__Sequence * lhs, const stack_msgs__msg__NetworkHealth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stack_msgs__msg__NetworkHealth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stack_msgs__msg__NetworkHealth__Sequence__copy(
  const stack_msgs__msg__NetworkHealth__Sequence * input,
  stack_msgs__msg__NetworkHealth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stack_msgs__msg__NetworkHealth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stack_msgs__msg__NetworkHealth * data =
      (stack_msgs__msg__NetworkHealth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stack_msgs__msg__NetworkHealth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stack_msgs__msg__NetworkHealth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stack_msgs__msg__NetworkHealth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
