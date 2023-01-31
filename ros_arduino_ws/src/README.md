# Using rosserial

# Setup
- [link](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup)
- ```
    sudo apt-get install ros-${ROS_DISTRO}-rosserial-arduino
    sudo apt-get install ros-${ROS_DISTRO}-rosserial
    ```
- Create or go to workspace/src
- ```
    git clone https://github.com/ros-drivers/rosserial.git
    ```
- build package

# for using custom message 
- [link](http://wiki.ros.org/rosserial_arduino/Tutorials/Adding%20Custom%20Messages)
- Create custom message in your env
- Then run 
```
rosrun rosserial_client make_library.py path_to_libraries your_message_package
```
- If the above command does not works and while running arduino IDE it gives error so copy the file with desired package name from ros_ws/devel/include/ to ~/snap/arduino/current/Arduino/libraries/ros_lib
- Say I want to include message package exo_angle_control
- So i will copy

        ros_ws/devel/include/exo_angle_control 
- to 

        ~/snap/arduino/current/Arduino/libraries/ros_lib

# Running setup
- Start rosmaster
    ```
    roscore
    ```
- To connect ros with arduino run for each port `ACM0`,`ACM1`,`ACM2`
    ```
    rosrun rosserial_python serial_node.py /dev/ttyACM0
    ```
- Then you can run your ROS nodes as per your wish 
- For my case I am pusblising ros node `anglePublisher` of package `exo_angle_control`

- > currently setup is done 
    - > Next step is to import the `rosserial_python` package in `exo_angle_control` package so `exo_angle_control` can have common launch file 