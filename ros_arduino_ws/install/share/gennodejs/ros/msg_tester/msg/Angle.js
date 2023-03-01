// Auto-generated. Do not edit!

// (in-package msg_tester.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Angle {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.des_angle = null;
    }
    else {
      if (initObj.hasOwnProperty('des_angle')) {
        this.des_angle = initObj.des_angle
      }
      else {
        this.des_angle = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Angle
    // Serialize message field [des_angle]
    bufferOffset = _serializer.uint32(obj.des_angle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Angle
    let len;
    let data = new Angle(null);
    // Deserialize message field [des_angle]
    data.des_angle = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'msg_tester/Angle';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3b014ad599de74f65dbbbb8e4f583b3d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 des_angle
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Angle(null);
    if (msg.des_angle !== undefined) {
      resolved.des_angle = msg.des_angle;
    }
    else {
      resolved.des_angle = 0
    }

    return resolved;
    }
};

module.exports = Angle;
