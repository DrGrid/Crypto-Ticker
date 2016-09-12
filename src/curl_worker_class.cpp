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
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        curling_data.clear();
        curling_string = curling.fetch();
        //mute the string to ensure no race conditions
        //muting[index].lock();
        curling_data.clear();
        wrap_mute.lock();
        curling_data = curling_string;
        wrap_mute.unlock();
        //muting[index].lock();
        //end of mutex
        curling_string.clear();
        curling.data_cleanup();
    }
}

