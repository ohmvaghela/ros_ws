; Auto-generated. Do not edit!


(cl:in-package msg_tester-msg)


;//! \htmlinclude Angle.msg.html

(cl:defclass <Angle> (roslisp-msg-protocol:ros-message)
  ((des_angle
    :reader des_angle
    :initarg :des_angle
    :type cl:integer
    :initform 0))
)

(cl:defclass Angle (<Angle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Angle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Angle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name msg_tester-msg:<Angle> is deprecated: use msg_tester-msg:Angle instead.")))

(cl:ensure-generic-function 'des_angle-val :lambda-list '(m))
(cl:defmethod des_angle-val ((m <Angle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader msg_tester-msg:des_angle-val is deprecated.  Use msg_tester-msg:des_angle instead.")
  (des_angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Angle>) ostream)
  "Serializes a message object of type '<Angle>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'des_angle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'des_angle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'des_angle)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'des_angle)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Angle>) istream)
  "Deserializes a message object of type '<Angle>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'des_angle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'des_angle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'des_angle)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'des_angle)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Angle>)))
  "Returns string type for a message object of type '<Angle>"
  "msg_tester/Angle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Angle)))
  "Returns string type for a message object of type 'Angle"
  "msg_tester/Angle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Angle>)))
  "Returns md5sum for a message object of type '<Angle>"
  "3b014ad599de74f65dbbbb8e4f583b3d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Angle)))
  "Returns md5sum for a message object of type 'Angle"
  "3b014ad599de74f65dbbbb8e4f583b3d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Angle>)))
  "Returns full string definition for message of type '<Angle>"
  (cl:format cl:nil "uint32 des_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Angle)))
  "Returns full string definition for message of type 'Angle"
  (cl:format cl:nil "uint32 des_angle~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Angle>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Angle>))
  "Converts a ROS message object to a list"
  (cl:list 'Angle
    (cl:cons ':des_angle (des_angle msg))
))
