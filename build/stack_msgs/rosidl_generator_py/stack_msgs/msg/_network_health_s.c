// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from stack_msgs:msg/NetworkHealth.idl
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
#include "stack_msgs/msg/detail/network_health__struct.h"
#include "stack_msgs/msg/detail/network_health__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool stack_msgs__msg__network_health__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("stack_msgs.msg._network_health.NetworkHealth", full_classname_dest, 44) == 0);
  }
  stack_msgs__msg__NetworkHealth * ros_message = _ros_message;
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
  {  // interface_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "interface_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->interface_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // rtt_avg
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtt_avg");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rtt_avg = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rtt_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtt_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rtt_min = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rtt_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtt_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rtt_max = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rtt_stddev
    PyObject * field = PyObject_GetAttrString(_pymsg, "rtt_stddev");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rtt_stddev = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // packet_loss_percent
    PyObject * field = PyObject_GetAttrString(_pymsg, "packet_loss_percent");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->packet_loss_percent = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // available_bandwidth
    PyObject * field = PyObject_GetAttrString(_pymsg, "available_bandwidth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->available_bandwidth = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // utilized_bandwidth
    PyObject * field = PyObject_GetAttrString(_pymsg, "utilized_bandwidth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->utilized_bandwidth = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // quality_score
    PyObject * field = PyObject_GetAttrString(_pymsg, "quality_score");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->quality_score = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // is_stable
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_stable");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_stable = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * stack_msgs__msg__network_health__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NetworkHealth */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("stack_msgs.msg._network_health");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NetworkHealth");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  stack_msgs__msg__NetworkHealth * ros_message = (stack_msgs__msg__NetworkHealth *)raw_ros_message;
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
  {  // interface_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->interface_name.data,
      strlen(ros_message->interface_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "interface_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtt_avg
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rtt_avg);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtt_avg", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtt_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rtt_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtt_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtt_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rtt_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtt_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rtt_stddev
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rtt_stddev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rtt_stddev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // packet_loss_percent
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->packet_loss_percent);
    {
      int rc = PyObject_SetAttrString(_pymessage, "packet_loss_percent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // available_bandwidth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->available_bandwidth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "available_bandwidth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utilized_bandwidth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->utilized_bandwidth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utilized_bandwidth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quality_score
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->quality_score);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quality_score", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_stable
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_stable ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_stable", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
