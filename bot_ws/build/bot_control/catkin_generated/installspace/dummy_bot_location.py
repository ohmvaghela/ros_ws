#!usr/bin/env python

import rospy
from bot_msg.msg import bot_vel,bot_param

# float32 linear_vel
# float32 angluar_vel
# float32 orientation

# float32 radius
# float32 lx
# float32 ly


def dummy_publisher():
    pub_vel = rospy.Publisher('bot_2_wheels_vel_topic/bot_vel',bot_vel,queue_size=10)
    rospy.loginfo('velocity publisher is up' )
    pub_param = rospy.Publisher('bot_2_wheels_vel_topic/bot_param',bot_param,queue_size=10)
    rospy.loginfo('parameter publisher is up' )

    rospy.init_node('dummy_bot_publisher')
    rate = rospy.Rate(10)
    bot_velocity = bot_vel()
    bot_parameters = bot_param()

    while not rospy.is_shutdown():

        bot_velocity.linear_vel = 1.01
        bot_velocity.angular_vel = 2
        bot_velocity.orientation = 0
        pub_vel.publish(bot_velocity)

        bot_parameters.radius = 0.5
        bot_parameters.lx = 0.25
        bot_parameters.ly = 0.25
        pub_param.publish(bot_parameters)
        rospy.loginfo(pub_vel)
        rospy.loginfo(pub_param)
        rate.sleep()

if __name__=='__main__':
    dummy_publisher()