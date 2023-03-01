#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/EncoderKL.h"
#include "exo_angle_control/EncoderHL.h"
#include <sstream>
#include <algorithm>

float old_HL_angle = 0, new_HL_angle = 0;
float old_KL_angle = 0, new_KL_angle = 0;
float speed_KL = 0, speed_HL = 0;
float max_speed_KL = 0, max_speed_HL = 0;
void HLCallback(const exo_angle_control::EncoderHL &HL)
{
    new_HL_angle = HL.angle;
}
void KLCallback(const exo_angle_control::EncoderKL &KL)
{
    new_KL_angle = KL.angle;
}

int main(int argc, char **argv)
{
    // general
    ros::init(argc, argv, "angleUpdate");

    ros::NodeHandle n;

    // subscriber
    ros::Subscriber HLsub = n.subscribe("KLTopic", 1000, HLCallback);
    ros::Subscriber KLsub = n.subscribe("HLTopic", 1000, KLCallback);

    // genreal
    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ros::Time start_time = ros::Time::now();

        ros::spinOnce();

        loop_rate.sleep();

        ros::Time end_time = ros::Time::now();
        ros::Duration duration = end_time - start_time;
        

        speed_HL = (old_HL_angle - new_HL_angle)/duration.toSec();
        speed_KL = (old_KL_angle - new_KL_angle)/duration.toSec();
        max_speed_HL = std::max(speed_HL,max_speed_HL);
        max_speed_KL = std::max(speed_KL,max_speed_KL);
        
        ROS_INFO("KL: %.3f || HL: %.3f", max_speed_KL,max_speed_HL);
        
    }

    return 0;
}