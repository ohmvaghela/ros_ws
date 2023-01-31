#!usr/bin/env python

import math
import rospy
from bot_msg.msg import bot_vel
from bot_msg.msg import bot_param
from bot_msg.msg import wheel_vel


class Convert_bot_vel_2_wheel_vel:
	def __inti__(self):
		pass

	def bot_vel_sub_cb(self,data):
		info1 = "Got bot's velocity \n"
		info2 = str(data)
		info = info1 + info2

		self.tlv = data.linear_vel #target_linear_velocity 
		self.trv = data.angular_vel#target_rotational_velocity
		self.deg = data.orientation#current_orientation 
		# rospy.loginfo(info)

	def bot_param_sub_cb(self,data):
		info1 = "Got bot's parameters \n"
		info2 = str(data)
		info = info1 + info2
		self.lx =  data.lx# half the distance between back wheels  
		self.r = data.radius #radius
		self.ly =  data.ly# half the distance between left wheels
		# rospy.loginfo(info)

	def bot_vel_2_wheel_vel(self):
		# rospy.loginfo("in bot_vel_2_wheel_vel")
		rospy.Subscriber('bot_2_wheels_vel_topic/bot_param',bot_param,callback=self.bot_param_sub_cb)
		rospy.Subscriber('bot_2_wheels_vel_topic/bot_vel',bot_vel,callback=self.bot_vel_sub_cb)
		# todo
		try:
			vx = self.tlv*math.cos(self.deg)
			vy = self.tlv*math.sin(self.deg)
			lxly = self.lx + self.ly
			w1 = (1/self.r) * (vx - vy - lxly*self.trv )
			w2 = (1/self.r) * (vx + vy + lxly*self.trv )
			w3 = (1/self.r) * (vx + vy - lxly*self.trv )
			w4 = (1/self.r) * (vx - vy + lxly*self.trv )
			Data = [w1,w2,w3,w4]
			return Data
		except:
			return 0
		
	def publish_2_wheels(self):
		wheel_pub = rospy.Publisher('arduino_pub',wheel_vel,queue_size=10)
		rate = rospy.Rate(10)
		while not rospy.is_shutdown():	
			Data = self.bot_vel_2_wheel_vel()
			try:
				rospy.loginfo("Wheel velocity Data recived")
				wheel_vel.w1 = Data[0]
				wheel_vel.w2 = Data[1]
				wheel_vel.w3 = Data[2]
				wheel_vel.w4 = Data[3]
				wheel_pub.publish(wheel_vel)
				rate.sleep()
			except:
				rospy.loginfo("data not recived")


if __name__=='__main__':
	
	rospy.init_node('bot_2_wheels_vel_node')
	
	get_wheel_vel_class = Convert_bot_vel_2_wheel_vel()
	get_wheel_vel_class.publish_2_wheels()

	rospy.spin()
		
	
	
