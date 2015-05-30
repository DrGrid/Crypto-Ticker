#include "data_parser.h"
#include <string>
#include <sstream>
#include <QVector>

void parsed_data::okcoin_data_writer(std::string& data)
{
    keeper = data[9];
		keeper += data[10];
		keeper += data[11];
		keeper += data[12];
		keeper += data[13];
		keeper += data[14];
		keeper += data[15];
		keeper += data[16];
		keeper += data[17];
		keeper += data[18];
		keeper += data[19];
		str << keeper;
		str >> time_number; //finish writing the date / time.
		str.str("");
		str.clear();
		keeper.clear();
		keeper = data[38];
		c = 39;
		while (data[c+1] != ',')
		{
			keeper += data[c];
			c++;
		}
		str << keeper;
		str >> buy; //finish writing the current top buy order.
		str.str("");
		str.clear();
		keeper.clear();
		c+=10;
		keeper = data[c];
		c++;
		while (data[c+1] != ',')
		{
			keeper += data[c];
			c++;
		}
		str << keeper;
		str >> daily_high; //finish writing the highest executed order during the last 24h.
		str.str("");
		str.clear();
		keeper.clear();
		c+=10;
		keeper = data[c];
		c++;
		while (data[c+1] != ',')
		{
			keeper += data[c];
			c++;
		}
		str << keeper;
		str >> last; //finish writing the last executed order value.
		str.str("");
		str.clear();
		keeper.clear();
		c+=9;
		keeper = data[c];
		c++;
		while (data[c+1] != ',')
		{
			keeper += data[c];
			c++;
		}
		str << keeper;
		str >> daily_low; //finish writing the lowest executed order of the last 24h.
		str.str("");
		str.clear();
		keeper.clear();
		c+=10;
		keeper = data[c];
		c++;
		while (data[c+1] != ',')
		{
			keeper += data[c];
			c++;
		}
        str << keeper;
        str >> sell; //finish writing the last sell order.
        str.str("");
        str.clear();
        keeper.clear();
        c+=9;
        keeper = data[c];
        c++;
        while (data[c+1] != ',')
        {
            keeper += data[c];
            c++;
        }
        str << keeper;
        str >> volume; //finish writing the last sell order.
        str.str("");
        str.clear();
        keeper.clear();
}

void parsed_data::btcchina_data_writer(std::string &data)
{
    c = 19;
    keeper = data[c];
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> daily_high; //daily high
    str.str("");
    str.clear();
    keeper.clear();
    c+=10;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> daily_low; //daily low
    str.str("");
    str.clear();
    keeper.clear();
    c+=10;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> buy;   //buy
    str.str("");
    str.clear();
    keeper.clear();
    c+=11;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> sell; //sell
    str.str("");
    str.clear();
    keeper.clear();
    c+=11;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> last; //last
    str.str("");
    str.clear();
    keeper.clear();
    c+=10;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> volume; //volume
    str.str("");
    str.clear();
    keeper.clear();
    c+=11;
    while (data[c+1] != ',')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> time_number; //volume
    str.str("");
    str.clear();
    keeper.clear();
}

void parsed_data::bitfinex_data_writer(std::string &data)
{
    c = 24;
    keeper = data[c];
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> buy; //sell
    str.str("");
    str.clear();
    keeper.clear();
    c+=10;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> sell; //buy
    str.str("");
    str.clear();
    keeper.clear();
    c+=17;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> last; //last
    str.str("");
    str.clear();
    keeper.clear();
    c+=10;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> daily_low; //low
    str.str("");
    str.clear();
    keeper.clear();
    c+=11;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> daily_high; //high
    str.str("");
    str.clear();
    keeper.clear();
    c+=14;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> volume; //volume
    str.str("");
    str.clear();
    keeper.clear();
    c+=16;
    while (data[c+1] != '"')
    {
        keeper += data[c];
        c++;
    }
    str << keeper;
    str >> time_number; //timestamp
    str.str("");
    str.clear();
    keeper.clear();
}

void parsed_data::bitstamp_data_writer(std::string &data)
{
    c = 10;
    keeper = data[c];
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> daily_high; //buy
    str.str("");
    str.clear();
    keeper.clear();
    c+=13;
    keeper = data[c];
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> last; //last
    str.str("");
    str.clear();
    keeper.clear();
    c+=17;
    keeper = data[c];
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> time_number; //timestamp
    str.str("");
    str.clear();
    keeper.clear();
    c+=11;
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> buy; //buy
    str.str("");
    str.clear();
    keeper.clear();
    c+=13;
    while (data[c+1] != '"')
    {
        c++;  //leave out for vwap
    }
    c+=15;
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> volume; //volume
    str.str("");
    str.clear();
    keeper.clear();
    c+=11;
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> daily_low; //low
    str.str("");
    str.clear();
    keeper.clear();
    c+=11;
    while (data[c+1] != '"')
    {
        c++;
        keeper += data[c];
    }
    str << keeper;
    str >> sell; //sell
    str.str("");
    str.clear();
    keeper.clear();
}


