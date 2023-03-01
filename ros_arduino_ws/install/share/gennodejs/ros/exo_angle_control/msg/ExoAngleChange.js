// Auto-generated. Do not edit!

// (in-package exo_angle_control.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ExoAngleChange {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.hipLeft = null;
      this.hipRight = null;
      this.kneeLeft = null;
      this.kneeRight = null;
    }
    else {
      if (initObj.hasOwnProperty('hipLeft')) {
        this.hipLeft = initObj.hipLeft
      }
      else {
        this.hipLeft = 0;
      }
      if (initObj.hasOwnProperty('hipRight')) {
        this.hipRight = initObj.hipRight
      }
      else {
        this.hipRight = 0;
      }
      if (initObj.hasOwnProperty('kneeLeft')) {
        this.kneeLeft = initObj.kneeLeft
      }
      else {
        this.kneeLeft = 0;
      }
      if (initObj.hasOwnProperty('kneeRight')) {
        this.kneeRight = initObj.kneeRight
      }
      else {
        this.kneeRight = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ExoAngleChange
    // Serialize message field [hipLeft]
    bufferOffset = _serializer.uint32(obj.hipLeft, buffer, bufferOffset);
    // Serialize message field [hipRight]
    bufferOffset = _serializer.uint32(obj.hipRight, buffer, bufferOffset);
    // Serialize message field [kneeLeft]
    bufferOffset = _serializer.uint32(obj.kneeLeft, buffer, bufferOffset);
    // Serialize message field [kneeRight]
    bufferOffset = _serializer.uint32(obj.kneeRight, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ExoAngleChange
    let len;
    let data = new ExoAngleChange(null);
    // Deserialize message field [hipLeft]
    data.hipLeft = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [hipRight]
    data.hipRight = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [kneeLeft]
    data.kneeLeft = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [kneeRight]
    data.kneeRight = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'exo_angle_control/ExoAngleChange';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '32bc8f464253af317aba999b23bbafc7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 hipLeft
    uint32 hipRight
    uint32 kneeLeft
    uint32 kneeRight
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ExoAngleChange(null);
    if (msg.hipLeft !== undefined) {
      resolved.hipLeft = msg.hipLeft;
    }
    else {
      resolved.hipLeft = 0
    }

    if (msg.hipRight !== undefined) {
      resolved.hipRight = msg.hipRight;
    }
    else {
      resolved.hipRight = 0
    }

    if (msg.kneeLeft !== undefined) {
      resolved.kneeLeft = msg.kneeLeft;
    }
    else {
      resolved.kneeLeft = 0
    }

    if (msg.kneeRight !== undefined) {
      resolved.kneeRight = msg.kneeRight;
    }
    else {
      resolved.kneeRight = 0
    }

    return resolved;
    }
};

module.exports = ExoAngleChange;
