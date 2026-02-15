// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from stack_msgs:msg/SystemMetrics.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "stack_msgs/msg/detail/system_metrics__struct.h"
#include "stack_msgs/msg/detail/system_metrics__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool stack_msgs__msg__system_metrics__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("stack_msgs.msg._system_metrics.SystemMetrics", full_classname_dest, 44) == 0);
  }
  stack_msgs__msg__SystemMetrics * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // cpu_percent
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_percent");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cpu_percent = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cpu_temp_celsius
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_temp_celsius");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cpu_temp_celsius = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gpu_percent
    PyObject * field = PyObject_GetAttrString(_pymsg, "gpu_percent");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gpu_percent = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gpu_temp_celsius
    PyObject * field = PyObject_GetAttrString(_pymsg, "gpu_temp_celsius");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gpu_temp_celsius = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gpu_freq_mhz
    PyObject * field = PyObject_GetAttrString(_pymsg, "gpu_freq_mhz");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gpu_freq_mhz = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ram_used_mb
    PyObject * field = PyObject_GetAttrString(_pymsg, "ram_used_mb");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ram_used_mb = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ram_total_mb
    PyObject * field = PyObject_GetAttrString(_pymsg, "ram_total_mb");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ram_total_mb = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ram_percent
    PyObject * field = PyObject_GetAttrString(_pymsg, "ram_percent");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->ram_percent = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // is_throttled
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_throttled");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_throttled = (Py_True == field);
    Py_DECREF(field);
  }
  {  // power_draw_mw
    PyObject * field = PyObject_GetAttrString(_pymsg, "power_draw_mw");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->power_draw_mw = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // system_healthy
    PyObject * field = PyObject_GetAttrString(_pymsg, "system_healthy");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->system_healthy = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * stack_msgs__msg__system_metrics__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SystemMetrics */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("stack_msgs.msg._system_metrics");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SystemMetrics");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  stack_msgs__msg__SystemMetrics * ros_message = (stack_msgs__msg__SystemMetrics *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cpu_percent
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cpu_percent);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_percent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cpu_temp_celsius
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cpu_temp_celsius);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_temp_celsius", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gpu_percent
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gpu_percent);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gpu_percent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gpu_temp_celsius
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gpu_temp_celsius);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gpu_temp_celsius", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gpu_freq_mhz
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gpu_freq_mhz);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gpu_freq_mhz", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ram_used_mb
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ram_used_mb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ram_used_mb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ram_total_mb
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ram_total_mb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ram_total_mb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ram_percent
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->ram_percent);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ram_percent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_throttled
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_throttled ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_throttled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // power_draw_mw
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->power_draw_mw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "power_draw_mw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // system_healthy
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->system_healthy ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "system_healthy", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
