# bebop_teleoperation
## __source code__
```c++
#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <stdio.h>
#include <termio.h>

#include <iostream>

std::string data;

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
    ros::init(argc, argv, "bebop_teleoperation");
    ros::NodeHandle nh;

    ros::Publisher takeoff_pub = nh.advertise<std_msgs::Empty>("/bebop/takeoff", 1);
    ros::Publisher land_pub = nh.advertise<std_msgs::Empty>("/bebop/land", 1);
    ros::Publisher move_pub = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);

    bool is_takeoff = false;

    while(ros::ok())
    {
        int input_key = getch();

        if(input_key == 32)
        {
            if(is_takeoff == false)
            {
                std_msgs::Empty msg;
                takeoff_pub.publish(msg);

                is_takeoff = !is_takeoff;
            }
            else
            {
                std_msgs::Empty msg;
                land_pub.publish(msg);

                is_takeoff = !is_takeoff;
            }
        }
        else if(input_key == 'w' || input_key == 'W')   //forward
        {
            geometry_msgs::Twist move_msg;
            move_msg.linear.x = 0.5;
            move_msg.linear.y = move_msg.linear.z = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_key == 'x' || input_key == 'X')   //backward
        {
            geometry_msgs::Twist move_msg;
            move_msg.linear.x = -0.5;
            move_msg.linear.y = move_msg.linear.z = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_key == 'a' || input_key == 'A')   //left
        {
            geometry_msgs::Twist move_msg;
            move_msg.linear.y = 0.5;
            move_msg.linear.x = move_msg.linear.z = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_key == 'd' || input_key == 'D')   //right
        {
            geometry_msgs::Twist move_msg;
            move_msg.linear.y = -0.5;
            move_msg.linear.x = move_msg.linear.z = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_key == 'u' || input_key == 'U')   // going up
        {
            geometry_msgs::Twist move_msg;
            move_msg.linear.z = 0.5;
            move_msg.linear.x = move_msg.linear.y = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_key == 'm' || input_key == 'M')   // going down
        {
            geometry_msgs::Twist move_msg;
            move_msg.linear.z = -0.5;
            move_msg.linear.x = move_msg.linear.y = move_msg.angular.x = move_msg.angular.y = move_msg.angular.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_key == 'h' || input_key == 'H')   // turn left
        {
            geometry_msgs::Twist move_msg;
            move_msg.angular.z = 0.5;
            move_msg.linear.x = move_msg.linear.y = move_msg.angular.x = move_msg.angular.y = move_msg.linear.z = 0;

            move_pub.publish(move_msg);
        }
        else if(input_key == 'k' || input_key == 'K')   // turn right
        {
            geometry_msgs::Twist move_msg;
            move_msg.angular.z = -0.5;
            move_msg.linear.x = move_msg.linear.y = move_msg.angular.x = move_msg.angular.y = move_msg.linear.z = 0;

            move_pub.publish(move_msg);
        }
        else
        {
            geometry_msgs::Twist move_msg;
            move_msg.angular.z = move_msg.linear.x = move_msg.linear.y = move_msg.angular.x = move_msg.angular.y = move_msg.linear.z = 0;

            move_pub.publish(move_msg);
        }

        ros::spinOnce();
    }

    return 0;
}
```

# __실행화면__
![스크린샷, 2020-08-23 16-01-41](https://user-images.githubusercontent.com/69963988/90973128-01e7b080-e55a-11ea-984d-f00186d74aff.png)