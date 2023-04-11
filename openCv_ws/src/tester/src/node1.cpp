#include "ros/ros.h"

int main(int argc, char **argv)
{
    // general
    ros::init(argc, argv, "node1");

    ros::NodeHandle n;

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}