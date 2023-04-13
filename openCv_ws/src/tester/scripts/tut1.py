import cv2
import sys
import numpy as np
import os
from images import tones,tree, lines
my_img = np.copy(tones)

def nothing(x):
    pass

cv2.namedWindow("erode")
cv2.createTrackbar("val","erode",1,10,nothing) 
cv2.imshow("img",my_img) 
erode = cv2.erode(my_img,(3,3))
cv2.waitKey(0)
while True:
    cv2.imshow("erode",erode)

    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break
    k_size = cv2.getTrackbarPos('val','erode')
    k_size_odd = (k_size*2) + 1
    print(k_size_odd)
    erode = cv2.erode(erode,(k_size_odd,k_size_odd))
cv2.destroyAllWindows()

