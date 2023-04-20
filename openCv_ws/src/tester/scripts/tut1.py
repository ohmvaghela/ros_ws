import cv2
import sys
import numpy as np
import os
from images import tones,tree, lines,color_balls

def singleDigit(x):
    temp = 0
    while True:
        while(x!=0):
            temp = temp + x%10 # 8
            x = x//10 # 4
        if(temp<10): return temp
        x = temp
        temp = 0
    
    
digit = 45
# singleDigit(digit)
print(singleDigit(digit))

