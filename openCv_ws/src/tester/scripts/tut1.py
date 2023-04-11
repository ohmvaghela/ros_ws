import cv2
import sys
import numpy as np
logo_path = "/home/exoskeleton/GitHubRepo/ros_ws/openCv_ws/src/tester/images/logo.png"
rand_path = "/home/exoskeleton/GitHubRepo/ros_ws/openCv_ws/src/tester/images/random.jpg"
cat_path =  "/home/exoskeleton/GitHubRepo/ros_ws/openCv_ws/src/tester/images/cat.jpeg"
tree_path =  "/home/exoskeleton/GitHubRepo/ros_ws/openCv_ws/src/tester/images/tree.jpg"

logo = cv2.imread(logo_path, 1)
rnad = cv2.imread(rand_path, 1)
cat = cv2.imread(cat_path,1)
tree =cv2.imread(tree_path,1)

h,w = tree.shape[:2]
tree = cv2.resize(tree,(w//3,h//3))

blur = cv2.blur(tree,(7,7))
Gblur = cv2.GaussianBlur(tree,(7,7),0,0)
BLF = cv2.bilateralFilter(tree,100,80,80)
medianBlur = cv2.medianBlur(tree,3)
cv2.imshow("cat",tree)
# cv2.imshow('blur',blur)
cv2.imshow("gausian",Gblur)
cv2.imshow("BLF",BLF)
cv2.imshow("mblur",medianBlur)

cv2.waitKey(0)
cv2.destroyAllWindows()
