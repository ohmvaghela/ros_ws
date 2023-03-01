
(cl:in-package :asdf)

(defsystem "exo_angle_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ExoAngle" :depends-on ("_package_ExoAngle"))
    (:file "_package_ExoAngle" :depends-on ("_package"))
    (:file "ExoAngle" :depends-on ("_package_ExoAngle"))
    (:file "_package_ExoAngle" :depends-on ("_package"))
    (:file "ExoAngleChange" :depends-on ("_package_ExoAngleChange"))
    (:file "_package_ExoAngleChange" :depends-on ("_package"))
    (:file "ExoAngleChange" :depends-on ("_package_ExoAngleChange"))
    (:file "_package_ExoAngleChange" :depends-on ("_package"))
  ))