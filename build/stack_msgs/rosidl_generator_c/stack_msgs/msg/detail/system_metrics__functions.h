// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice

#ifndef STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__FUNCTIONS_H_
#define STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "stack_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "stack_msgs/msg/detail/system_metrics__struct.h"

/// Initialize msg/SystemMetrics message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * stack_msgs__msg__SystemMetrics
 * )) before or use
 * stack_msgs__msg__SystemMetrics__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
bool
stack_msgs__msg__SystemMetrics__init(stack_msgs__msg__SystemMetrics * msg);

/// Finalize msg/SystemMetrics message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
void
stack_msgs__msg__SystemMetrics__fini(stack_msgs__msg__SystemMetrics * msg);

/// Create msg/SystemMetrics message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * stack_msgs__msg__SystemMetrics__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
stack_msgs__msg__SystemMetrics *
stack_msgs__msg__SystemMetrics__create();

/// Destroy msg/SystemMetrics message.
/**
 * It calls
 * stack_msgs__msg__SystemMetrics__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
void
stack_msgs__msg__SystemMetrics__destroy(stack_msgs__msg__SystemMetrics * msg);

/// Check for msg/SystemMetrics message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
bool
stack_msgs__msg__SystemMetrics__are_equal(const stack_msgs__msg__SystemMetrics * lhs, const stack_msgs__msg__SystemMetrics * rhs);

/// Copy a msg/SystemMetrics message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
bool
stack_msgs__msg__SystemMetrics__copy(
  const stack_msgs__msg__SystemMetrics * input,
  stack_msgs__msg__SystemMetrics * output);

/// Initialize array of msg/SystemMetrics messages.
/**
 * It allocates the memory for the number of elements and calls
 * stack_msgs__msg__SystemMetrics__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
bool
stack_msgs__msg__SystemMetrics__Sequence__init(stack_msgs__msg__SystemMetrics__Sequence * array, size_t size);

/// Finalize array of msg/SystemMetrics messages.
/**
 * It calls
 * stack_msgs__msg__SystemMetrics__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
void
stack_msgs__msg__SystemMetrics__Sequence__fini(stack_msgs__msg__SystemMetrics__Sequence * array);

/// Create array of msg/SystemMetrics messages.
/**
 * It allocates the memory for the array and calls
 * stack_msgs__msg__SystemMetrics__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
stack_msgs__msg__SystemMetrics__Sequence *
stack_msgs__msg__SystemMetrics__Sequence__create(size_t size);

/// Destroy array of msg/SystemMetrics messages.
/**
 * It calls
 * stack_msgs__msg__SystemMetrics__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
void
stack_msgs__msg__SystemMetrics__Sequence__destroy(stack_msgs__msg__SystemMetrics__Sequence * array);

/// Check for msg/SystemMetrics message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
bool
stack_msgs__msg__SystemMetrics__Sequence__are_equal(const stack_msgs__msg__SystemMetrics__Sequence * lhs, const stack_msgs__msg__SystemMetrics__Sequence * rhs);

/// Copy an array of msg/SystemMetrics messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_stack_msgs
bool
stack_msgs__msg__SystemMetrics__Sequence__copy(
  const stack_msgs__msg__SystemMetrics__Sequence * input,
  stack_msgs__msg__SystemMetrics__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // STACK_MSGS__MSG__DETAIL__SYSTEM_METRICS__FUNCTIONS_H_
