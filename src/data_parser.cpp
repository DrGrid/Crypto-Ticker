#include "data_parser.h"

parsed_data::parsed_data()
{
    read_config();
}

void parsed_data::to_cstring(std::string& data)
{
    c_stringer = data.c_str();
}

void parsed_data::read_config() //read the json config file and add the parameters.
{
    if (conf_file.is_open())
    {
        debug_logger.write_debug("The config file exists \n");
        std::getline(conf_file, keeper);
    }
    conf_file.close();
    if(!conf_doc.Parse(keeper.c_str()).HasParseError())
    {
        debug_logger.write_debug("The file has been parsed \n");
        conf_doc.Parse(keeper.c_str());
    }
    do
    {
        str.str("");
        str.clear();
        keeper.clear();
        c++;
        str << c;
        str >> keeper;
        cmember_number = keeper.c_str();
        if (conf_doc["json_config"].HasMember(cmember_number))
        {
            keeper = conf_doc["json_config"][cmember_number].GetString();
            markets.push_back(keeper);
            for (unsigned short i = 0; i <= 6; i++)
            {
                if (conf_doc["json_config"][cmember_number].HasMember(fields[i]))
                {
                    label_pairs.insert(std::pair<std::string, std::string>(fields[i], conf_doc["json_config"][cmember_number][fields[i]].GetString()));
                    debug_logger.write_debug(label_pairs[fields[i]].c_str());
                    debug_logger.write_debug("The presence of the member date was checked\n");
                }
            }
            if (conf_doc["json_config"][cmember_number].HasMember("label"))
            {
                label_pairs.insert(std::pair<std::string, std::string>("label", conf_doc["json_config"][cmember_number]["label"].GetString()));
                c_stringer = label_pairs["label"].c_str();
                debug_logger.write_debug(c_stringer);
                debug_logger.write_debug("Label abstraction reached!");
                for (unsigned short i = 0; i <= 6; i++)
                {
                    if (conf_doc["json_config"][cmember_number][label_pairs["label].c_str()]
            }
        }

    }
    while (conf_doc["json_config"].HasMember(cmember_number));
    debug_logger.write_debug(cmember_number);
    c = 0;
}

void parsed_data::stream_clear(std::string option)
{
    str.str("");
    str.clear();
    keeper.clear();
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
