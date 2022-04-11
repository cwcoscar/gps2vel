#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/TwistStamped.h>


geometry_msgs::TwistStamped data;

void gps_odometry_callback(const nav_msgs::Odometry& msg)
{
    data.header = msg.header;
    data.twist = msg.twist.twist;
}


int main(int argc, char **argv)
{

  ros::init(argc, argv, "gps2vel");
  ros::NodeHandle n;

//publisher
  ros::Publisher vel_pub = n.advertise<geometry_msgs::TwistStamped>("gps_vel", 1000);

//subscriber
  ros::Subscriber sub1 = n.subscribe("/gps_odometry", 1000, gps_odometry_callback);

  ros::Rate loop_rate(10);


  
  while (ros::ok())
  {

    ROS_INFO("Running");

    vel_pub.publish(data);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}

