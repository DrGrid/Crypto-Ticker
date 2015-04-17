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
    curl_data = okcoin_curling.fetch();
    okcoin_data = QString::fromStdString(okcoin_string);
    curling.data_cleanup();
    // allocate resources using new here
    emit finished_okcoin(okcoin_data);
 }
}
