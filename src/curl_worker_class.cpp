#include "curl_worker_class.h"
#include <thread>

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
    while (something)
    {
        okcoin_string = okcoin_curling.fetch();
        okcoin_data = QString::fromStdString(okcoin_string);
        okcoin_string.clear();
        okcoin_curling.data_cleanup();
        emit finished_okcoin(okcoin_data);
    }
}

void curl_worker::btcchina_process()
{
    while(something)
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
    while(something)
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
    while (something)
    {
        bitstamp_string = bitstamp_curling.fetch();
        bitstamp_data = QString::fromStdString(bitstamp_string);
        bitstamp_string.clear();
        bitstamp_curling.data_cleanup();
        emit finished_bitstamp(bitstamp_data);
    }
}


