#include "data_parser.h"
#include <string>
#include <sstream>
#include <QVector>
#include <iostream>
#include <cassert>

void parsed_data::to_cstring(std::string& data)
{
    c_stringer = data.c_str();
}

void parsed_data::stream_clear(std::string option)
{
    str << keeper;
    if (option == "date")
      str >> time_number;
    else if (option == "buy")
      str >> buy;
    else if (option == "daily_high")
      str >> daily_high;
    else if (option == "last")
      str >> last;
    else if (option == "daily_low")
      str >> daily_low;
    else if (option == "sell")
      str >> sell;
    else if (option == "volume")
      str >> volume;
    str.str("");
    str.clear();
    keeper.clear();
}

void parsed_data::okcoin_data_writer(std::string& data)
{
    to_cstring(data);
    document.Parse(c_stringer);
    keeper = document["date"].GetString();
		stream_clear("date");
		keeper = document["ticker"]["buy"].GetString();
		stream_clear("buy");
		keeper = document["ticker"]["high"].GetString();
		stream_clear("daily_high");
		keeper = document["ticker"]["last"].GetString();
    stream_clear("last");
    keeper = document["ticker"]["low"].GetString();
		stream_clear("daily_low");
    keeper = document["ticker"]["sell"].GetString();
    stream_clear("sell");
    keeper = document["ticker"]["vol"].GetString();
    stream_clear("volume");
}

void parsed_data::btcchina_data_writer(std::string &data)
{
    to_cstring(data);
    document.Parse(c_stringer);
    keeper = document["ticker"]["high"].GetString();
    stream_clear("daily_high");
    keeper = document["ticker"]["low"].GetString();
    stream_clear("daily_low");
    keeper = document["ticker"]["buy"].GetString();
    stream_clear("buy");
    keeper = document["ticker"]["sell"].GetString();
    stream_clear("sell");
    keeper = document["ticker"]["last"].GetString();
    stream_clear("last");
    keeper = document["ticker"]["vol"].GetString();
    stream_clear("volume");
    assert(document["ticker"]["date"].IsNumber()); //it passed ->the element is a number.
    time_number = document["ticker"]["date"].GetInt64();
}

void parsed_data::bitfinex_data_writer(std::string &data)
{
    to_cstring(data);
    document.Parse(c_stringer);
    keeper = document["bid"].GetString();
    stream_clear("buy");
    keeper = document["ask"].GetString();
    stream_clear("sell");
    keeper = document["last_price"].GetString();
    stream_clear("last");
    keeper = document["low"].GetString();
    stream_clear("daily_low");
    keeper = document["high"].GetString();
    stream_clear("daily_high");
    keeper = document["volume"].GetString();
    stream_clear("volume");
    keeper = document["timestamp"].GetString();
    stream_clear("date");
}

void parsed_data::bitstamp_data_writer(std::string &data)
{
    to_cstring(data);
    document.Parse(c_stringer);
    keeper = document["high"].GetString();
    stream_clear("daily_high");
    keeper = document["last"].GetString();
    stream_clear("last");
    keeper = document["timestamp"].GetString();
    stream_clear("date");
    keeper = document["bid"].GetString();
    stream_clear("buy");
    keeper = document["volume"].GetString();
    stream_clear("volume");
    keeper = document["low"].GetString();
    stream_clear("daily_low");
    keeper = document["ask"].GetString();
    stream_clear("sell");
}


