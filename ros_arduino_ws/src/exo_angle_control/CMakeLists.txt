cmake_minimum_required(VERSION 3.0.2)
project(exo_angle_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(
  FILES
  ExoAngle.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  exo_angle_control
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES exo_angle_control
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

# foreach(dir config)
# 	install(DIRECTORY ${dir}/
# 		DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/${dir})
# endforeach(dir)

include_directories(

  ${catkin_INCLUDE_DIRS}
)

add_executable(anglePublusher src/anglePublusher.cpp)
target_link_libraries(anglePublusher ${catkin_LIBRARIES})
add_dependencies(anglePublusher exo_angle_control)