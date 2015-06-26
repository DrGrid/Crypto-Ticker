#include "data_parser.h"

parsed_data::parsed_data(std::vector<std::map<std::string,std::string>> labels)
{
    market_labels = labels;
}

void parsed_data::to_cstring(std::string input)
{
    c_stringer = input.c_str();
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

void parsed_data::data_writer(std::string &data, int &nmarkets)
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
                    c_stringer = market_labels[nmarkets]["label"].c_str();
                    for (int i = 0; i <= 6; i++)
                    {
                        if (document[c_stringer].HasMember(market_labels[nmarkets][fields[i]].c_str()))
                        {
                            keeper.clear();
                            keeper = document[c_stringer][market_labels[nmarkets][fields[i]].c_str()].GetString();
                            stream_clear(fields[i]);
                        }
                    }
                    increase_dimension = false;
                }
                if (document.HasMember(market_labels[nmarkets][fields[c]].c_str()))
                {
                    keeper.clear();
                    keeper = document[market_labels[nmarkets][fields[c]].c_str()].GetString();
                    stream_clear(fields[c]);
                }
            }
        }
    }
    increase_dimension = true;
}

