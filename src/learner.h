#ifndef LEARNER_H
#define LEARNER_H

#include <QObject>
#include <QVector>

class Learner : public QObject
{
    Q_OBJECT
public:
    explicit Learner(QObject *parent = 0);
    double delta(QVector<double> &marketlist, int difference);
    bool significant_discrimination(double market_1, double market_2);
    void predictor();
signals:

public slots:
    void data_feeder();
private:
    double market_1, market_2;
    double diff;
    double okcoin_delta_five, okcoin_delta_ten, btcchina_delta_five, btcchina_delta_ten;
    QVector<double> okcoin_history = QVector<double> (1001); //QVector initialized with C++11 copy-only member initialisers. The Vector holds the last price of the past 100 seconds.
    QVector<double> btcchina_history = QVector<double> (1001);
    QVector<double> bitfinex_history = QVector<double> (1001);
    QVector<double> bitstamp_history = QVector<double> (1001);
};

#endif // LEARNER_H
