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








// [ INFO] [1677734966.598460051]: 316
// [ INFO] [1677734966.598752564]: 315
// [ INFO] [1677734966.599079204]: 314
// [ INFO] [1677734966.599393414]: 313
// [ INFO] [1677734966.599613071]: 312
// [ INFO] [1677734966.599894727]: 311
// [ INFO] [1677734966.600193439]: 310
// [ INFO] [1677734967.597251212]: 309
// [ INFO] [1677734967.597577309]: 308
// [ INFO] [1677734967.597808353]: 307
// [ INFO] [1677734967.598045708]: 306
// [ INFO] [1677734967.598268877]: 305
// [ INFO] [1677734967.598683418]: 304
// [ INFO] [1677734968.598154639]: 303
// [ INFO] [1677734968.598357486]: 302
// [ INFO] [1677734968.598670036]: 301
// [ INFO] [1677734968.598920683]: 300
// [ INFO] [1677734968.599186285]: 299
// [ INFO] [1677734968.599475698]: 298
// [ INFO] [1677734968.599673140]: 297
// [ INFO] [1677734969.601141454]: 296
// [ INFO] [1677734969.601602765]: 295
// [ INFO] [1677734969.601921887]: 294
// [ INFO] [1677734969.602172040]: 293
// [ INFO] [1677734969.602459078]: 292
// [ INFO] [1677734969.602785068]: 291
// [ INFO] [1677734970.598548995]: 290
// [ INFO] [1677734970.599145618]: 289
// [ INFO] [1677734970.599454987]: 288
// [ INFO] [1677734970.599722251]: 287
// [ INFO] [1677734970.600043095]: 286
// [ INFO] [1677734970.600297666]: 285
// [ INFO] [1677734971.601045278]: 280
// [ INFO] [1677734972.598577736]: 275
// [ INFO] [1677734973.597606174]: 270






















