#include "learner.h"

Learner::Learner(QObject *parent) :
    QObject(parent)
{
}

void Learner::data_feeder(double china1_current, double china2_current, double usd1_current, double usd2_current)
{
    if (china1.size() <= 12)
        china1.push_back(china1_current);
    else
    {
        for (unsigned short c(0); c < 12; c++)
        {
            china1[c] = china1[c+1];
        }
        china1[11] = china1_current;
    }
    if (china2.size() <= 12)
        china2.push_back(china2_current);
    else
    {
        for (unsigned short c(0); c < 12; c++)
        {
            china2[c] = china2[c+1];
        }
        china2[11] = china2_current;
    }
    if (usd1.size() <= 12)
        usd1.push_back(usd1_current);
    else
    {
        for (unsigned short c(0); c < 12; c++)
        {
            usd1[c] = usd1[c+1];
        }
        usd1[11] = usd1_current;
    }
    if (usd1.size() <= 12)
        usd2.push_back(usd2_current);
    else
    {
        for (unsigned short c(0); c < 12; c++)
        {
            usd2[c] = usd2[c+1];
        }
        usd2[11] = usd2_current;
    }
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
