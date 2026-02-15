# generated from rosidl_generator_py/resource/_idl.py.em
# with input from stack_msgs:msg/SystemMetrics.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SystemMetrics(type):
    """Metaclass of message 'SystemMetrics'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('stack_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'stack_msgs.msg.SystemMetrics')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__system_metrics
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__system_metrics
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__system_metrics
            cls._TYPE_SUPPORT = module.type_support_msg__msg__system_metrics
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__system_metrics

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SystemMetrics(metaclass=Metaclass_SystemMetrics):
    """Message class 'SystemMetrics'."""

    __slots__ = [
        '_header',
        '_cpu_percent',
        '_cpu_temp_celsius',
        '_gpu_percent',
        '_gpu_temp_celsius',
        '_gpu_freq_mhz',
        '_ram_used_mb',
        '_ram_total_mb',
        '_ram_percent',
        '_is_throttled',
        '_power_draw_mw',
        '_system_healthy',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'cpu_percent': 'float',
        'cpu_temp_celsius': 'float',
        'gpu_percent': 'float',
        'gpu_temp_celsius': 'float',
        'gpu_freq_mhz': 'uint32',
        'ram_used_mb': 'uint32',
        'ram_total_mb': 'uint32',
        'ram_percent': 'float',
        'is_throttled': 'boolean',
        'power_draw_mw': 'uint32',
        'system_healthy': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.cpu_percent = kwargs.get('cpu_percent', float())
        self.cpu_temp_celsius = kwargs.get('cpu_temp_celsius', float())
        self.gpu_percent = kwargs.get('gpu_percent', float())
        self.gpu_temp_celsius = kwargs.get('gpu_temp_celsius', float())
        self.gpu_freq_mhz = kwargs.get('gpu_freq_mhz', int())
        self.ram_used_mb = kwargs.get('ram_used_mb', int())
        self.ram_total_mb = kwargs.get('ram_total_mb', int())
        self.ram_percent = kwargs.get('ram_percent', float())
        self.is_throttled = kwargs.get('is_throttled', bool())
        self.power_draw_mw = kwargs.get('power_draw_mw', int())
        self.system_healthy = kwargs.get('system_healthy', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.cpu_percent != other.cpu_percent:
            return False
        if self.cpu_temp_celsius != other.cpu_temp_celsius:
            return False
        if self.gpu_percent != other.gpu_percent:
            return False
        if self.gpu_temp_celsius != other.gpu_temp_celsius:
            return False
        if self.gpu_freq_mhz != other.gpu_freq_mhz:
            return False
        if self.ram_used_mb != other.ram_used_mb:
            return False
        if self.ram_total_mb != other.ram_total_mb:
            return False
        if self.ram_percent != other.ram_percent:
            return False
        if self.is_throttled != other.is_throttled:
            return False
        if self.power_draw_mw != other.power_draw_mw:
            return False
        if self.system_healthy != other.system_healthy:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def cpu_percent(self):
        """Message field 'cpu_percent'."""
        return self._cpu_percent

    @cpu_percent.setter
    def cpu_percent(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cpu_percent' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cpu_percent' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cpu_percent = value

    @builtins.property
    def cpu_temp_celsius(self):
        """Message field 'cpu_temp_celsius'."""
        return self._cpu_temp_celsius

    @cpu_temp_celsius.setter
    def cpu_temp_celsius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cpu_temp_celsius' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cpu_temp_celsius' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cpu_temp_celsius = value

    @builtins.property
    def gpu_percent(self):
        """Message field 'gpu_percent'."""
        return self._gpu_percent

    @gpu_percent.setter
    def gpu_percent(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gpu_percent' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gpu_percent' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gpu_percent = value

    @builtins.property
    def gpu_temp_celsius(self):
        """Message field 'gpu_temp_celsius'."""
        return self._gpu_temp_celsius

    @gpu_temp_celsius.setter
    def gpu_temp_celsius(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gpu_temp_celsius' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gpu_temp_celsius' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gpu_temp_celsius = value

    @builtins.property
    def gpu_freq_mhz(self):
        """Message field 'gpu_freq_mhz'."""
        return self._gpu_freq_mhz

    @gpu_freq_mhz.setter
    def gpu_freq_mhz(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gpu_freq_mhz' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'gpu_freq_mhz' field must be an unsigned integer in [0, 4294967295]"
        self._gpu_freq_mhz = value

    @builtins.property
    def ram_used_mb(self):
        """Message field 'ram_used_mb'."""
        return self._ram_used_mb

    @ram_used_mb.setter
    def ram_used_mb(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ram_used_mb' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'ram_used_mb' field must be an unsigned integer in [0, 4294967295]"
        self._ram_used_mb = value

    @builtins.property
    def ram_total_mb(self):
        """Message field 'ram_total_mb'."""
        return self._ram_total_mb

    @ram_total_mb.setter
    def ram_total_mb(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ram_total_mb' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'ram_total_mb' field must be an unsigned integer in [0, 4294967295]"
        self._ram_total_mb = value

    @builtins.property
    def ram_percent(self):
        """Message field 'ram_percent'."""
        return self._ram_percent

    @ram_percent.setter
    def ram_percent(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'ram_percent' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'ram_percent' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._ram_percent = value

    @builtins.property
    def is_throttled(self):
        """Message field 'is_throttled'."""
        return self._is_throttled

    @is_throttled.setter
    def is_throttled(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_throttled' field must be of type 'bool'"
        self._is_throttled = value

    @builtins.property
    def power_draw_mw(self):
        """Message field 'power_draw_mw'."""
        return self._power_draw_mw

    @power_draw_mw.setter
    def power_draw_mw(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'power_draw_mw' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'power_draw_mw' field must be an unsigned integer in [0, 4294967295]"
        self._power_draw_mw = value

    @builtins.property
    def system_healthy(self):
        """Message field 'system_healthy'."""
        return self._system_healthy

    @system_healthy.setter
    def system_healthy(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'system_healthy' field must be of type 'bool'"
        self._system_healthy = value
