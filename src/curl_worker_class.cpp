#include "curl_worker_class.h"
#include <thread>
#include <chrono>
#include <ctime>
// --- PROCESS ---
// Start processing data.

curl_worker::curl_worker()
    : QObject()
{
    okcoin_curling.settings("https://www.okcoin.cn/api/ticker.do");
    btcchina_curling.settings("https://data.btcchina.com/data/ticker");
    bitfinex_curling.settings("https://api.bitfinex.com/v1/pubticker/BTCUSD");
    bitstamp_curling.settings("https://www.bitstamp.net/api/ticker/");
}

void curl_worker::process()
{
    std::thread (&curl_worker::okcoin_process, this).detach();
    std::thread (&curl_worker::btcchina_process, this).detach();
    std::thread (&curl_worker::bitfinex_process, this).detach();
    std::thread (&curl_worker::bitstamp_process, this).detach();
}

void curl_worker::okcoin_process()
{
    unsigned short nrequests; //use this varible to control the number of requests the user is making, it has to be sub 40, otherwise he will be banned from the API.
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
        okcoin_string = okcoin_curling.fetch();
        okcoin_data = QString::fromStdString(okcoin_string);
        okcoin_string.clear();
        okcoin_curling.data_cleanup();
        emit finished_okcoin(okcoin_data);
    }
}

void curl_worker::btcchina_process()
{
    while(true)
    {
        btcchina_string = btcchina_curling.fetch();
        btcchina_data = QString::fromStdString(btcchina_string);
        btcchina_string.clear();
        btcchina_curling.data_cleanup();
        emit finished_btcchina(btcchina_data);
    }
}

void curl_worker::bitfinex_process()
{
    while(true)
    {
        bitfinex_string = bitfinex_curling.fetch();
        bitfinex_data = QString::fromStdString(bitfinex_string);
        bitfinex_string.clear();
        bitfinex_curling.data_cleanup();
        emit finished_bitfinex(bitfinex_data);
    }
}

void curl_worker::bitstamp_process()
{
    while (true)
    {
        bitstamp_string = bitstamp_curling.fetch();
        bitstamp_data = QString::fromStdString(bitstamp_string);
        bitstamp_string.clear();
        bitstamp_curling.data_cleanup();
        emit finished_bitstamp(bitstamp_data);
    }
}


