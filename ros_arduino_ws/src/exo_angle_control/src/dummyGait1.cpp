#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/ExoAngle.h"
#include "exo_angle_control/ExoAngleChange.h"
#include "exo_angle_control/EncoderKL.h"
#include "exo_angle_control/EncoderHL.h"
#include <sstream>

int angleKL = 0;
int angleHL = 0;
void KLEncoderCallback(const exo_angle_control::EncoderKL &msg)
{
    angleKL = msg.angle;
}
void HLEncoderCallback(const exo_angle_control::EncoderHL &msg)
{
    angleHL = msg.angle;
}
int main(int argc, char **argv)
{

    ros::init(argc, argv, "dummyGait");
    ros::NodeHandle n;

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1000);

    ros::Subscriber encoder_sub_hip = n.subscribe("updateHLTopic", 1000, HLEncoderCallback);
    ros::Subscriber encoder_sub_knee = n.subscribe("updateKLTopic", 1000, KLEncoderCallback);

    ros::Rate loop_rate(100);

    exo_angle_control::ExoAngle desired_angle;

    ros::Time start_time = ros::Time::now();
    ros::Time end_time = ros::Time::now();

    ros::Duration duration = end_time - start_time;

    // wait for 5 sec
    while (ros::ok() && duration.toSec() < 5)
    {
        ros::spinOnce();
        loop_rate.sleep();

        end_time = ros::Time::now();
        duration = end_time - start_time;
    }

    // initial config
    while (ros::ok() && duration.toSec() < 5)
    {
        desired_angle.kneeLeft = 0;
        desired_angle.hipLeft = 0;
        desired_angle.hipRight = 70;
        desired_angle.kneeRight = 70;
        angle_pub.publish(desired_angle);

        ros::spinOnce();
        loop_rate.sleep();

        end_time = ros::Time::now();
        duration = end_time - start_time;
    }

    // forward +ve
    // backward -ve
    while (ros::ok())
    {
        start_time = ros::Time::now();
        end_time = ros::Time::now();
        duration = end_time - start_time;

        while (ros::ok() && (duration.toSec() < 5))
        {
            desired_angle.kneeLeft = 280;
            desired_angle.hipLeft = 280 ;

            desired_angle.hipRight = 0;
            desired_angle.kneeRight = 0;

            angle_pub.publish(desired_angle);

            ros::spinOnce();
            loop_rate.sleep();

            end_time = ros::Time::now();
            duration = end_time - start_time;
        }

        start_time = ros::Time::now();
        end_time = ros::Time::now();

        duration = end_time - start_time;

        while (ros::ok() && (duration.toSec() < 5))
        {

            desired_angle.kneeLeft = 0;
            desired_angle.hipLeft = 0;

            desired_angle.hipRight = 70;
            desired_angle.kneeRight = 70;

            angle_pub.publish(desired_angle);

            ros::spinOnce();
            loop_rate.sleep();

            end_time = ros::Time::now();
            duration = end_time - start_time;
        }

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}