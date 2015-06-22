#ifndef CURL_WORKER_CLASS_H
#define CURL_WORKER_CLASS_H

#include <QObject>
#include "curl_wrapper_class.h"
#include <string>
#include <QString>

class curl_worker: public QObject
{
    Q_OBJECT
private:
    CppCurl curling;
    std::string curling_string;
    QString curling_data;
public:
    curl_worker(const char * url);
    void curling_process();
public slots:
    void process();
signals:
    void finished_curling (QString okcoin_data);
};

#endif
