# 설치하기
설치하기 내용은 다음과 같이 구성되어 있습니다.
-------------
1. ROS 설치하기
    * ROS설치 명령어는 다음과 같이 수행합니다.
        ```s
        $ cd 01_install_ros
        $ chmod +755 install_ros_kinetic.sh
        $ ./install_ros_kinetic.sh
        ```

2. sphinx 설치 및 실행하기
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
