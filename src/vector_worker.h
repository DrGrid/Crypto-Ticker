#ifndef VECTOR_WORKER_H
#define VECTOR_WORKER_H

#include <QObject>
#include <QVector>

class vector_worker : public QObject
{
    Q_OBJECT
public:
    explicit vector_worker(QObject *parent = 0);
    void vector_memory_stepping();
signals:

public slots:

private:
    QVector<double> history = QVector<double> (1001);
    unsigned int position;
    unsigned int plot_time;
    double current_last;
};

#endif // VECTOR_WORKER_H
