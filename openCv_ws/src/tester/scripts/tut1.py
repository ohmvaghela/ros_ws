import cv2
import sys
import numpy as np
logo_path = "/home/ohm/GitRepo/ros_ws/openCv_ws/src/tester/images/logo.png"
rand_path = "/home/ohm/GitRepo/ros_ws/openCv_ws/src/tester/images/random.jpg"
cat_path =  "/home/ohm/GitRepo/ros_ws/openCv_ws/src/tester/images/cat.jpeg"
tree_path =  "/home/ohm/GitRepo/ros_ws/openCv_ws/src/tester/images/tree.jpg"
noisy_path =  "/home/ohm/GitRepo/ros_ws/openCv_ws/src/tester/images/Noisy_image.png"

logo = cv2.imread(logo_path, 0)
rnad = cv2.imread(rand_path, 1)
cat = cv2.imread(cat_path,1)
tree =cv2.imread(tree_path,0)

h,w = tree.shape[:2]
tree = cv2.resize(tree,(w//2,h//2))
hitmiss = cv2.morphologyEx(logo,cv2.MORPH_HITMISS,(17,17))

cv2.imshow("hitmiss",hitmiss)

cv2.waitKey(0)
cv2.destroyAllWindows()
