#ifndef BLDC_ROBOT_HW_H
#define BLDC_ROBOT_HW_H

#include <hardware_interface/robot_hw.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>

class BLDCRobot : public hardware_interface::RobotHW
{
public:
  BLDCRobot();

  void read();
  void write();

  ros::Time get_time() const { return ros::Time::now(); }
  ros::Duration get_period() const { return ros::Duration(0.02); }

private:
  void send_duty_cycle_command(int motor_id, double duty_cycle);

  double joint_positions_[4];
  double joint_velocities_[4];
  double joint_efforts_[4];
  double joint_commands_[4];

  hardware_interface::JointStateInterface joint_position_interface_;
  hardware_interface::PositionJointInterface joint_command_interface_;
};

#endif // BLDC_ROBOT_HW_H
