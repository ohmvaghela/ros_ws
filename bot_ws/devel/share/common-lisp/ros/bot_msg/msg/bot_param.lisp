; Auto-generated. Do not edit!


(cl:in-package bot_msg-msg)


;//! \htmlinclude bot_param.msg.html

(cl:defclass <bot_param> (roslisp-msg-protocol:ros-message)
  ((radius
    :reader radius
    :initarg :radius
    :type cl:float
    :initform 0.0)
   (lx
    :reader lx
    :initarg :lx
    :type cl:float
    :initform 0.0)
   (ly
    :reader ly
    :initarg :ly
    :type cl:float
    :initform 0.0))
)

(cl:defclass bot_param (<bot_param>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <bot_param>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'bot_param)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name bot_msg-msg:<bot_param> is deprecated: use bot_msg-msg:bot_param instead.")))

(cl:ensure-generic-function 'radius-val :lambda-list '(m))
(cl:defmethod radius-val ((m <bot_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bot_msg-msg:radius-val is deprecated.  Use bot_msg-msg:radius instead.")
  (radius m))

(cl:ensure-generic-function 'lx-val :lambda-list '(m))
(cl:defmethod lx-val ((m <bot_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bot_msg-msg:lx-val is deprecated.  Use bot_msg-msg:lx instead.")
  (lx m))

(cl:ensure-generic-function 'ly-val :lambda-list '(m))
(cl:defmethod ly-val ((m <bot_param>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader bot_msg-msg:ly-val is deprecated.  Use bot_msg-msg:ly instead.")
  (ly m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <bot_param>) ostream)
  "Serializes a message object of type '<bot_param>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'radius))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'ly))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <bot_param>) istream)
  "Deserializes a message object of type '<bot_param>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'radius) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ly) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<bot_param>)))
  "Returns string type for a message object of type '<bot_param>"
  "bot_msg/bot_param")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'bot_param)))
  "Returns string type for a message object of type 'bot_param"
  "bot_msg/bot_param")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<bot_param>)))
  "Returns md5sum for a message object of type '<bot_param>"
  "c5e53d0394b914157d262ee240387e65")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'bot_param)))
  "Returns md5sum for a message object of type 'bot_param"
  "c5e53d0394b914157d262ee240387e65")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<bot_param>)))
  "Returns full string definition for message of type '<bot_param>"
  (cl:format cl:nil "float32 radius~%float32 lx # half of length of bot in x-direction~%float32 ly # half of length of bot in y-direction~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'bot_param)))
  "Returns full string definition for message of type 'bot_param"
  (cl:format cl:nil "float32 radius~%float32 lx # half of length of bot in x-direction~%float32 ly # half of length of bot in y-direction~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <bot_param>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <bot_param>))
  "Converts a ROS message object to a list"
  (cl:list 'bot_param
    (cl:cons ':radius (radius msg))
    (cl:cons ':lx (lx msg))
    (cl:cons ':ly (ly msg))
))
