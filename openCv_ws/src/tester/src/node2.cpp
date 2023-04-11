#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  cv_bridge::CvImagePtr cv_ptr;
  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("cv_bridge exception: %s", e.what());
    return;
  }

  // Apply a simple filter to the image
  cv::Mat filtered;
  cv::GaussianBlur(cv_ptr->image, filtered, cv::Size(5, 5), 0);

  // Publish the filtered image to a new topic
  cv_bridge::CvImage out_msg;
  out_msg.header = msg->header;
  out_msg.encoding = sensor_msgs::image_encodings::BGR8;
  out_msg.image = filtered;
  pub.publish(out_msg.toImageMsg());
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_filter");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("image_raw", 1, imageCallback);
  ros::Publisher pub = nh.advertise<sensor_msgs::Image>("image_filtered", 1);

  ros::spin();

  return 0;
}
