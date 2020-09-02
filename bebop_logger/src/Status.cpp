#include "Status.h"
#include <time.h>

Status::Status(const char *host, const char *user, const char *pw, const char *db, int port)
{
    this->host = host;
    this->user = user;
    this->pw = pw;
    this->db = db;
    this->port = port;
    this->connect = NULL;
}

void Status::insert_status(int statusId, int droneId, double latitude, double longitude, double altitude,
                           int batteryPercent)
{
    time_t t = time(NULL);
    struct tm curr_tm = *localtime(&t);

    int year = curr_tm.tm_year + 1900;
    int month = curr_tm.tm_mon + 1;
    int day = curr_tm.tm_mday;
    int hour = curr_tm.tm_hour;
    int minute = curr_tm.tm_min;
    int second = curr_tm.tm_sec;
    std::cout << "generate time" <<std::endl;

    this->timeStamp = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day) + " " + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
    std::cout << "timestamp : " << this->timeStamp << std::endl;

    mysql_init(&this->conn);
    this->connect = mysql_real_connect(&this->conn, this->host, this->user, this->pw, this->db, 3306, (const char*)NULL, 0);

    if(this->connect != NULL)
    {
        std::string query;
        query = "insert into Status value(" + std::to_string(statusId) + "," + std::to_string(droneId) + "," +
                 + "\"" + timeStamp + "\"" +"," + std::to_string(latitude) + "," + std::to_string(longitude) + "," +
                std::to_string(altitude) + "," + std::to_string(batteryPercent) + ")";
        std::cout << query << std::endl;

        int state = 0;
        state = mysql_query(connect, query.c_str());

        if(state == 0)
            std::cout << "success" << std::endl;
        else
            std::cout << "error" << std::endl;

        mysql_close(connect);
    }
}