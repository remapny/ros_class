#include "Logger.h"

Logger::Logger(int argc, char **argv, const char* drone_name, DroneInfo droneInfo, Status status) : droneInfo(droneInfo), status(status) {
    this->init_argc = argc;
    this->init_argv = argv;

    this->droneName = drone_name;

    this->droneInfo = DroneInfo("localhost", "root", "wjdtn1940", "mydb", 3306);
    this->status = Status("localhost", "root", "wjdtn1940", "mydb", 3306);
    this->droneId = droneInfo.get_DroneId_by_Name(this->droneName);

    this->latitude = this->longitude = this->altitude = this->percent = 0;

    this->status_cnt = 1;
}

void Logger::init()
{
    ros::init(init_argc, init_argv, "Bebop_Logger");
    ros::NodeHandle nh;

    this->battery_sub = nh.subscribe("/bebop/states/common/CommonState/BatteryStateChanged", 1, &Logger::batteryCallback, this);
    this->odom_sub = nh.subscribe("/bebop/odom", 1, &Logger::odometryCallback, this);
    this->position_sub = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 1, &Logger::positionCallback, this);

    while(ros::ok())
    {
        ros::spinOnce();

        this->status.insert_status(this->status_cnt, this->droneId, this->latitude, this->longitude, this->altitude, this->percent);
        this->status_cnt++;
    }
}

void
Logger::batteryCallback(const bebop_msgs::CommonCommonStateBatteryStateChanged::ConstPtr &msg)
{
    ROS_INFO("Battery : %d", msg->percent);
    this->percent = msg->percent;
}

void Logger::odometryCallback(const nav_msgs::Odometry::ConstPtr &msg)
{
    this->positionX = msg->pose.pose.position.x;
    this->positionY = msg->pose.pose.position.y;
    this->positionZ = msg->pose.pose.position.z;

    this->orientationX = msg->pose.pose.orientation.x;
    this->orientationY = msg->pose.pose.orientation.y;
    this->orientationZ = msg->pose.pose.orientation.z;

    this->linearX = msg->twist.twist.linear.x;
    this->linearY = msg->twist.twist.linear.y;
    this->linearZ = msg->twist.twist.linear.z;
}

void Logger::positionCallback(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr &msg)
{
    this->latitude = msg->latitude;
    this->longitude = msg->longitude;
    this->altitude = msg->altitude;
}