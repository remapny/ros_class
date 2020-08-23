#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <stdio.h>
#include <termio.h>

#include <iostream>

int getch()
{
    int ch;

    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);

    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();

    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "takeoff_and_land");
    ros::NodeHandle nh;

    ros::Publisher takeoff_pub = nh.advertise<std_msgs::Empty>("/bebop/takeoff", 1);
    ros::Publisher land_pub = nh.advertise<std_msgs::Empty>("/bebop/land", 1);
    ros::Publisher move_pub = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);

    while(ros::ok())
    {
        int input_data =  getch();

        if(input_data == 49)        //1 입력된 경우
        {
            std_msgs::Empty msg;
            takeoff_pub.publish(msg);
        }
        else if(input_data == 50)   //2 입력된 경우
        {
            std_msgs::Empty msg;
            land_pub.publish(msg);
        }
        else if(input_data == 119)  // w가 입력된 경우 전진
        {
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0.1;
            move_msg.linear.y = 0;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if (input_data == 120)     // x가 눌린 경우
        {
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = -0.1;
            move_msg.linear.y = move_msg.linear.z = 0;
            move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_data == 115)      // s가 눌린 경우
        {
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = move_msg.linear.y = move_msg.linear.z = 0;
            move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        ros::spinOnce();
    }

    return 0;
}