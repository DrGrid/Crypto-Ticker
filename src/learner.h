#ifndef LEARNER_H
#define LEARNER_H

#include <vector>

class Learner
{
private:
    double market_1, market_2;
    double diff;
    double okcoin_delta_five, okcoin_delta_ten, btcchina_delta_five, btcchina_delta_ten;
    std::vector<double> china1, china2, usd1, usd2;
    std::vector<double> btcchina_history, okcoin_history;
    bool china_move, usd_move;
public:
    Learner();
    void push_vector(double current, std::vector<double>& new_storage);
    double delta(std::vector<double> &marketlist, int difference);
    bool significant_discrimination(double market_1, double market_2);
    void predictor();
    bool zero_movement(std::vector<double> &once, std::vector<double> &twice);
    void data_feeder(double china1_current, double china2_current, double usd1_current, double usd2_current);
};

#endif // LEARNER_H
