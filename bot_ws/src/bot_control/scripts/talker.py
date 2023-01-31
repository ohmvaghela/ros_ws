#!/usr/bin/env python

# http://wiki.ros.org/rospy/Overview/Publishers%20and%20Subscribers

import rospy
from std_msgs.msg import String
from bot_msg.msg import wheel,bot_vel



def talker():
	pub = rospy.Publisher('chatter',wheel,queue_size=10)
	rospy.init_node('talker',anonymous=True)
	rate = rospy.Rate(1)
	wheel_vel = wheel()
	
	while not rospy.is_shutdown():
	
		wheel_vel.w1 = 2
		wheel_vel.w2 = 4
		wheel_vel.w3 = 8
		wheel_vel.w4 = 16			
		rospy.loginfo("Publishing wheel vel" )
		pub.publish(wheel_vel)
		rate.sleep()
		
if __name__ == '__main__':
	try:
		talker()
	except rospy.ROSInterruptException:
		pass 
