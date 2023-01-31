;; Auto-generated. Do not edit!


(when (boundp 'bot_msg::bot_param)
  (if (not (find-package "BOT_MSG"))
    (make-package "BOT_MSG"))
  (shadow 'bot_param (find-package "BOT_MSG")))
(unless (find-package "BOT_MSG::BOT_PARAM")
  (make-package "BOT_MSG::BOT_PARAM"))

(in-package "ROS")
;;//! \htmlinclude bot_param.msg.html


(defclass bot_msg::bot_param
  :super ros::object
  :slots (_radius _lx _ly ))

(defmethod bot_msg::bot_param
  (:init
   (&key
    ((:radius __radius) 0.0)
    ((:lx __lx) 0.0)
    ((:ly __ly) 0.0)
    )
   (send-super :init)
   (setq _radius (float __radius))
   (setq _lx (float __lx))
   (setq _ly (float __ly))
   self)
  (:radius
   (&optional __radius)
   (if __radius (setq _radius __radius)) _radius)
  (:lx
   (&optional __lx)
   (if __lx (setq _lx __lx)) _lx)
  (:ly
   (&optional __ly)
   (if __ly (setq _ly __ly)) _ly)
  (:serialization-length
   ()
   (+
    ;; float32 _radius
    4
    ;; float32 _lx
    4
    ;; float32 _ly
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _radius
       (sys::poke _radius (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _lx
       (sys::poke _lx (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _ly
       (sys::poke _ly (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _radius
     (setq _radius (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _lx
     (setq _lx (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _ly
     (setq _ly (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get bot_msg::bot_param :md5sum-) "c5e53d0394b914157d262ee240387e65")
(setf (get bot_msg::bot_param :datatype-) "bot_msg/bot_param")
(setf (get bot_msg::bot_param :definition-)
      "float32 radius
float32 lx # half of length of bot in x-direction
float32 ly # half of length of bot in y-direction


")



(provide :bot_msg/bot_param "c5e53d0394b914157d262ee240387e65")


