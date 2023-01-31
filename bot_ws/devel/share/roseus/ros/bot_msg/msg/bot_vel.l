;; Auto-generated. Do not edit!


(when (boundp 'bot_msg::bot_vel)
  (if (not (find-package "BOT_MSG"))
    (make-package "BOT_MSG"))
  (shadow 'bot_vel (find-package "BOT_MSG")))
(unless (find-package "BOT_MSG::BOT_VEL")
  (make-package "BOT_MSG::BOT_VEL"))

(in-package "ROS")
;;//! \htmlinclude bot_vel.msg.html


(defclass bot_msg::bot_vel
  :super ros::object
  :slots (_linear_vel _angular_vel _orientation ))

(defmethod bot_msg::bot_vel
  (:init
   (&key
    ((:linear_vel __linear_vel) 0.0)
    ((:angular_vel __angular_vel) 0.0)
    ((:orientation __orientation) 0.0)
    )
   (send-super :init)
   (setq _linear_vel (float __linear_vel))
   (setq _angular_vel (float __angular_vel))
   (setq _orientation (float __orientation))
   self)
  (:linear_vel
   (&optional __linear_vel)
   (if __linear_vel (setq _linear_vel __linear_vel)) _linear_vel)
  (:angular_vel
   (&optional __angular_vel)
   (if __angular_vel (setq _angular_vel __angular_vel)) _angular_vel)
  (:orientation
   (&optional __orientation)
   (if __orientation (setq _orientation __orientation)) _orientation)
  (:serialization-length
   ()
   (+
    ;; float32 _linear_vel
    4
    ;; float32 _angular_vel
    4
    ;; float32 _orientation
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _linear_vel
       (sys::poke _linear_vel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angular_vel
       (sys::poke _angular_vel (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _orientation
       (sys::poke _orientation (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _linear_vel
     (setq _linear_vel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angular_vel
     (setq _angular_vel (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _orientation
     (setq _orientation (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get bot_msg::bot_vel :md5sum-) "263c8ee54faf31d00782a1588f2032bf")
(setf (get bot_msg::bot_vel :datatype-) "bot_msg/bot_vel")
(setf (get bot_msg::bot_vel :definition-)
      "float32 linear_vel
float32 angular_vel # CCW -> +ve
float32 orientation # angle with x-axis

")



(provide :bot_msg/bot_vel "263c8ee54faf31d00782a1588f2032bf")


