#include <ros/ros.h>
#include <hardware_interface/robot_hw.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
// #include "bldc_robot_hw.h"
#include <controller_manager/controller_manager.h>

#include "exo_angle_control/EncoderHL.h"
#include "exo_angle_control/EncoderKL.h"
#include "exo_angle_control/EncoderKR.h"
#include "exo_angle_control/EncoderHR.h"
#include "exo_angle_control/ExoAngle.h"

class BLDCRobot : public hardware_interface::RobotHW
{
public:
  BLDCRobot()
  {
    // Initialize joint state interfaces
    for (int i = 0; i < 4; ++i)
    {
      joint_positions_[i] = 0.0;
      joint_velocities_[i] = 0.0;
      joint_efforts_[i] = 0.0;
      joint_position_interface_.registerHandle(hardware_interface::JointHandle(
          "bldc_joint_" + std::to_string(i),
          &joint_positions_[i]));
    }
    registerInterface(&joint_position_interface_);

    // Initialize joint command interfaces
    for (int i = 0; i < 4; ++i)
    {
      joint_commands_[i] = 0.0;
      joint_command_interface_.registerHandle(hardware_interface::JointHandle(
          "bldc_joint_" + std::to_string(i),
          &joint_commands_[i]));
    }
    registerInterface(&joint_command_interface_);
  }
  void hlCallback(const exo_angle_control::EncoderHL::ConstPtr &msg) {hl_angle_ = msg->angle;}
  void klCallback(const exo_angle_control::EncoderKL::ConstPtr &msg) {kl_angle_ = msg->angle;}
  void krCallback(const exo_angle_control::EncoderKR::ConstPtr &msg) {kr_angle_ = msg->angle;}
  void hrCallback(const exo_angle_control::EncoderHR::ConstPtr &msg) {hr_angle_ = msg->angle;}

  void read(ros::Time time, ros::Duration period) {ros::spinOnce();}
  // Send duty cycle command to the motor driver
  // The duty cycle value should be between -1.0 and 1.0
  void write() 
  {
    for (int i = 0; i < 4; ++i)
      send_duty_cycle_command(i, joint_commands_[i]);
  }
  

  void send_duty_cycle_command()
  {
    exo_angle_control::ExoAngle msg;
    msg.hipLeft = hip_left_duty_cycle_;
    msg.hipRight = hip_right_duty_cycle_;
    msg.kneeLeft = knee_left_duty_cycle_;
    msg.kneeRight = knee_right_duty_cycle_;
    desired_angle_pub_.publish(msg);
  }
  ros::Publisher desired_angle_pub_;

private:
  double hip_left_duty_cycle_;
  double hip_right_duty_cycle_;
  double knee_left_duty_cycle_;
  double knee_right_duty_cycle_;

  // Publisher for the desired angle message
  uint32_t hl_angle_;
  uint32_t kl_angle_;
  uint32_t kr_angle_;
  uint32_t hr_angle_;
  double joint_positions_[4];
  double joint_velocities_[4];
  double joint_efforts_[4];
  double joint_commands_[4];

  hardware_interface::JointStateInterface joint_position_interface_;
  hardware_interface::PositionJointInterface joint_command_interface_;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "bldc_robot_hw_interface");
  ros::NodeHandle nh;

  BLDCRobot robot;
  robot.desired_angle_pub_ = nh.advertise<exo_angle_control::ExoAngle>("desiredAngleTopic", 1);

  // Register the hardware interface with the controller manager
  hardware_interface::RobotHW *robot_ptr = &robot;
  controller_manager::ControllerManager cm(robot_ptr, nh);
  cm.loadController("my_controller");
  cm.switchController("my_controller");

  ros::Rate loop_rate(50);
  while (ros::ok())
  {
    robot.read();
    cm.update(ros::Time::now(), ros::Duration(0.02));
    robot.write();
    loop_rate.sleep();
  }

  return 0;
}
