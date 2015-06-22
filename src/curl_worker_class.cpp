#include "curl_worker_class.h"
#include <thread>
#include <chrono>
#include <ctime>
// --- PROCESS ---
// Start processing data.

curl_worker::curl_worker(const char * url)
    : QObject()
{
    curling.settings(url);
}

void curl_worker::process()
{
    std::thread (&curl_worker::curling_process, this).detach();
}

void curl_worker::curling_process()
{
    unsigned short nrequests; //use this varible to control the number of requests the user is making, it has to be sub 40, otherwise he will be banned by some APIs.
    std::time_t unix_time = std::time(nullptr);
    long prevtime;
    while (true)
    {
        prevtime = unix_time;
        unix_time = std::time(nullptr);
        if (prevtime == unix_time)
        {
          nrequests++;
          if (nrequests == 20)
              std::this_thread::sleep_for(std::chrono::seconds(1)); //wait a bit, in case the client queries the api too often.
        }
        else
          nrequests = 0;
        curling_string = curling.fetch();
        curling_data = QString::fromStdString(curling_string);
        curling_string.clear();
        curling.data_cleanup();
        emit finished_curling(curling_data);
    }
}

