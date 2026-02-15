# generated from rosidl_generator_py/resource/_idl.py.em
# with input from stack_msgs:msg/NetworkHealth.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NetworkHealth(type):
    """Metaclass of message 'NetworkHealth'."""

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
                'stack_msgs.msg.NetworkHealth')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__network_health
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__network_health
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__network_health
            cls._TYPE_SUPPORT = module.type_support_msg__msg__network_health
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__network_health

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


class NetworkHealth(metaclass=Metaclass_NetworkHealth):
    """Message class 'NetworkHealth'."""

    __slots__ = [
        '_header',
        '_interface_name',
        '_rtt_avg',
        '_rtt_min',
        '_rtt_max',
        '_rtt_stddev',
        '_packet_loss_percent',
        '_available_bandwidth',
        '_utilized_bandwidth',
        '_quality_score',
        '_is_stable',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'interface_name': 'string',
        'rtt_avg': 'float',
        'rtt_min': 'float',
        'rtt_max': 'float',
        'rtt_stddev': 'float',
        'packet_loss_percent': 'float',
        'available_bandwidth': 'float',
        'utilized_bandwidth': 'float',
        'quality_score': 'uint8',
        'is_stable': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.interface_name = kwargs.get('interface_name', str())
        self.rtt_avg = kwargs.get('rtt_avg', float())
        self.rtt_min = kwargs.get('rtt_min', float())
        self.rtt_max = kwargs.get('rtt_max', float())
        self.rtt_stddev = kwargs.get('rtt_stddev', float())
        self.packet_loss_percent = kwargs.get('packet_loss_percent', float())
        self.available_bandwidth = kwargs.get('available_bandwidth', float())
        self.utilized_bandwidth = kwargs.get('utilized_bandwidth', float())
        self.quality_score = kwargs.get('quality_score', int())
        self.is_stable = kwargs.get('is_stable', bool())

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
        if self.interface_name != other.interface_name:
            return False
        if self.rtt_avg != other.rtt_avg:
            return False
        if self.rtt_min != other.rtt_min:
            return False
        if self.rtt_max != other.rtt_max:
            return False
        if self.rtt_stddev != other.rtt_stddev:
            return False
        if self.packet_loss_percent != other.packet_loss_percent:
            return False
        if self.available_bandwidth != other.available_bandwidth:
            return False
        if self.utilized_bandwidth != other.utilized_bandwidth:
            return False
        if self.quality_score != other.quality_score:
            return False
        if self.is_stable != other.is_stable:
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
    def interface_name(self):
        """Message field 'interface_name'."""
        return self._interface_name

    @interface_name.setter
    def interface_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'interface_name' field must be of type 'str'"
        self._interface_name = value

    @builtins.property
    def rtt_avg(self):
        """Message field 'rtt_avg'."""
        return self._rtt_avg

    @rtt_avg.setter
    def rtt_avg(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rtt_avg' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rtt_avg' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rtt_avg = value

    @builtins.property
    def rtt_min(self):
        """Message field 'rtt_min'."""
        return self._rtt_min

    @rtt_min.setter
    def rtt_min(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rtt_min' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rtt_min' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rtt_min = value

    @builtins.property
    def rtt_max(self):
        """Message field 'rtt_max'."""
        return self._rtt_max

    @rtt_max.setter
    def rtt_max(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rtt_max' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rtt_max' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rtt_max = value

    @builtins.property
    def rtt_stddev(self):
        """Message field 'rtt_stddev'."""
        return self._rtt_stddev

    @rtt_stddev.setter
    def rtt_stddev(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rtt_stddev' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rtt_stddev' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rtt_stddev = value

    @builtins.property
    def packet_loss_percent(self):
        """Message field 'packet_loss_percent'."""
        return self._packet_loss_percent

    @packet_loss_percent.setter
    def packet_loss_percent(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'packet_loss_percent' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'packet_loss_percent' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._packet_loss_percent = value

    @builtins.property
    def available_bandwidth(self):
        """Message field 'available_bandwidth'."""
        return self._available_bandwidth

    @available_bandwidth.setter
    def available_bandwidth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'available_bandwidth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'available_bandwidth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._available_bandwidth = value

    @builtins.property
    def utilized_bandwidth(self):
        """Message field 'utilized_bandwidth'."""
        return self._utilized_bandwidth

    @utilized_bandwidth.setter
    def utilized_bandwidth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'utilized_bandwidth' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'utilized_bandwidth' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._utilized_bandwidth = value

    @builtins.property
    def quality_score(self):
        """Message field 'quality_score'."""
        return self._quality_score

    @quality_score.setter
    def quality_score(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'quality_score' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'quality_score' field must be an unsigned integer in [0, 255]"
        self._quality_score = value

    @builtins.property
    def is_stable(self):
        """Message field 'is_stable'."""
        return self._is_stable

    @is_stable.setter
    def is_stable(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_stable' field must be of type 'bool'"
        self._is_stable = value
