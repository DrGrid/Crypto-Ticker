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
    std::string curl_data;
    QString my_data;
public:
    curl_worker();
public slots:
    void process();
signals:
    void finished_thread (QString my_data);
};

#endif
