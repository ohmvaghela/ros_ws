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

- edit port name in `multipleArduino.launch`
- Now run

```
roslaunch exo_angle_control multipleArduino.launch
```

# message types

- ExoAngle.msg
  - Contain 4 for each hip/knee left/right
  - All are uint_32
- ExoAngleChange.msg
  - Same as ExoAngle.msg
  - Not used anywhere as of now

#### - EncoderHL.msg : Hip Left : uint_32

#### - EncoderHR.msg : Hip Right : uint_32

#### - EncoderKL.msg : Knee Left : uint_32

#### - EncoderKR.msg : Knee Right : uint_32

# ROS control

## Controller

- joint_state_controller
  - Read joint state data : But dont know from where?
  - Publish data to `/joint_states` topic
- effort_controller : Returns current or voltage to accuator
  - Used to send effort command
  - Used when joint accepts current or voltage (DC, Stepper, ...)
  - JointPositionController, JointVelocityController : Input position and velocity ; PID controller
  - JointEffortController : Input effort ; PID has no effect
- velocity_contoller : When accuator accepts velocity
  - JointPositionController, JointVelocityController
- position_controller
- joint_trajectory_controller : Execute joint space trajectory on group of joints - Trajectories are specified as a set of waypoints to be reached - Current or voltage values are given to controller - effort_controllers, velocity_controllers, position_controllers

> These all were controller

> but there is a need of interface between controller output and hardware input

## hardware_interface

- EffortJointInterface, VelocityJointInterface, PositionJointInterface
  - Takes input from controller and provide output to actuator
  - Output may be voltage, current, position, velocity
- JointStateInterface, ImuSensorInterface
  - Takes joints state : position, velocity, effort
  - IMU : used to take IMU data

## Writing ROS control node

- Creating class

    - ```cpp
        class MyRobot:public hardware_interface::RobotHW
        {
        public:
            MyRobot() : nh_("~")// initiate nodeHandle
            { 
                // Write all interface
            }
            void update(const ros::Time& time, const ros::Duration& period)
            { 
                // Update all states
            }
        }
        ```
- Writing Constructor
    - ```cpp

        MyRobot() : nh_("~")
        { 
            // JointStateHandle is used to read the joint state(position, velocity, effort)
            // hardware_interface::JointStateHandle state_handle(name, &pos_, &vel_, &eff_); 
            // name	: The name of the joint
            // pos	: A pointer to the storage for this joint's position
            // vel	: A pointer to the storage for this joint's velocity
            // eff	: A pointer to the storage for this joint's effort (force or torque)

            hardware_interface::JointStateHandle state_handle("motor_joint", &pos_, &vel_, &eff_);
            
            // Hardware interface to support reading the state of an array of joints.
            hardware_interface::JointStateInterface jnt_state_interface_;
            jnt_state_interface_.registerHandle(state_handle);

            // JointHandle used to read and command a single joint
            // 
            hardware_interface::PositionJointInterface jnt_pos_interface_;
            hardware_interface::JointHandle pos_handle(jnt_state_interface_.getHandle("motor_joint"), &cmd_);
            jnt_pos_interface_.registerHandle(pos_handle);

            registerInterface(&jnt_state_interface_);
            registerInterface(&jnt_pos_interface_);

            motor_controller_.init();
            encoder_.init();
            nh_.param<double>("gear_ratio", gear_ratio_, 1.0);

        }


        ```

- Read, Write and update functions
    - The update function is called in certain intervals of time
    - Read and write are called in it
    - Read : reads the data from micronctoller(arduino)
    - Write : Sends the data to micronctoller(arduino)
    - Update
        - ```cpp
            void MyRobot::update(const ros::TimerEvent& e) {
                elapsed_time_ = ros::Duration(e.current_real - e.last_real);
                read();
                controller_manager_->update(ros::Time::now(), elapsed_time_);
                write(elapsed_time_);
            }
            ```
    - Read
        - ```cpp
            void MyRobot::read() {​
            pos_ = // get value by subscribe, client server, action
            vel_ = // get value by subscribe, client server, action

            // Write the protocol (I2C/CAN/ros_serial/ros_industrial)used to get the current joint position and/or velocity and/or effort       

            //from robot.
            // and fill JointStateHandle variables joint_position_[i], joint_velocity_[i] and joint_effort_[i]

            }
            ```
    - Write
        - ```cpp
            void MyRobot::write(ros::Duration elapsed_time) {
            // Safety
            effortJointSaturationInterface.enforceLimits(elapsed_time);   // enforce limits for JointA and JointB
            positionJointSaturationInterface.enforceLimits(elapsed_time); // enforce limits for JointC

            // publish data to a topic to which arduino subscribe

            // Write the protocol (I2C/CAN/ros_serial/ros_industrial)used to send the commands to the robot's actuators.
            // the output commands need to send are joint_effort_command_[0] for JointA, joint_effort_command_[1] for JointB and 

            //joint_position_command_ for JointC.

            }
            ```

## Controller.yaml

```yaml
my_joint_control:
    joints_update:
        type: joint_state_controller/JointStateController
        publish_rate: 50

    joint1_position_controller:
        type: effort_controlers/JointPositionController
        joint: joint1 # Joint name
        pid: {p:12, i:12, d:12}
```

## launch file 
```xml

<launch>

    <rosparam file="$(find package_name)/config/controller.yaml" command="load"/>
    <rosparam file="$(find package_name)/config/limits.yaml" command="load"/>

    <node name="hardware_inteface_node" pkg="pkg_name" type="file_name_in_CMakeList.txt" output="screen"/>

    <node name="controller_spawner" pkg="controller_manager" type="spawner" respawn="false" 
        args="
            /my_joint_control/joint_update
            /my_joint_control/joint1_position_controller
        "
    />
</launch>

```