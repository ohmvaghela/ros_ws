
(cl:in-package :asdf)

(defsystem "bot_msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "bot_param" :depends-on ("_package_bot_param"))
    (:file "_package_bot_param" :depends-on ("_package"))
    (:file "bot_vel" :depends-on ("_package_bot_vel"))
    (:file "_package_bot_vel" :depends-on ("_package"))
    (:file "wheel_vel" :depends-on ("_package_wheel_vel"))
    (:file "_package_wheel_vel" :depends-on ("_package"))
  ))