cmake_minimum_required(VERSION 3.0.2)
project(tester)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)
find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tester
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}

)

add_executable(node1 src/node1.cpp)
target_link_libraries(node1
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)

add_executable(node2 src/node2.cpp)
target_link_libraries(node2
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)


install(TARGETS node1 node2
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

add_compile_definitions(HAVE_OPENCV)
add_compile_definitions(HAVE_OPENCV_CALIB3D)
add_compile_definitions(HAVE_OPENCV_CORE)
add_compile_definitions(HAVE_OPENCV_FEATURES2D)
add_compile_definitions(HAVE_OPENCV_FLANN)
add_compile_definitions(HAVE_OPENCV_HIGHGUI)
add_compile_definitions(HAVE_OPENCV_IMGCODECS)
add_compile_definitions(HAVE_OPENCV_IMGPROC)
add_compile_definitions(HAVE_OPENCV_ML)
add_compile_definitions(HAVE_OPENCV_OBJDETECT)
add_compile_definitions(HAVE_OPENCV_PHOTO)
add_compile_definitions(HAVE_OPENCV_VIDEO)
add_compile_definitions(HAVE_OPENCV_VIDEOIO)
