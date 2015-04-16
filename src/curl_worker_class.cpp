 #include "curl_worker_class.h"

curl_worker::curl_worker()
{
}

// --- PROCESS ---
// Start processing data.
void curl_worker::process()
{
    curling.settings("https://www.okcoin.cn/api/ticker.do");
    curl_data = curling.fetch();
    my_data = QString::fromStdString(curl_data);
    curling.data_cleanup();
    // allocate resources using new here
    emit finished_thread(my_data);
}
