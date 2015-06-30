#include "curl_worker_class.h"
// --- PROCESS ---
// Start processing data.

void curl_worker::settings(const char * url)
{
    curling.settings(url);
}

void curl_worker::process()
{
    debugger.write_debug("You are now in the process function, the thread is on its way");
    //std::thread (&curl_worker::curling_process, this).detach();
    std::thread (&curl_worker::curling_process, this).detach();
    debugger.write_debug("The thread has been detatched, wish it good luck");
}

void curl_worker::curling_process()
{
    //nrequests = 0; //use this varible to control the number of requests the user is making, it has to be sub 40, otherwise he will be banned by some APIs.
    //unix_time = std::time(nullptr);
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    while (true)
    {
        /*prevtime = unix_time;
        unix_time = std::time(nullptr);
        if (prevtime == unix_time)
        {
          nrequests++;
          if (nrequests == 20)
              std::this_thread::sleep_for(std::chrono::seconds(1)); //wait a bit, in case the client queries the api too often.
        }
        else
          nrequests = 0;*/
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        curling_data.clear();
        curling_string = curling.fetch();
        //mute the string to ensure no race conditions
        //muting[index].lock();
        curling_data.clear();
        curling_data = curling_string;
        //muting[index].lock();
        //end of mutex
        curling_string.clear();
        curling.data_cleanup();
    }
}

