#ifndef CURL_WORKER_CLASS_H
#define CURL_WORKER_CLASS_H

#include <QObject>
#include "curl_wrapper_class.h"
#include <string>
#include <QString>
#include <thread>

class curl_worker: public QObject
{
    Q_OBJECT
private:
    CppCurl okcoin_curling, btcchina_curling, bitfinex_curling, bitstamp_curling;
    std::string okcoin_string, btcchina_string, bitfinex_string, bitstamp_string;
    QString okcoin_data, btcchina_data. bitfinex_data. bitstamp_data;
public:
    curl_worker();
public slots:
    void process();
signals:
    void finished_okcoin (QString okcoin_data);
};

#endif
