# gps2vel
Transform and publish current velocity from LG simulator's gps odometry

## Overview
From LG simulator, you can add a topic named "gps_odometry to receive the true location of the vehicle in the simulator.
This package subscribes `/gps_odometry` and publishes the velocity of the vehicle to `/gps_vel` in type, geometry_msgs/TwistStamped.
