#ifndef CURL_WORKER_CLASS_H
#define CURL_WORKER_CLASS_H

#include <QObject>
#include "curl_wrapper_class.h"
#include "data_parser.h"
#include <string>
#include <QString>

class curl_worker: public QObject
{
    Q_OBJECT
private:
    CppCurl okcoin_curling, btcchina_curling, bitfinex_curling, bitstamp_curling;
    std::string okcoin_string, btcchina_string, bitfinex_string, bitstamp_string;
    QString okcoin_data, btcchina_data, bitfinex_data, bitstamp_data;
    bool something = true;
public:
    void okcoin_process();
    void btcchina_process();
    void bitfinex_process();
    void bitstamp_process();
    void clear_data();
public slots:
    void process();
signals:
    void finished_okcoin (QString okcoin_data);
    void finished_btcchina (QString btcchina_data);
    void finished_bitfinex (QString bitfinex_data);
    void finished_bitstamp (QString bitstamp_data);
    void finished_all();
};

#endif
