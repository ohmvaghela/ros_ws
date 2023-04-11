#include <ros/ros.h>
#include <ros/console.h>
#include <std_msgs/Float64.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include "exo_angle_control/ExoAngle.h"


class BLDCmotor
{
public:
    BLDCmotor()
    {
        joint_state_interface.registerHandle(hardware_interface::JointStateHandle("BLDC_joint", &pos, &vel));
        joint_vel_interface.registerHandle(hardware_interface::JointHandle(joint_vel_interface.getHandle("BLDC_joint"), &cmd));
        registerInterface(&joint_state_interface);
        registerInterface(&joint_vel_interface);
    }

    void write()
    {
        des_angles.hipLeft = pos;
        // des_angles.hipRight = 0;
        // des_angles.kneeLeft = 0;
        // des_angles.kneeRight = 0;
        angle_pub.publish(des_angles);

        // Send command to the BLDC motor
        // Use the cmd variable to control the BLDC
    }

private:
    hardware_interface::JointStateInterface joint_state_interface;
    hardware_interface::VelocityJointInterface joint_vel_interface;
    double cmd = 0.0;
    double pos = 0.0;
    double vel = 0.0;
    // double eff = 0.0;
    exo_angle_control::ExoAngle des_angles;
    des_angles.hipLeft = 0;
    des_angles.hipRight = 0;
    des_angles.kneeLeft = 0;
    des_angles.kneeRight = 0;

};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "BLDC_controller");
    ros::NodeHandle n;

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);

    BLDCmotor BLDC_motor;
    controller_manager::ControllerManager cm(&BLDC_motor);

    ros::AsyncSpinner spinner(1);
    spinner.start();

    ros::Rate rate(50);
    ros::Time prev_time = ros::Time::now();

    while (ros::ok())
    {
        const ros::Time time = ros::Time::now();
        const ros::Duration period = time - prev_time;
        prev_time = time;

        BLDC_motor.write();
        cm.update(time, period);

        rate.sleep();
    }

    return 0;
}





































