// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice
#include "stack_msgs/msg/detail/system_metrics__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
stack_msgs__msg__SystemMetrics__init(stack_msgs__msg__SystemMetrics * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    stack_msgs__msg__SystemMetrics__fini(msg);
    return false;
  }
  // cpu_percent
  // cpu_temp_celsius
  // gpu_percent
  // gpu_temp_celsius
  // gpu_freq_mhz
  // ram_used_mb
  // ram_total_mb
  // ram_percent
  // is_throttled
  // power_draw_mw
  // system_healthy
  return true;
}

void
stack_msgs__msg__SystemMetrics__fini(stack_msgs__msg__SystemMetrics * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // cpu_percent
  // cpu_temp_celsius
  // gpu_percent
  // gpu_temp_celsius
  // gpu_freq_mhz
  // ram_used_mb
  // ram_total_mb
  // ram_percent
  // is_throttled
  // power_draw_mw
  // system_healthy
}

bool
stack_msgs__msg__SystemMetrics__are_equal(const stack_msgs__msg__SystemMetrics * lhs, const stack_msgs__msg__SystemMetrics * rhs)
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
  // cpu_percent
  if (lhs->cpu_percent != rhs->cpu_percent) {
    return false;
  }
  // cpu_temp_celsius
  if (lhs->cpu_temp_celsius != rhs->cpu_temp_celsius) {
    return false;
  }
  // gpu_percent
  if (lhs->gpu_percent != rhs->gpu_percent) {
    return false;
  }
  // gpu_temp_celsius
  if (lhs->gpu_temp_celsius != rhs->gpu_temp_celsius) {
    return false;
  }
  // gpu_freq_mhz
  if (lhs->gpu_freq_mhz != rhs->gpu_freq_mhz) {
    return false;
  }
  // ram_used_mb
  if (lhs->ram_used_mb != rhs->ram_used_mb) {
    return false;
  }
  // ram_total_mb
  if (lhs->ram_total_mb != rhs->ram_total_mb) {
    return false;
  }
  // ram_percent
  if (lhs->ram_percent != rhs->ram_percent) {
    return false;
  }
  // is_throttled
  if (lhs->is_throttled != rhs->is_throttled) {
    return false;
  }
  // power_draw_mw
  if (lhs->power_draw_mw != rhs->power_draw_mw) {
    return false;
  }
  // system_healthy
  if (lhs->system_healthy != rhs->system_healthy) {
    return false;
  }
  return true;
}

bool
stack_msgs__msg__SystemMetrics__copy(
  const stack_msgs__msg__SystemMetrics * input,
  stack_msgs__msg__SystemMetrics * output)
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
  // cpu_percent
  output->cpu_percent = input->cpu_percent;
  // cpu_temp_celsius
  output->cpu_temp_celsius = input->cpu_temp_celsius;
  // gpu_percent
  output->gpu_percent = input->gpu_percent;
  // gpu_temp_celsius
  output->gpu_temp_celsius = input->gpu_temp_celsius;
  // gpu_freq_mhz
  output->gpu_freq_mhz = input->gpu_freq_mhz;
  // ram_used_mb
  output->ram_used_mb = input->ram_used_mb;
  // ram_total_mb
  output->ram_total_mb = input->ram_total_mb;
  // ram_percent
  output->ram_percent = input->ram_percent;
  // is_throttled
  output->is_throttled = input->is_throttled;
  // power_draw_mw
  output->power_draw_mw = input->power_draw_mw;
  // system_healthy
  output->system_healthy = input->system_healthy;
  return true;
}

stack_msgs__msg__SystemMetrics *
stack_msgs__msg__SystemMetrics__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stack_msgs__msg__SystemMetrics * msg = (stack_msgs__msg__SystemMetrics *)allocator.allocate(sizeof(stack_msgs__msg__SystemMetrics), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stack_msgs__msg__SystemMetrics));
  bool success = stack_msgs__msg__SystemMetrics__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stack_msgs__msg__SystemMetrics__destroy(stack_msgs__msg__SystemMetrics * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stack_msgs__msg__SystemMetrics__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stack_msgs__msg__SystemMetrics__Sequence__init(stack_msgs__msg__SystemMetrics__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stack_msgs__msg__SystemMetrics * data = NULL;

  if (size) {
    data = (stack_msgs__msg__SystemMetrics *)allocator.zero_allocate(size, sizeof(stack_msgs__msg__SystemMetrics), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stack_msgs__msg__SystemMetrics__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stack_msgs__msg__SystemMetrics__fini(&data[i - 1]);
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
stack_msgs__msg__SystemMetrics__Sequence__fini(stack_msgs__msg__SystemMetrics__Sequence * array)
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
      stack_msgs__msg__SystemMetrics__fini(&array->data[i]);
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

stack_msgs__msg__SystemMetrics__Sequence *
stack_msgs__msg__SystemMetrics__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stack_msgs__msg__SystemMetrics__Sequence * array = (stack_msgs__msg__SystemMetrics__Sequence *)allocator.allocate(sizeof(stack_msgs__msg__SystemMetrics__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stack_msgs__msg__SystemMetrics__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stack_msgs__msg__SystemMetrics__Sequence__destroy(stack_msgs__msg__SystemMetrics__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stack_msgs__msg__SystemMetrics__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stack_msgs__msg__SystemMetrics__Sequence__are_equal(const stack_msgs__msg__SystemMetrics__Sequence * lhs, const stack_msgs__msg__SystemMetrics__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stack_msgs__msg__SystemMetrics__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stack_msgs__msg__SystemMetrics__Sequence__copy(
  const stack_msgs__msg__SystemMetrics__Sequence * input,
  stack_msgs__msg__SystemMetrics__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stack_msgs__msg__SystemMetrics);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stack_msgs__msg__SystemMetrics * data =
      (stack_msgs__msg__SystemMetrics *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stack_msgs__msg__SystemMetrics__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stack_msgs__msg__SystemMetrics__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stack_msgs__msg__SystemMetrics__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
