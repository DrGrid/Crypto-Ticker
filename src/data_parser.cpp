#include "data_parser.h"

parsed_data::parsed_data()
{
    read_config();
    debug_log.open("debug.log", std::ofstream::out | std::ofstream::trunc);
    debug_log.close();
}

void parsed_data::to_cstring(std::string& data)
{
    c_stringer = data.c_str();
}

void parsed_data::read_config()
{
    if (conf_file.is_open())
    {
        write_debug("The config file exists \n");
        std::getline(conf_file, keeper);
    }
    conf_file.close();
    if(!conf_doc.Parse(keeper.c_str()).HasParseError())
    {
        write_debug("The file has been parsed \n");
        conf_doc.Parse(keeper.c_str());
    }
    if (conf_doc["json_config"].HasMember("key1"))
    {
        keeper = conf_doc["json_config"]["key1"].GetString();
        markets.insert(std::map<int,std::string>::value_type(1, keeper));
    }
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
    if (!document.Parse(c_stringer).HasParseError())
    {
        document.Parse(c_stringer);
        if (document.IsObject())
        {
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
    }
}

void parsed_data::btcchina_data_writer(std::string &data)
{
    to_cstring(data);
    if (!document.Parse(c_stringer).HasParseError())
    {
        document.Parse(c_stringer);
        if (document.IsObject())
        {
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
            time_number = document["ticker"]["date"].GetInt64();
        }
    }
}

void parsed_data::bitfinex_data_writer(std::string &data)
{
    to_cstring(data);
    if (!document.Parse(c_stringer).HasParseError())
    {
        document.Parse(c_stringer);
        if (document.IsObject())
        {
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
    }
}

void parsed_data::bitstamp_data_writer(std::string &data)
{
    to_cstring(data);
    if (!document.Parse(c_stringer).HasParseError())
    {
        document.Parse(c_stringer);
        if (document.IsObject())
        {
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
    }
}
void parsed_data::write_debug(const char * input)
{
    debug_log.open("debug_log", std::ios::app);
    debug_log << input;
    debug_log.close();
}
