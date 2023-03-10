# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from exo_angle_control/ExoAngle.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class ExoAngle(genpy.Message):
  _md5sum = "32bc8f464253af317aba999b23bbafc7"
  _type = "exo_angle_control/ExoAngle"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint32 hipLeft
uint32 hipRight
uint32 kneeLeft
uint32 kneeRight"""
  __slots__ = ['hipLeft','hipRight','kneeLeft','kneeRight']
  _slot_types = ['uint32','uint32','uint32','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       hipLeft,hipRight,kneeLeft,kneeRight

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ExoAngle, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.hipLeft is None:
        self.hipLeft = 0
      if self.hipRight is None:
        self.hipRight = 0
      if self.kneeLeft is None:
        self.kneeLeft = 0
      if self.kneeRight is None:
        self.kneeRight = 0
    else:
      self.hipLeft = 0
      self.hipRight = 0
      self.kneeLeft = 0
      self.kneeRight = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_4I().pack(_x.hipLeft, _x.hipRight, _x.kneeLeft, _x.kneeRight))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.hipLeft, _x.hipRight, _x.kneeLeft, _x.kneeRight,) = _get_struct_4I().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_4I().pack(_x.hipLeft, _x.hipRight, _x.kneeLeft, _x.kneeRight))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 16
      (_x.hipLeft, _x.hipRight, _x.kneeLeft, _x.kneeRight,) = _get_struct_4I().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_4I = None
def _get_struct_4I():
    global _struct_4I
    if _struct_4I is None:
        _struct_4I = struct.Struct("<4I")
    return _struct_4I
