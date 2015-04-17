 #include "curl_worker_class.h"

curl_worker::curl_worker()
{
 bool something = true;
 okcoin_curling.settings("https://www.okcoin.cn/api/ticker.do");
 btcchina_curling.settings("https://data.btcchina.com/data/ticker");
 bitfinex_curling.settings("https://api.bitfinex.com/v1/pubticker/BTCUSD");
 bitstamp_curling.settings("https://www.bitstamp.net/api/ticker/");
}

// --- PROCESS ---
// Start processing data.
void curl_worker::process()
{
 while (something)
 {
    std::thread okcoin_tread(&curl_worker, okcoin_process, this);
    std::thread btcchina_thread(&curl_worker, btcchina_process, this);
    std::thread bitfinex_thread(&curl_worker, bitfinex_process, this);
    std::thread bitstamp_thread(&curl_worker, bitstamp_process, this);
    bitstamp_thread.join();
    bitfinex_thread.join();
    btcchina_thread.join();
    okcoin_thread.join();
    // allocate resources using new here
    emit finished_okcoin(okcoin_data);
    emit finished_btcchina(btcchina_data);
    emit finished_bitfinex(bitfinex_data);
    emit finished_bitstamp(bitstamp_data);
 }
}

void curl_worker::okcoin_process()
{
 okcoin_string = okcoin_curling.fetch();
 okcoin_data = QString::fromStdString(okcoin_string);
 okcoin_curling.data_cleanup();
}

void curl_worker::btcchina_process()
{
 btcchina_string = btcchina_curling.fetch();
 btcchina_data = QString::fromStdString(btcchina_string);
 btcchina_curling.data_cleanup();
}

void curl_worker::bitfinex_process()
{
 bitfinex_string = bitfinex_curling.fetch();
 bitfinex_data = QString::fromStdString(bitfinex_string);
 bitfinex_curling.data_cleanup();
}

void curl_worker::bitstamp_process()
{
 bitstamp_string = bitstamp_curling.fetch();
 bitstamp_data = QString::fromStdString(bitstamp_string);
 bitstamp_curling.data_cleanup();
}

