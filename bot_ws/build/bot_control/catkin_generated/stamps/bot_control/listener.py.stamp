#!/usr/bin/env python

# http://wiki.ros.org/rospy/Overview/Publishers%20and%20Subscribers

import rospy
from std_msgs.msg import String
from bot_msg.msg import wheel,bot_vel

def callback(Data):
	rospy.loginfo(rospy.get_caller_id())
	rospy.loginfo(Data.w1)
	
	
def listener():
	rospy.init_node('listener', anonymous = True)
	rospy.Subscriber('chatter' , wheel , callback)
	rospy.spin()

if __name__ == '__main__':
	listener()
