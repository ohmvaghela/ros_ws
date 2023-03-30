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

int hipLeft = 0;
int hipRight = 0;
int kneeLeft = 0;
int kneeRight = 0;

// std::vector<int> encoder = {0,0,0,0};// HL, HR, KL, KR
void ExoAngleCB(const exo_angle_control::ExoAngleChange &msg)
{
    hipLeft = msg.hipLeft;
    hipRight = msg.hipRight;
    kneeLeft = msg.kneeLeft;
    kneeRight = msg.kneeRight;
}

// void encoderHLCB(const exo_angle_control::EncoderKL &HL) {encoder[0] = HL.angle;}
// void encoderHRCB(const exo_angle_control::EncoderKL &HR) {encoder[1] = HR.angle;}
// void encoderKLCB(const exo_angle_control::EncoderKL &KL) {encoder[2] = KL.angle;}
// void encoderKRCB(const exo_angle_control::EncoderKL &KR) {encoder[3] = KR.angle;}

int main(int argc, char **argv)
{
    // general
    ros::init(argc, argv, "angleUpdate");

    ros::NodeHandle n;

    // publisher
    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);

    // subscriber
    ros::Subscriber sub = n.subscribe("updateAngleTopic", 1000, ExoAngleCB);

    // ros::Subscriber subHL = n.subscribe("updateHLTopic", 1000, encoderHLCB);
    // ros::Subscriber subHR = n.subscribe("updateHRTopic", 1000, encoderHRCB);
    // ros::Subscriber subKL = n.subscribe("updateKLTopic", 1000, encoderKLCB);
    // ros::Subscriber subKR = n.subscribe("updateKRTopic", 1000, encoderKRCB);

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