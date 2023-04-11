#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/ExoAngle.h"
#include "exo_angle_control/ExoAngleChange.h"
#include <sstream>
#include "exo_angle_control/EncoderKL.h"
#include "exo_angle_control/EncoderHL.h"
#include "exo_angle_control/EncoderKR.h"
#include "exo_angle_control/EncoderHR.h"
#include <vector>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
std::vector<int> angleEnc = {0, 0, 0, 0};
// callbacks
void KLEncoderCallback(const exo_angle_control::EncoderKL &msg)
{
    // angleKL = msg.angle;
    angleEnc[0] = msg.angle;
}
void HLEncoderCallback(const exo_angle_control::EncoderHL &msg)
{
    // angleHL = msg.angle;
    angleEnc[1] = msg.angle;
}
void KREncoderCallback(const exo_angle_control::EncoderKR &msg)
{
    // angleKR = msg.angle;
    angleEnc[2] = msg.angle;
}
void HREncoderCallback(const exo_angle_control::EncoderHR &msg)
{
    // angleHR = msg.angle;
    angleEnc[3] = msg.angle;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "encoder");
    ros::NodeHandle n;
    // ROS_INFO("namespace");

    ros::Subscriber encoder_sub_hipL = n.subscribe("updateHLTopic", 1000, HLEncoderCallback);
    ros::Subscriber encoder_sub_kneeL = n.subscribe("updateKLTopic", 1000, KLEncoderCallback);
    ros::Subscriber encoder_sub_hipR = n.subscribe("updateHRTopic", 1000, HREncoderCallback);
    ros::Subscriber encoder_sub_kneeR = n.subscribe("updateKRTopic", 1000, KREncoderCallback);

    ros::Rate loop_rate(100);

    ros::Time start_time = ros::Time::now();
    ros::Time end_time = ros::Time::now();
    ros::Duration duration = end_time - start_time;

    while (ros::ok())
    {
        // print encoder input
        ROS_INFO("%i, %i, %i, %i", angleEnc[0], angleEnc[1], angleEnc[2], angleEnc[3]);
        
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
