#include "learner.h"

Learner::Learner(QObject *parent) :
    QObject(parent)
{
}

double Learner::delta(QVector<double> &marketlist, int difference) //calculates the price variance within a specific time
{
    return marketlist[marketlist.size()] - marketlist[marketlist.size() - difference];
}

bool Learner::significant_discrimination(double market_1, double market_2) //returns true, if it detects a significant difference between the market prices
{
    diff = market_1 - market_2;
    if (diff > -0.5 && diff < 0.5)
        return false;
    else
        return true;
}

void Learner::predictor()
{
    if (significant_discrimination(market_1, market_2))
        {
            okcoin_delta_five = delta(okcoin_history,5);
            okcoin_delta_ten =  delta(okcoin_history, 10);
            btcchina_delta_five = delta(btcchina_history, 5);
            btcchina_delta_ten = delta (btcchina_history, 10);
            /*if (((okcoin_delta_five  > 1) | (okcoin_delta_five  < -1) | (btcchina_delta_five  > 1) |  (btcchina_delta_five  < -1)) && ((okcoin_delta_ten  > 2) | (okcoin_delta_ten  < -2) | (btcchina_delta_ten  > 2) | (btcchina_delta_five  < -2)))
            {
                //execute order, derivation from standard market behaviour deteted.
                if(okcoin_delta_five > 0)
                    //do something here
                else
                    //do something here
            }*/
        }
}
