#include "data_parser.h"

parsed_data::parsed_data()
{
    increase_dimension = true;
    read_config();
    parse_config();
}

void parsed_data::to_cstring(std::string& data)
{
    c_stringer = data.c_str();
}

void parsed_data::read_config() //read the json config file and add the parameters.
{
    if (conf_file.is_open()) //parse config into JSON object
    {
        std::getline(conf_file, keeper);
    }
    conf_file.close();
    if(!conf_doc.Parse(keeper.c_str()).HasParseError())
    {
        conf_doc.Parse(keeper.c_str());
    }
}

void parsed_data::parse_config()
{
    do //as long as there are more market types, execute the loop
    {
        str.str("");
        str.clear();
        keeper.clear();
        c++;
        str << c;
        str >> keeper;
        cmember_number = keeper.c_str(); //assign markets by number
        if (conf_doc["json_config"].HasMember(cmember_number))
        {
            keeper = conf_doc["json_config"][cmember_number].GetString();
            markets.push_back(keeper);
            keeper.clear();
            if (conf_doc["json_config"][cmember_number].HasMember("dimensions"))
            {
                dimensions.push_back(conf_doc["json_config"][cmember_number]["dimensions"].GetInt());
            }
            for (unsigned short i = 0; i <= 6; i++)
            {
                if (conf_doc["json_config"][cmember_number].HasMember(fields[i])) //extract fields and put them into the map.
                {
                    label_pairs.insert(std::pair<std::string, std::string>(fields[i], conf_doc["json_config"][cmember_number][fields[i]].GetString()));
                }
            }
            if (conf_doc["json_config"][cmember_number].HasMember("label"))
            {
                //Use value to read number of Container/DOM dimensions
                label_pairs.insert(std::pair<std::string, std::string>("label", conf_doc["json_config"][cmember_number]["label"].GetString()));
                c_stringer = label_pairs["label"].c_str();
                for (unsigned short j = 0; j <= 6; j++)
                {
                    if (conf_doc["json_config"][cmember_number][c_stringer].HasMember(fields[j]))
                    {
                        label_pairs.insert(std::pair<std::string, std::string>(fields[j], conf_doc["json_config"][cmember_number][c_stringer][fields[j]].GetString()));
                    }
                }
            }
        }
    }
    while (conf_doc["json_config"].HasMember(cmember_number));
}

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

void parsed_data::okcoin_data_writer(std::string& data)
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
