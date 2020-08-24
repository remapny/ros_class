#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

#include <iostream>

void pose_callback(const geometry_msgs::PoseStamped::ConstPtr& msg)
{
    std::cout << "Position X : " << msg->pose.position.x << std::endl;
    std::cout << "Position Y : " << msg->pose.position.y << std::endl;
    std::cout << "Position Z : " << msg->pose.position.z << std::endl;

    std::cout << "Orientation X : " << msg->pose.orientation.x << std::endl;
    std::cout << "Orientation Y : " << msg->pose.orientation.y << std::endl;
    std::cout << "Orientation Z : " << msg->pose.orientation.z << std::endl;
    std::cout << "-------------------------" << std::endl;

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "get_aruco_pose");
    ros::NodeHandle nh;

    ros::Subscriber pose_sub = nh.subscribe("/aruco_single/pose", 1, pose_callback);
    ros::spin();

    return 0;
}