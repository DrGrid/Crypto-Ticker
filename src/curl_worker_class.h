#ifndef CURL_WORKER_CLASS_H
#define CURL_WORKER_CLASS_H

#include "curl_wrapper_class.h"
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
    unsigned short index;
public:
    std::string curling_data;
    void settings(const char * url, unsigned short nmarket);
    void curling_process();
    void process();
};

#endif
