#include "data_parser.h"
#include <string>
#include <sstream>

void parsed_data::data_writer(std::string& data)
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
}

void five_step::memory_stepping(float new_price)
{
        price[4]=price[3];
        price[3]=price[2];
        price[2]=price[1];
        price[1]=price[0];
        price[0]=new_price;
        if(tester < price[0])
            tester = price[0];
        if(tester < price[1])
            tester = price[1];
        if(tester < price[2])
            tester = price[2];
        if(tester < price[3])
            tester = price[3];
        if(tester < price[4])
            tester = price[4];
        high_price = tester;
        if(tester > price[0])
            tester = price[0];
        if(tester > price[1])
            tester = price[1];
        if(tester > price[2])
            tester = price[2];
        if(tester > price[3])
            tester = price[3];
        if(tester > price[4])
            tester = price[4];
        low_price = tester;
}
