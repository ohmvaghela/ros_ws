;; Auto-generated. Do not edit!


(when (boundp 'exo_angle_control::ExoAngleChange)
  (if (not (find-package "EXO_ANGLE_CONTROL"))
    (make-package "EXO_ANGLE_CONTROL"))
  (shadow 'ExoAngleChange (find-package "EXO_ANGLE_CONTROL")))
(unless (find-package "EXO_ANGLE_CONTROL::EXOANGLECHANGE")
  (make-package "EXO_ANGLE_CONTROL::EXOANGLECHANGE"))

(in-package "ROS")
;;//! \htmlinclude ExoAngleChange.msg.html


(defclass exo_angle_control::ExoAngleChange
  :super ros::object
  :slots (_hipLeft _hipRight _kneeLeft _kneeRight ))

(defmethod exo_angle_control::ExoAngleChange
  (:init
   (&key
    ((:hipLeft __hipLeft) 0)
    ((:hipRight __hipRight) 0)
    ((:kneeLeft __kneeLeft) 0)
    ((:kneeRight __kneeRight) 0)
    )
   (send-super :init)
   (setq _hipLeft (round __hipLeft))
   (setq _hipRight (round __hipRight))
   (setq _kneeLeft (round __kneeLeft))
   (setq _kneeRight (round __kneeRight))
   self)
  (:hipLeft
   (&optional __hipLeft)
   (if __hipLeft (setq _hipLeft __hipLeft)) _hipLeft)
  (:hipRight
   (&optional __hipRight)
   (if __hipRight (setq _hipRight __hipRight)) _hipRight)
  (:kneeLeft
   (&optional __kneeLeft)
   (if __kneeLeft (setq _kneeLeft __kneeLeft)) _kneeLeft)
  (:kneeRight
   (&optional __kneeRight)
   (if __kneeRight (setq _kneeRight __kneeRight)) _kneeRight)
  (:serialization-length
   ()
   (+
    ;; uint32 _hipLeft
    4
    ;; uint32 _hipRight
    4
    ;; uint32 _kneeLeft
    4
    ;; uint32 _kneeRight
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _hipLeft
       (write-long _hipLeft s)
     ;; uint32 _hipRight
       (write-long _hipRight s)
     ;; uint32 _kneeLeft
       (write-long _kneeLeft s)
     ;; uint32 _kneeRight
       (write-long _kneeRight s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _hipLeft
     (setq _hipLeft (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _hipRight
     (setq _hipRight (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _kneeLeft
     (setq _kneeLeft (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _kneeRight
     (setq _kneeRight (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get exo_angle_control::ExoAngleChange :md5sum-) "32bc8f464253af317aba999b23bbafc7")
(setf (get exo_angle_control::ExoAngleChange :datatype-) "exo_angle_control/ExoAngleChange")
(setf (get exo_angle_control::ExoAngleChange :definition-)
      "uint32 hipLeft
uint32 hipRight
uint32 kneeLeft
uint32 kneeRight
")



(provide :exo_angle_control/ExoAngleChange "32bc8f464253af317aba999b23bbafc7")


