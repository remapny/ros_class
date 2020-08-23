# Simple Publisher
## __source code__
```c++
#include <ros/ros.h>
#include <std_msgs/String.h>

#include <sstream>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "publisher_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("hello_ros", 1000);
    ros::Rate loop_rate(10);

    int cnt = 0;

    while(ros::ok())
    {
        std_msgs::String msg;

        std::stringstream ss;

        ss << "Hello ROS " << cnt;

        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        pub.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
        cnt++;
    }

    return 0;
}
```

# __실행화면__
![스크린샷, 2020-08-23 16-01-41](https://user-images.githubusercontent.com/69963988/90973128-01e7b080-e55a-11ea-984d-f00186d74aff.png)