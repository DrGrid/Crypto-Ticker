#ifndef LEARNER_H
#define LEARNER_H

#include <QObject>
#include <QVector>

class Learner : public QObject
{
    Q_OBJECT
public:
    explicit Learner(QObject *parent = 0);
    QVector<double> push_vector(double current, QVector<double>& new_storage);
    double delta(QVector<double> &marketlist, int difference);
    bool significant_discrimination(double market_1, double market_2);
    void predictor();
signals:

public slots:
    void data_feeder(double china1_current, double china2_current, double usd1_current, double usd2_current);
private:
    double market_1, market_2;
    double diff;
    double okcoin_delta_five, okcoin_delta_ten, btcchina_delta_five, btcchina_delta_ten;
    QVector<double> china1, china2, usd1, usd2;
    QVector<double> btcchina_history, okcoin_history;
};

#endif // LEARNER_H
