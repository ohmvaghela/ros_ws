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
exo_angle_control::ExoAngle desired_angle;
int phase = 0; // max 7

int angleKL = 0;
int angleHL = 0;
int angleKR = 0;
int angleHR = 0;
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

void UpdateDesiredAngle(int phase)
{
    if (phase == 1)
    {
        desired_angle.hipLeft = 20;
        desired_angle.hipRight = 20;
        desired_angle.kneeLeft = 20;
        desired_angle.kneeRight = 20;
    }
    if (phase == 2)
    {
        desired_angle.hipLeft = 340;
        desired_angle.hipRight = 340;
        desired_angle.kneeLeft = 340;
        desired_angle.kneeRight = 340;
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "dummyGiat");
    ros::NodeHandle n;
    // ROS_INFO("namespace");

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);
    // ros::Subscriber encoder_sub_hipL = n.subscribe("updateHLTopic", 1000, HLEncoderCallback);
    // ros::Subscriber encoder_sub_kneeL = n.subscribe("updateKLTopic", 1000, KLEncoderCallback);
    // ros::Subscriber encoder_sub_hipR = n.subscribe("updateHRTopic", 1000, HREncoderCallback);
    // ros::Subscriber encoder_sub_kneeR = n.subscribe("updateKRTopic", 1000, KREncoderCallback);

    ros::Rate loop_rate(100);

    ros::Time start_time = ros::Time::now();
    ros::Time end_time = ros::Time::now();
    ros::Duration duration = end_time - start_time;

    while (ros::ok())
    {
        while (ros::ok() && (duration.toSec() < 3))
        {

            UpdateDesiredAngle(1);
            angle_pub.publish(desired_angle);
            ROS_INFO("1 : %f", duration.toSec());
            end_time = ros::Time::now();
            duration = end_time - start_time;

            ros::spinOnce();
            loop_rate.sleep();
        }
        start_time = ros::Time::now();
        duration = end_time - start_time;

        while (ros::ok() && (duration.toSec() < 3))
        {
            UpdateDesiredAngle(2);
            angle_pub.publish(desired_angle);
            ROS_INFO("2: %f", duration.toSec());
            end_time = ros::Time::now();
            duration = end_time - start_time;

            ros::spinOnce();
            loop_rate.sleep();
        }
        start_time = ros::Time::now();
        duration = end_time - start_time;
    }
    return 0;
}
