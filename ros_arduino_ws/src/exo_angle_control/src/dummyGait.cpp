#include "ros/ros.h"
#include "std_msgs/String.h"
#include "exo_angle_control/ExoAngle.h"
#include "exo_angle_control/ExoAngleChange.h"
#include "exo_angle_control/EncoderKL.h"
#include <sstream>

int angleKL = 0;

void EncoderCallback(const exo_angle_control::EncoderKL &msg)
{
   angleKL = msg.angle; 
}

int main(int argc, char **argv){

    ros::init(argc,argv,"dummyGait");
    ros::NodeHandle n;

    ros::Publisher angle_pub = n.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic",1000);

    ros::Subscriber encoder_sub = n.subscribe("updateHLTopic",1000,EncoderCallback);

    ros::Rate loop_rate(100);

    // code for all phases for knee
    // for hip make 2 condition 
        // if it reached forward at max then stop till knee complete its phases
        // then make hip move backwards and same

    //////////////////////////////////////////////
    // first test it manually by moving it by hand
    //////////////////////////////////////////////

    while(ros::ok())
    {
        // knee phase 1
        while(ros::ok() /* && condition1*/)
        {
            // code here

            // publish hip angle for backmost position
            ros::spinOnce();
            loop_rate.sleep();
        }
        // knee phase 2
        while(ros::ok() /* && condition2*/)
        {
            // code here

            // publish hip angle for backmost position
            ros::spinOnce();
            loop_rate.sleep();

        }

        // .
        // .
        // .


        // knee phase n
        while(ros::ok() /* && condition n*/)
        {
            // code here

            // publish hip angle for forward position
            ros::spinOnce();
            loop_rate.sleep();

        }

    } 
    return 0;
}