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
    // currently knee 0 hip 1

    // code for all phases for knee
    // for hip make 2 condition
    // if it reached forward at max then stop till knee complete its phases
    // then make hip move backwards and same

    // If hip reaches desired angle so it will stop automatically
    // as error from desired angle will be nearly zero

    //////////////////////////////////////////////
    // first test it manually by moving it by hand
    // oncorporate code for making motor move from standing position to phase 1
    // then give delay of some time and then start gait motion
    //////////////////////////////////////////////

    while (ros::ok())
    {
        // initial setting
        while (ros::ok() && (angleKL < 10) && (angleHL < 40))
        {
            // desired angle is more then required as
            // angle precision upto 3 degree
            // hence if goal if 0 to 30 degree then it will reach 27 or 28 degree

            desired_angle.hipLeft = 50;  // extra incorporated
            desired_angle.kneeLeft = 20; // extra incorporated

            angle_pub.publish(desired_angle);

            ros::spinOnce();
            loop_rate.sleep();
        }

        // knee phase 1 (0 to 25 degree)| condition hip back
        while (ros::ok() && (angleKL < 25))
        {
            desired_angle.kneeLeft = 35; // extra incorporated
            // publish hip angle for backmost position
            desired_angle.hipLeft = 340; // extra incorporated

            angle_pub.publish(desired_angle);

            ros::spinOnce();
            loop_rate.sleep();
        }

        // knee phase 2 | condition hip back
        while (ros::ok() && (angleKL > 10))
        {
            desired_angle.kneeLeft = 0;  // extra incorporated
            desired_angle.hipLeft = 340; // extra incorporated

            angle_pub.publish(desired_angle);

            // publish hip angle for backmost position
            ros::spinOnce();
            loop_rate.sleep();
        }

        // knee phase 3 & 4 | condition hip front
        while (ros::ok() && (angleKL < 75))
        {
            desired_angle.kneeLeft = 85; // extra incorporated
            desired_angle.hipLeft = 45;  // extra incorporated

            angle_pub.publish(desired_angle);

            // publish hip angle for forward position
            ros::spinOnce();
            loop_rate.sleep();
        }

        // knee phase 5 | condition hip front
        while (ros::ok() && (angleKL > 10))
        {
            // code here
            desired_angle.kneeLeft = 0; // extra incorporated
            desired_angle.hipLeft = 45; // extra incorporated

            angle_pub.publish(desired_angle);
            // publish hip angle for forward position
            ros::spinOnce();
            loop_rate.sleep();
        }

        ros::spinOnce();
        loop_rate.sleep();

    }
    return 0;
}