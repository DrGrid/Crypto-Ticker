#include "learner.h"

Learner::Learner(QObject *parent) :
    QObject(parent)
{
    china_move = false;
    usd_move = false;
}

void Learner::data_feeder(double china1_current, double china2_current, double usd1_current, double usd2_current)
{
    if ((china1_current-china2_current > 0.1) | (china1_current-china2_current < -0.1))
        china_move = true;
    if ((china1.size() == 11) && (zero_movement(china1,china2)))
        china_move = false;
    if (china_move)
    {
        china1 = push_vector(china1_current, china1);
        china2 = push_vector(china2_current, china2);
    }
    if ((usd1_current-usd2_current > 0.01) | (usd1_current-usd2_current < -0.01))
        usd_move = true;
    if ((usd1.size() == 11) && (zero_movement(usd1,usd2)))
        usd_move = false;
    if (usd_move)
    {
        usd1 = push_vector(usd1_current, usd1);
        usd2 = push_vector(usd2_current, usd2);
    }
}

bool Learner::zero_movement(QVector<double> &once, QVector<double> &twice)
{
    if (once.size() == 11)
        return false;
    for (unsigned short c(0); c <= 10; c++)
    {
        if ((once[c]-twice[c] > 0.1) | (once[c]-twice[c] < -0.1))
            return false;
    }
    return true;
}

QVector<double> Learner::push_vector(double current, QVector<double> &new_storage)
{
    if (new_storage.size() <= 12)
        new_storage.push_back(current);
    else
    {
        for (unsigned short c(0); c < 11; c++)
        {
            new_storage[c] = new_storage[c+1];
        }
        new_storage[11] = current;
    }
    return new_storage;
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
