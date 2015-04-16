 #include "curl_worker_class.h"

curl_worker::curl_worker()
{
}

// --- PROCESS ---
// Start processing data.
void curl_worker::process()
{
    // allocate resources using new here
    emit finished();
}
