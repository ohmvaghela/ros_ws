#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/Float64.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include "exo_angle_control/ExoAngle.h"


class ServoMotor
{
public:
    ServoMotor()
    {
        joint_state_interface.registerHandle(hardware_interface::JointStateHandle("servo_joint", &pos, &vel, &eff));
        joint_effort_interface.registerHandle(hardware_interface::JointHandle(joint_state_interface.getHandle("servo_joint"), &cmd));
        registerInterface(&joint_state_interface);
        registerInterface(&joint_effort_interface);
    }

    void write()
    {
        des_angles.hipLeft = pos;
        des_angles.hipRight = 0;
        des_angles.kneeLeft = 0;
        des_angles.kneeRight = 0;
        angle_pub.publish(des_angles);

        // Send command to the servo motor
        // Use the cmd variable to control the servo
    }

private:
    hardware_interface::JointStateInterface joint_state_interface;
    hardware_interface::EffortJointInterface joint_effort_interface;
    double cmd = 0.0;
    double pos = 0.0;
    double vel = 0.0;
    double eff = 0.0;
    exo_angle_control::ExoAngle des_angles;
    des_angles.hipLeft = 0;
    des_angles.hipRight = 0;
    des_angles.kneeLeft = 0;
    des_angles.kneeRight = 0;

};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "servo_controller");
    ros::NodeHandle n;

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);

    ServoMotor servo_motor;
    controller_manager::ControllerManager cm(&servo_motor);

    ros::AsyncSpinner spinner(1);
    spinner.start();

    ros::Rate rate(50);
    ros::Time prev_time = ros::Time::now();

    while (ros::ok())
    {
        const ros::Time time = ros::Time::now();
        const ros::Duration period = time - prev_time;
        prev_time = time;

        servo_motor.write();
        cm.update(time, period);

        rate.sleep();
    }

    return 0;
}





































