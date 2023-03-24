#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/ExoAngle.h"
#include "exo_angle_control/ExoAngleChange.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */

int hipLeft = 0;
int hipRight = 0;
int kneeLeft = 0;
int kneeRight = 0;

void chatterCallback(const exo_angle_control::ExoAngleChange &msg)
{
    ROS_INFO("I heard: [%i], [%i], [%i], [%i]", msg.hipLeft, msg.kneeRight, msg.kneeRight, msg.hipRight);
    hipLeft = msg.hipLeft;
    hipRight = msg.hipRight;
    kneeLeft = msg.kneeLeft;
    kneeRight = msg.kneeRight;
}

int main(int argc, char **argv)
{
    // general
    ros::init(argc, argv, "angleUpdate");

    ros::NodeHandle n;

    // publisher
    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);

    // subscriber
    ros::Subscriber sub = n.subscribe("updateAngleTopic", 1000, chatterCallback);

    // genreal
    ros::Rate loop_rate(10);

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
        ROS_INFO("pubsub %i | %i | %i | %i ", des_angles.hipLeft, des_angles.hipRight, des_angles.kneeLeft, des_angles.kneeRight);

        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}