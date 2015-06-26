#include "data_parser.h"

void parsed_data::stream_clear(std::string option)
{
    str.str("");
    str.clear();
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
    keeper.clear();
}

void parsed_data::data_writer(std::string& data)
{
    str.str("");
    str.clear();
    keeper.clear();
    to_cstring(data);
    if (!document.Parse(c_stringer).HasParseError())
    {
        document.Parse(c_stringer);
        if (document.IsObject())
        {
            for (int c = 0; c <= 6; c++)
            {
                if (dimensions[0] >= 2 && increase_dimension)
                {
                    c_stringer = label_pairs["label"].c_str();
                    for (int i = 0; i <= 6; i++)
                    {
                        if (document[c_stringer].HasMember(label_pairs[str_fields[i]].c_str()))
                        {
                            debug_logger.write_debug(fields[i]);
                            keeper.clear();
                            keeper = document[c_stringer][label_pairs[str_fields[i]].c_str()].GetString();
                            stream_clear(fields[i]);
                        }
                    }
                    increase_dimension = false;
                    debug_logger.write_debug("\n");
                    debug_logger.write_debug("\n");
                }
                if (document.HasMember(label_pairs[str_fields[c]].c_str()))
                {
                    keeper.clear();
                    keeper = document[label_pairs[str_fields[c]].c_str()].GetString();
                    stream_clear(fields[c]);
                }
            }
        }
    }
    increase_dimension = true;
    debug_logger.write_debug("\n");
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
