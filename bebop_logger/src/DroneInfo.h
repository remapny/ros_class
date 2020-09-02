#ifndef BEBOP_LOGGER_DRONEINFO_H
#define BEBOP_LOGGER_DRONEINFO_H

#include <mysql/mysql.h>
#include <iostream>

class DroneInfo
{
private:
    int droneId;
    const char* droneName;

    const char* host;
    const char* user;
    const char* pw;
    const char* db;
    int port;

    MYSQL* connection;
    MYSQL conn;
    MYSQL_RES* sql_result;
    MYSQL_ROW sql_row;
    MYSQL_FIELD sql_field;



public:
    DroneInfo(int droneId, const char* droneName, const char* host, const char* user, const char* pw, const char* db, int port);
    DroneInfo(const char* host, const char* user, const char* pw, const char* db, int port);
    void input_DroneInfo();
    int get_DroneId_by_Name(const char* droneName);
};


#endif //BEBOP_LOGGER_DRONEINFO_H
