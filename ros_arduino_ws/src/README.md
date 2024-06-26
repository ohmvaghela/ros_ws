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
- 1st way go to arduio libaray folder
    - Make sure to source both terminal 
    1. roscore terminal 
    2. in which you will run following code
``` 
rosrun rosserial_arduino make_libraries.py ./
```

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

## first way
- Edit the port in launch file and then run following command
```
roslaunch exo_angle_control oneArduino.launch
```

## Sercond way
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


# For all motors
- edit port name in  `oneArduino.launch`
- Now run 
```
roslaunch exo_angle_control oneArduino.launch
```

# message types
- ExoAngle.msg
    - Contain 4 for each hip/knee left/right
    - All are uint_32
- ExoAngleChange.msg 
    - Same as ExoAngle.msg
    - Not used anywhere as of now
### - EncoderHL.msg : Hip Left   : uint_32
### - EncoderHR.msg : Hip Right  : uint_32 
### - EncoderKL.msg : Knee Left  : uint_32 
### - EncoderKR.msg : Knee Right : uint_32  
 
