cmake_minimum_required(VERSION 3.0.2)
project(exo_angle_control)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  roslaunch
  controller_manager
  hardware_interface
)

roslaunch_add_file_check(launch)

add_message_files(
  FILES
  ExoAngle.msg
  ExoAngleChange.msg  
  EncoderHL.msg
  EncoderHR.msg
  EncoderKL.msg
  EncoderKR.msg
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
target_link_libraries(anglePublusher ${catkin_LIBRARIES} )
add_dependencies(anglePublusher exo_angle_control)

add_executable(anglePubSub src/anglePubSub.cpp)
target_link_libraries(anglePubSub ${catkin_LIBRARIES} )
add_dependencies(anglePubSub exo_angle_control)

add_executable(speedTest src/speedTest.cpp)
target_link_libraries(speedTest ${catkin_LIBRARIES} )
add_dependencies(speedTest exo_angle_control)

add_executable(dummyGait src/dummyGait.cpp)
target_link_libraries(dummyGait ${catkin_LIBRARIES} )
add_dependencies(dummyGait exo_angle_control)

add_executable(dummyGait1 src/dummyGait1.cpp)
target_link_libraries(dummyGait1 ${catkin_LIBRARIES} )
add_dependencies(dummyGait1 exo_angle_control)

add_executable(servoHardwareInterface src/servoHardwareInterface.cpp)
target_link_libraries(servoHardwareInterface ${catkin_LIBRARIES} )
add_dependencies(servoHardwareInterface exo_angle_control)
