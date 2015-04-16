#ifndef CURL_WORKER_CLASS_H
#define CURL_WORKER_CLASS_H

#include <QObject>
#include "curl_wrapper_class.h"

class curl_worker: public QObject
{
    Q_OBJECT
private:
public:
    curl_worker();
public slots:
    void process();
signals:
    void finished();
};

#endif
