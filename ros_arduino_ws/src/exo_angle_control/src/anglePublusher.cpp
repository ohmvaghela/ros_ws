#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/ExoAngle.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
    ros::init(argc, argv, "angleUpdate");

    ros::NodeHandle n;

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);

    ros::Rate loop_rate(10);

    int hipLeft = 50;
    int hipRight = 50;
    int kneeLeft = 50;
    int kneeRight = 50;

    while (ros::ok())
    {
        // angle
        // msg_tester::Angle pub_angle;
        // pub_angle.des_angle = cur_angle;
        // angle_pub.publish(pub_angle);
        // ROS_INFO("%i", pub_angle.des_angle);

        exo_angle_control::ExoAngle des_angles;
        
        des_angles.hipLeft = hipLeft;
        des_angles.hipRight = hipRight;
        des_angles.kneeLeft = kneeLeft;
        des_angles.kneeRight = kneeRight;

        angle_pub.publish(des_angles);
        ROS_INFO("%i | %i | %i | %i ", des_angles.hipLeft, des_angles.hipRight, des_angles.kneeLeft,
                 des_angles.kneeRight);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}