# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "exo_angle_control: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iexo_angle_control:/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Iexo_angle_control:/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(exo_angle_control_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg" NAME_WE)
add_custom_target(_exo_angle_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "exo_angle_control" "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(exo_angle_control
  "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exo_angle_control
)

### Generating Services

### Generating Module File
_generate_module_cpp(exo_angle_control
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exo_angle_control
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(exo_angle_control_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(exo_angle_control_generate_messages exo_angle_control_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg" NAME_WE)
add_dependencies(exo_angle_control_generate_messages_cpp _exo_angle_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exo_angle_control_gencpp)
add_dependencies(exo_angle_control_gencpp exo_angle_control_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exo_angle_control_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(exo_angle_control
  "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exo_angle_control
)

### Generating Services

### Generating Module File
_generate_module_eus(exo_angle_control
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exo_angle_control
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(exo_angle_control_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(exo_angle_control_generate_messages exo_angle_control_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg" NAME_WE)
add_dependencies(exo_angle_control_generate_messages_eus _exo_angle_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exo_angle_control_geneus)
add_dependencies(exo_angle_control_geneus exo_angle_control_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exo_angle_control_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(exo_angle_control
  "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exo_angle_control
)

### Generating Services

### Generating Module File
_generate_module_lisp(exo_angle_control
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exo_angle_control
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(exo_angle_control_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(exo_angle_control_generate_messages exo_angle_control_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg" NAME_WE)
add_dependencies(exo_angle_control_generate_messages_lisp _exo_angle_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exo_angle_control_genlisp)
add_dependencies(exo_angle_control_genlisp exo_angle_control_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exo_angle_control_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(exo_angle_control
  "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exo_angle_control
)

### Generating Services

### Generating Module File
_generate_module_nodejs(exo_angle_control
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exo_angle_control
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(exo_angle_control_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(exo_angle_control_generate_messages exo_angle_control_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg" NAME_WE)
add_dependencies(exo_angle_control_generate_messages_nodejs _exo_angle_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exo_angle_control_gennodejs)
add_dependencies(exo_angle_control_gennodejs exo_angle_control_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exo_angle_control_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(exo_angle_control
  "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exo_angle_control
)

### Generating Services

### Generating Module File
_generate_module_py(exo_angle_control
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exo_angle_control
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(exo_angle_control_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(exo_angle_control_generate_messages exo_angle_control_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ohm/GithubRepos/ros_ws/ros_arduino_ws/src/exo_angle_control/msg/ExoAngle.msg" NAME_WE)
add_dependencies(exo_angle_control_generate_messages_py _exo_angle_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(exo_angle_control_genpy)
add_dependencies(exo_angle_control_genpy exo_angle_control_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS exo_angle_control_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exo_angle_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/exo_angle_control
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(exo_angle_control_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET exo_angle_control_generate_messages_cpp)
  add_dependencies(exo_angle_control_generate_messages_cpp exo_angle_control_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exo_angle_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/exo_angle_control
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(exo_angle_control_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET exo_angle_control_generate_messages_eus)
  add_dependencies(exo_angle_control_generate_messages_eus exo_angle_control_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exo_angle_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/exo_angle_control
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(exo_angle_control_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET exo_angle_control_generate_messages_lisp)
  add_dependencies(exo_angle_control_generate_messages_lisp exo_angle_control_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exo_angle_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/exo_angle_control
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(exo_angle_control_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET exo_angle_control_generate_messages_nodejs)
  add_dependencies(exo_angle_control_generate_messages_nodejs exo_angle_control_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exo_angle_control)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exo_angle_control\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/exo_angle_control
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(exo_angle_control_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET exo_angle_control_generate_messages_py)
  add_dependencies(exo_angle_control_generate_messages_py exo_angle_control_generate_messages_py)
endif()
