#include "DroneInfo.h"
#include <string>
#include <stdlib.h>

DroneInfo::DroneInfo(int droneId, const char *droneName, const char *host, const char *user, const char *pw,
                     const char *db, int port)
{
    this->droneId = droneId;
    this->droneName = droneName;
    this->host = host;
    this->user = user;
    this->pw = pw;
    this->port = port;
    this->db = db;
}

void DroneInfo::input_DroneInfo()
{
    mysql_init(&this->conn);
    this->connection = mysql_real_connect(&this->conn, this->host, this->user, this->pw, this->db, 3306, (const char*)NULL, 0);

    if(this->connection != NULL)
    {
        std::cout << "connection success" << std::endl;

        std::string query = "insert into DroneInfo value(" + std::to_string(this->droneId)  + ", "+ "\"" + this->droneName + "\"" + ")";
        int state = 0;
        state = mysql_query(connection, query.c_str());

        mysql_close(connection);
    }
}

int DroneInfo::get_DroneId_by_Name(const char *droneName)
{
    mysql_init(&this->conn);
    this->connection = mysql_real_connect(&this->conn, this->host, this->user, this->pw, this->db, this->port, (const char*)NULL, 0);

    std::string query = "select DroneId from DroneInfo where DroneName = " + (std::string)"\"" + (std::string)droneName + (std::string)"\"";
    int state = 0;
    int droneId = 0;

    state = mysql_query(this->connection, query.c_str());
    if(state == 0)
    {
        this->sql_result = mysql_store_result(connection);
        if(sql_result->field_count > 1)
            std::cout << "Duplicate Drone Name" << std::endl;
        else
        {
            while((sql_row = mysql_fetch_row(sql_result)) != NULL)
                for(int i = 0 ; i < sql_result->field_count ; i++)
                    droneId = atoi(sql_row[i]);
            mysql_free_result(sql_result);
        }
    }
    mysql_close(connection);
    return droneId;
}

DroneInfo::DroneInfo(const char *host, const char *user, const char *pw, const char *db, int port)
{
    this->host = host;
    this->user = user;
    this->pw = pw;
    this->port = port;
    this->db = db;
}