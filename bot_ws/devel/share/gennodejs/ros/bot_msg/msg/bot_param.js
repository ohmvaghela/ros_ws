// Auto-generated. Do not edit!

// (in-package bot_msg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class bot_param {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.radius = null;
      this.lx = null;
      this.ly = null;
    }
    else {
      if (initObj.hasOwnProperty('radius')) {
        this.radius = initObj.radius
      }
      else {
        this.radius = 0.0;
      }
      if (initObj.hasOwnProperty('lx')) {
        this.lx = initObj.lx
      }
      else {
        this.lx = 0.0;
      }
      if (initObj.hasOwnProperty('ly')) {
        this.ly = initObj.ly
      }
      else {
        this.ly = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type bot_param
    // Serialize message field [radius]
    bufferOffset = _serializer.float32(obj.radius, buffer, bufferOffset);
    // Serialize message field [lx]
    bufferOffset = _serializer.float32(obj.lx, buffer, bufferOffset);
    // Serialize message field [ly]
    bufferOffset = _serializer.float32(obj.ly, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type bot_param
    let len;
    let data = new bot_param(null);
    // Deserialize message field [radius]
    data.radius = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [lx]
    data.lx = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [ly]
    data.ly = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'bot_msg/bot_param';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c5e53d0394b914157d262ee240387e65';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 radius
    float32 lx # half of length of bot in x-direction
    float32 ly # half of length of bot in y-direction
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new bot_param(null);
    if (msg.radius !== undefined) {
      resolved.radius = msg.radius;
    }
    else {
      resolved.radius = 0.0
    }

    if (msg.lx !== undefined) {
      resolved.lx = msg.lx;
    }
    else {
      resolved.lx = 0.0
    }

    if (msg.ly !== undefined) {
      resolved.ly = msg.ly;
    }
    else {
      resolved.ly = 0.0
    }

    return resolved;
    }
};

module.exports = bot_param;
