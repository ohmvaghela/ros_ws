; Auto-generated. Do not edit!


(cl:in-package exo_angle_control-msg)


;//! \htmlinclude ExoAngle.msg.html

(cl:defclass <ExoAngle> (roslisp-msg-protocol:ros-message)
  ((hipLeft
    :reader hipLeft
    :initarg :hipLeft
    :type cl:integer
    :initform 0)
   (hipRight
    :reader hipRight
    :initarg :hipRight
    :type cl:integer
    :initform 0)
   (kneeLeft
    :reader kneeLeft
    :initarg :kneeLeft
    :type cl:integer
    :initform 0)
   (kneeRight
    :reader kneeRight
    :initarg :kneeRight
    :type cl:integer
    :initform 0))
)

(cl:defclass ExoAngle (<ExoAngle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ExoAngle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ExoAngle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name exo_angle_control-msg:<ExoAngle> is deprecated: use exo_angle_control-msg:ExoAngle instead.")))

(cl:ensure-generic-function 'hipLeft-val :lambda-list '(m))
(cl:defmethod hipLeft-val ((m <ExoAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader exo_angle_control-msg:hipLeft-val is deprecated.  Use exo_angle_control-msg:hipLeft instead.")
  (hipLeft m))

(cl:ensure-generic-function 'hipRight-val :lambda-list '(m))
(cl:defmethod hipRight-val ((m <ExoAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader exo_angle_control-msg:hipRight-val is deprecated.  Use exo_angle_control-msg:hipRight instead.")
  (hipRight m))

(cl:ensure-generic-function 'kneeLeft-val :lambda-list '(m))
(cl:defmethod kneeLeft-val ((m <ExoAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader exo_angle_control-msg:kneeLeft-val is deprecated.  Use exo_angle_control-msg:kneeLeft instead.")
  (kneeLeft m))

(cl:ensure-generic-function 'kneeRight-val :lambda-list '(m))
(cl:defmethod kneeRight-val ((m <ExoAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader exo_angle_control-msg:kneeRight-val is deprecated.  Use exo_angle_control-msg:kneeRight instead.")
  (kneeRight m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ExoAngle>) ostream)
  "Serializes a message object of type '<ExoAngle>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hipLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'hipLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'hipLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'hipLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hipRight)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'hipRight)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'hipRight)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'hipRight)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'kneeLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'kneeLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'kneeLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'kneeLeft)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'kneeRight)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'kneeRight)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'kneeRight)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'kneeRight)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ExoAngle>) istream)
  "Deserializes a message object of type '<ExoAngle>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hipLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'hipLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'hipLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'hipLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'hipRight)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'hipRight)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'hipRight)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'hipRight)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'kneeLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'kneeLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'kneeLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'kneeLeft)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'kneeRight)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'kneeRight)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'kneeRight)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'kneeRight)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ExoAngle>)))
  "Returns string type for a message object of type '<ExoAngle>"
  "exo_angle_control/ExoAngle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ExoAngle)))
  "Returns string type for a message object of type 'ExoAngle"
  "exo_angle_control/ExoAngle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ExoAngle>)))
  "Returns md5sum for a message object of type '<ExoAngle>"
  "32bc8f464253af317aba999b23bbafc7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ExoAngle)))
  "Returns md5sum for a message object of type 'ExoAngle"
  "32bc8f464253af317aba999b23bbafc7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ExoAngle>)))
  "Returns full string definition for message of type '<ExoAngle>"
  (cl:format cl:nil "uint32 hipLeft~%uint32 hipRight~%uint32 kneeLeft~%uint32 kneeRight~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ExoAngle)))
  "Returns full string definition for message of type 'ExoAngle"
  (cl:format cl:nil "uint32 hipLeft~%uint32 hipRight~%uint32 kneeLeft~%uint32 kneeRight~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ExoAngle>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ExoAngle>))
  "Converts a ROS message object to a list"
  (cl:list 'ExoAngle
    (cl:cons ':hipLeft (hipLeft msg))
    (cl:cons ':hipRight (hipRight msg))
    (cl:cons ':kneeLeft (kneeLeft msg))
    (cl:cons ':kneeRight (kneeRight msg))
))
