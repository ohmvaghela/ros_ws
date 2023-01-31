; Auto-generated. Do not edit!


(cl:in-package bot_msg-msg)


;//! \htmlinclude bot_vel.msg.html

(cl:defclass <bot_vel> (roslisp-msg-protocol:ros-message)
  ((linear_vel
    :reader linear_vel
    :initarg :linear_vel
    :type cl:float
    :initform 0.0)
   (angular_vel
    :reader angular_vel
    :initarg :angular_vel
    :type cl:float
    :initform 0.0)
   (orientation
    :reader orientation
    :initarg :orientation
    :type cl:float
    :initform 0.0))
)

(cl:defclass bot_vel (<bot_vel>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <bot_vel>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'bot_vel)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name bot_msg-msg:<bot_vel> is deprecated: use bot_msg-msg:bot_vel instead.")))

(cl:ensure-generic-function 'linear_vel-val :lambda-list '(m))
(cl:defmethod linear_vel-val ((m <bot_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bot_msg-msg:linear_vel-val is deprecated.  Use bot_msg-msg:linear_vel instead.")
  (linear_vel m))

(cl:ensure-generic-function 'angular_vel-val :lambda-list '(m))
(cl:defmethod angular_vel-val ((m <bot_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bot_msg-msg:angular_vel-val is deprecated.  Use bot_msg-msg:angular_vel instead.")
  (angular_vel m))

(cl:ensure-generic-function 'orientation-val :lambda-list '(m))
(cl:defmethod orientation-val ((m <bot_vel>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bot_msg-msg:orientation-val is deprecated.  Use bot_msg-msg:orientation instead.")
  (orientation m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <bot_vel>) ostream)
  "Serializes a message object of type '<bot_vel>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'linear_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angular_vel))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'orientation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <bot_vel>) istream)
  "Deserializes a message object of type '<bot_vel>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'linear_vel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angular_vel) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'orientation) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<bot_vel>)))
  "Returns string type for a message object of type '<bot_vel>"
  "bot_msg/bot_vel")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'bot_vel)))
  "Returns string type for a message object of type 'bot_vel"
  "bot_msg/bot_vel")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<bot_vel>)))
  "Returns md5sum for a message object of type '<bot_vel>"
  "263c8ee54faf31d00782a1588f2032bf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'bot_vel)))
  "Returns md5sum for a message object of type 'bot_vel"
  "263c8ee54faf31d00782a1588f2032bf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<bot_vel>)))
  "Returns full string definition for message of type '<bot_vel>"
  (cl:format cl:nil "float32 linear_vel~%float32 angular_vel # CCW -> +ve~%float32 orientation # angle with x-axis~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'bot_vel)))
  "Returns full string definition for message of type 'bot_vel"
  (cl:format cl:nil "float32 linear_vel~%float32 angular_vel # CCW -> +ve~%float32 orientation # angle with x-axis~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <bot_vel>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <bot_vel>))
  "Converts a ROS message object to a list"
  (cl:list 'bot_vel
    (cl:cons ':linear_vel (linear_vel msg))
    (cl:cons ':angular_vel (angular_vel msg))
    (cl:cons ':orientation (orientation msg))
))
