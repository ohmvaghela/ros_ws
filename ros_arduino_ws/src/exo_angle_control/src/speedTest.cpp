#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/ExoAngle.h"
#include "exo_angle_control/EncoderHL.h"

#include "exo_angle_control/ExoAngleChange.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */

int hipLeft =   0;
int hipLeftOld = 0;
int hipLeftNew = 0;

void chatterCallback(const exo_angle_control::EncoderHL &msg)
{
    // ROS_INFO("%i", msg.angle);
    hipLeft = msg.angle;
}

int main(int argc, char **argv)
{
    // general
    ros::init(argc, argv, "speedTest");

    ros::NodeHandle n;

    // time
    float speed = 0;


    // subscriber
    ros::Subscriber sub = n.subscribe("updateHLTopic", 1000, chatterCallback);

    // genreal
    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        ros::Time start_time = ros::Time::now();
        hipLeftNew = hipLeft;
        // do some work...
        ros::spinOnce();
        loop_rate.sleep();

        ros::Time end_time = ros::Time::now();
        ros::Duration duration = end_time - start_time;
        speed = (hipLeftOld-hipLeftNew)/duration.toSec();
        hipLeftOld = hipLeftNew;
        ROS_INFO("Speed: %.3f | Time : %.3f | HipAngle : %i", speed,start_time.toSec(),hipLeft);


    }

    return 0;
}

























