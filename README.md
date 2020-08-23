# 설치하기
## __설치하기 내용은 다음과 같이 구성되어 있습니다.__
1. __ROS 설치하기__
    * ROS설치 명령어는 다음과 같이 수행합니다.
        ```s
        $ cd 01_install_ros
        $ chmod +755 install_ros_kinetic.sh
        $ ./install_ros_kinetic.sh
        ```

2. __sphinx 설치 및 실행하기__
    * sphinx 설치 명령어는 다음과 같이 실행합니다.
        ```sh
        $ cd ros_class/02_install_sphinx
        $ chmod +755 install sphinx.sh
        $ ./install_sphinx.sh
        ```
    * 설치가 완료되었다면 ~/drone/bebop2.drone파일을 열어 stolen_interface 부분을 수정합니다.
        ```xml
        <stolen_interface>{your interface}:eth0:192.168.42.1/24</stolen_interface>
        ```
    * 설치가 완료된 경우 다음 파일을 실행하여 sphinx를 실행합니다.
        ```sh
        $ cd ~/
        $ ./sphinx_bebop2.sh
        ```

3. __bebop_autonomy 설치하기__
    * bebop autonomy 설치는 다음과 같이 진행합니다.
        ```sh
        $ sudo apt-get install build-essential python-rosdep python-catkin-tools
        $ cd ~/catkin_ws/src
        $ git clone https://github.com/jungsuyun/bebop_autonomy.git
        $ rosdep update
        $ cd ~/catkin_ws/
        $ rosdep install --from-paths src -i
        $ catkin_make
        ```
    * 설치가 완료되었다면 bashrc폴더에서 본안의 hostname, master_uri를 수정 후 실행합니다.
        * sphinx 상에서 실행하는 경우
            ```sh
            $ roscore
            $ roslaunch bebop_driver bebop_driver_sphinx.launch
            ```
        * 실제 드론과 연결하는 경우
            ```sh
            $ roscore
            $ roslaunch bebop_driver bebop_driver.launch
            ```