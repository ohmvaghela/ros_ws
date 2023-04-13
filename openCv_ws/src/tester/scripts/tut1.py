import cv2
import sys
import numpy as np
import os
from images import tones,tree, lines,color_balls
my_img = np.copy(color_balls)
my_img = cv2.resize(my_img,(my_img.shape[1]//2,my_img.shape[0]//2))
my_img_grey = cv2.cvtColor(my_img,cv2.COLOR_BGR2GRAY)
# cv2.inRange(miaf,)

max_value = 255
max_value_H = 360//2
low_H = 100
low_S = 100
low_V = 100
high_H = max_value_H
high_S = max_value
high_V = max_value

frame = my_img
frame_HSV = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
frame_threshold = cv2.inRange(frame_HSV, (low_H, low_S, low_V), (high_H, high_S, high_V))
    
_,thresh = cv2.threshold(my_img_grey,100,255,type=cv2.THRESH_TRUNC)
cv2.imshow("img1",frame_threshold)

cv2.waitKey()
cv2.destroyAllWindows()

