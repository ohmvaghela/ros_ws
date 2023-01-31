cmake_minimum_required(VERSION 3.0.2)
project(msg_tester)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(
  FILES
  Angle.msg
#   Message2.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
  msg_tester
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES msg_tester
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS} )

add_executable(angleUpdate src/angleUpdate.cpp)
target_link_libraries(angleUpdate ${catkin_LIBRARIES})
add_dependencies(angleUpdate msg_tester)

add_executable(angleSubs src/angleSubs.cpp)
target_link_libraries(angleSubs ${catkin_LIBRARIES})
add_dependencies(angleSubs msg_tester)


