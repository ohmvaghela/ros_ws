import cv2
import sys
import numpy as np
logo_path = "/home/ohm/GitRepo/ros_ws/openCv_ws/src/tester/images/logo.png"
rand_path = "/home/ohm/GitRepo/ros_ws/openCv_ws/src/tester/images/random.jpg"
logo = cv2.imread(logo_path, 1)
rnad = cv2.imread(rand_path, 1)
W=480
thickness = 2
line_type = 8
cv2.circle(logo,(300,300),100,(0,0,0),15,lineType=cv2.FILLED)
blend1 = cv2.addWeighted(logo, 0.5, rnad, 0.4, -25)
blend2 = cv2.addWeighted(logo, 0.5, rnad, 0.4, 10)
cv2.putText(logo,"ohm vaghela",(100,600),cv2.FONT_HERSHEY_TRIPLEX,2,(0,0,0),2,cv2.LINE_4)
cv2.imshow('logo',logo)
# cv2.imshow('RANd',rnad)
# cv2.imshow('blend1', blend1)
# cv2.imshow('blend2', blend2)


cv2.waitKey(0)
cv2.destroyAllWindows()
