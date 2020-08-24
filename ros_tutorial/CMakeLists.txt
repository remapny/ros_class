cmake_minimum_required(VERSION 3.0.2)
project(ros_tutorial)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(publisher_node src/publisher.cpp)
target_link_libraries(publisher_node ${catkin_LIBRARIES})

add_executable(subscriber_node src/subscriber.cpp)
target_link_libraries(subscriber_node ${catkin_LIBRARIES})