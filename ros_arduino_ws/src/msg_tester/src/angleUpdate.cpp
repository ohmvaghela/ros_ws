#include "ros/ros.h"
#include "std_msgs/String.h"
#include "msg_tester/Angle.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "angleUpdate");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher angle_pub = n.advertise<msg_tester::Angle>("angular", 1000);

  ros::Rate loop_rate(100);

  int32_t cur_angle = 1;
  int32_t count = 0;
  while (ros::ok())
  {
    // String
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
   
    // angle
    msg_tester::Angle pub_angle;
    pub_angle.des_angle = cur_angle;
    angle_pub.publish(pub_angle);
    ROS_INFO("%i", pub_angle.des_angle);


    ros::spinOnce();

    loop_rate.sleep();
    ++count;

    ++cur_angle;
  }

  return 0;
}