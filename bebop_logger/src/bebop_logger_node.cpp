#include "DroneInfo.h"
#include "Status.h"
#include <iostream>

int main()
{
    Status status = Status("localhost", "root", "wjdtn1940", "mydb", 3306);
    status.insert_status(1, 1, 36.5204, 127.1731, 10, 100);

    return 0;
}