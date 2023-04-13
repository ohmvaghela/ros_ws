import cv2
import os
logo_path = os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/logo.png")
rand_path = os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/random.jpg")
cat_path =  os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/cat.jpeg")
tree_path =  os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/tree.jpg")
noisy_path =  os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/Noisy_image.png")
lines_path =  os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/lines.jpg")
lines1_path =  os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/lines1.jpg")
tones_path =  os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/tones.png")
color_balls_path =  os.path.join(os.environ['GIT_REPO_PATH'], "ros_ws/openCv_ws/src/tester/images/color_balls.webp")


logo = cv2.imread(logo_path, 1)
rnad = cv2.imread(rand_path, 1)
cat = cv2.imread(cat_path,1)
tree =cv2.imread(tree_path,1)
noisy = cv2.imread(noisy_path,1)
lines = cv2.imread(lines_path,1)
lines1 = cv2.imread(lines1_path,1)
tones = cv2.imread(tones_path,1)
color_balls = cv2.imread(color_balls_path,1)

