#include <iostream>
#include "Logger.h"

int main(int argc, char** argv)
{
    Logger logger = Logger(argc, argv, "Bebop", DroneInfo(0, nullptr, nullptr, nullptr, nullptr, nullptr, 0), Status(nullptr, nullptr, nullptr, nullptr, 0));
    logger.init();

    return 0;
}