;; Auto-generated. Do not edit!


(when (boundp 'msg_tester::Angle)
  (if (not (find-package "MSG_TESTER"))
    (make-package "MSG_TESTER"))
  (shadow 'Angle (find-package "MSG_TESTER")))
(unless (find-package "MSG_TESTER::ANGLE")
  (make-package "MSG_TESTER::ANGLE"))

(in-package "ROS")
;;//! \htmlinclude Angle.msg.html


(defclass msg_tester::Angle
  :super ros::object
  :slots (_des_angle ))

(defmethod msg_tester::Angle
  (:init
   (&key
    ((:des_angle __des_angle) 0)
    )
   (send-super :init)
   (setq _des_angle (round __des_angle))
   self)
  (:des_angle
   (&optional __des_angle)
   (if __des_angle (setq _des_angle __des_angle)) _des_angle)
  (:serialization-length
   ()
   (+
    ;; uint32 _des_angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _des_angle
       (write-long _des_angle s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _des_angle
     (setq _des_angle (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get msg_tester::Angle :md5sum-) "3b014ad599de74f65dbbbb8e4f583b3d")
(setf (get msg_tester::Angle :datatype-) "msg_tester/Angle")
(setf (get msg_tester::Angle :definition-)
      "uint32 des_angle
")



(provide :msg_tester/Angle "3b014ad599de74f65dbbbb8e4f583b3d")


