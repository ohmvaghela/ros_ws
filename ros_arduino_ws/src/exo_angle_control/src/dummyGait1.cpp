#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/ExoAngle.h"
#include "exo_angle_control/ExoAngleChange.h"
#include "exo_angle_control/EncoderKL.h"
#include "exo_angle_control/EncoderHL.h"
#include "exo_angle_control/EncoderKR.h"
#include "exo_angle_control/EncoderHR.h"
#include <sstream>
#include <vector>
int angleKL = 0;
int angleHL = 0;
int angleKR = 0;
int angleHR = 0;
// [hipLeft, hipRight, kneeLeft, KneeRight]
std::vector<int> angleEnc = {0, 0, 0, 0};
int phase = 0;
void KLEncoderCallback(const exo_angle_control::EncoderKL &msg)
{
    angleEnc[2] = msg.angle;
}
void HLEncoderCallback(const exo_angle_control::EncoderHL &msg)
{
    angleEnc[0] = msg.angle;
}
void KREncoderCallback(const exo_angle_control::EncoderKR &msg)
{
    angleEnc[3] = msg.angle;
}
void HREncoderCallback(const exo_angle_control::EncoderHR &msg)
{
    angleEnc[1] = msg.angle;
}
void check_fn(std::vector<int> angleCur){
    for(int i = 0;i<3;i++){
        if(abs(angleEnc[i]-angleCur[i])>3)return;
    }
    if(phase == 7) phase = 0;
    else phase++;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "dummyGait");
    ros::NodeHandle n;
    // ROS_INFO("namespace");

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);
    ros::Subscriber encoder_sub_hipL = n.subscribe("updateHLTopic", 1000, HLEncoderCallback);
    ros::Subscriber encoder_sub_kneeL = n.subscribe("updateKLTopic", 1000, KLEncoderCallback);
    ros::Subscriber encoder_sub_hipR = n.subscribe("updateHRTopic", 1000, HREncoderCallback);
    ros::Subscriber encoder_sub_kneeR = n.subscribe("updateKRTopic", 1000, KREncoderCallback);

    ros::Rate loop_rate(100);

    exo_angle_control::ExoAngle desired_angle;
    exo_angle_control::EncoderHL HL;

    ros::Time start_time = ros::Time::now();
    ros::Time end_time = ros::Time::now();

    ros::Duration duration = end_time - start_time;

    //////// Gait angles
    // [hipLeft, hipRight, kneeLeft, KneeRight]
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

    std::vector<int> angleCur = angleV[0];
    ////////////////////////

    // wait for 5 sec
    while (ros::ok() && duration.toSec() < 5)
    {

        ros::spinOnce();
        loop_rate.sleep();

        end_time = ros::Time::now();
        duration = end_time - start_time;
    }

    while(ros::ok()){
        check_fn(angleCur);
        desired_angle.hipLeft =     angleCur[0];
        desired_angle.hipRight =    angleCur[1];
        desired_angle.kneeLeft =    angleCur[2];
        desired_angle.kneeRight =   angleCur[3];
        angleCur = angleV[phase];
        angle_pub.publish(desired_angle);
    }
    return 0;
}
  