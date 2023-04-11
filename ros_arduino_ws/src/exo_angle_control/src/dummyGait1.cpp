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
#include "stewart_msg/xyz.h"
/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
std::vector<int> angleEnc = {0, 0, 0, 0};
std::vector<int> desiredAngle = {0, 0, 0, 0};
std::vector<std::vector<int>> angleV = {
    {332, 332, 355, 355}, // Initial contact
    {335, 335, 340, 340}, // Loading response
    {350, 350, 353, 353}, // Midstance
    {346, 346, 358, 358}, // Terminal stance
    {342, 342, 7, 7},     // Pre-swing
    {337, 337, 40, 40},   // Initial swing
    {332, 332, 50, 50},   // Mid-swing
    {336, 336, 30, 30}    // Terminal swing
};
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

bool angleDiffCalc()
{
    ROS_INFO("%i,%i,%i,%i : %i,%i,%i,%i : : %i,%i,%i,%i",
             angleEnc[0], angleEnc[1], angleEnc[2], angleEnc[3],
             desiredAngle[0], desiredAngle[1], desiredAngle[2], desiredAngle[3],
             angleEnc[0]-desiredAngle[0], angleEnc[1]-desiredAngle[1], angleEnc[2]-desiredAngle[2], angleEnc[3]-desiredAngle[3]);
    for (int i = 0; i < 3; i++)
        if (abs(angleEnc[i] - desiredAngle[i]) > 10 && abs(angleEnc[i] - desiredAngle[i]) < 350 )
            return false;
            // ROS_INFO("in here");
    return true;
}

void updatePhase()
{
    if (angleDiffCalc())
    {
        if (phase == 7)
            phase = 0;
        else
            phase++;
    }
    desiredAngle = angleV[phase];
}

void UpdateDesiredAngle()
{
    desired_angle.hipLeft = desiredAngle[0];
    desired_angle.hipRight = desiredAngle[1];
    desired_angle.kneeLeft = desiredAngle[2];
    desired_angle.kneeRight = desiredAngle[3];
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "dummyGiat");
    ros::NodeHandle n;
    // ROS_INFO("namespace");

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);
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
        // ROS_INFO("%i, %i, %i, %i, Phase : %i", angleEnc[0], angleEnc[1], angleEnc[2], angleEnc[3], phase);
        updatePhase();
        // publish deisred angle
        UpdateDesiredAngle();
        angle_pub.publish(desired_angle);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
