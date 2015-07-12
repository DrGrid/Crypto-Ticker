#ifndef CURL_WORKER_CLASS_H
#define CURL_WORKER_CLASS_H

#include "curl_wrapper_class.h"
#include "debug_write.h"
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

class curl_worker
{
private:
    CppCurl curling;
    std::string curling_string;
    unsigned short nrequests;
    std::time_t unix_time, prevtime;
    debug debugger;
public:
    std::mutex wrap_mute;
    std::string curling_data;
    void settings(const char * url);
    void curling_process();
    void process();
};

#endif
