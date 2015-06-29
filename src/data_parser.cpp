#include "data_parser.h"

parsed_data::parsed_data(std::vector<std::map<std::string,std::string>> labels, std::vector<unsigned short> config_dimensions)
{
    market_labels = labels;
    dimensions = config_dimensions;
    main_field = new extracted_fields [market_labels.size()];
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
      str >> main_field[current_market].time_number;
    else if (option == "buy")
      str >> main_field[current_market].buy;
    else if (option == "daily_high")
      str >> main_field[current_market].daily_high;
    else if (option == "last")
      str >> main_field[current_market].last;
    else if (option == "daily_low")
      str >> main_field[current_market].daily_low;
    else if (option == "sell")
      str >> main_field[current_market].sell;
    else if (option == "volume")
      str >> main_field[current_market].volume;
    keeper.clear();
}

void parsed_data::data_writer(std::string &data, int &nmarkets)
{
    current_market = nmarkets;
    str.str("");
    str.clear();
    keeper.clear();
    to_cstring(data);
    if (!document.Parse(data.c_str()).HasParseError())
    {
        document.Parse(data.c_str());
        if (document.IsObject())
        {
            for (int c = 0; c <= 6; c++)
            {
                if (dimensions[current_market] >= 2 && increase_dimension)
                {
                    slabel.clear();
                    slabel = market_labels[current_market]["label"]; //check the vector of maps for the appropriate market name.
                    for (int i = 0; i <= 6; i++)
                    {
                        if (document[slabel.c_str()].HasMember(market_labels[nmarkets][fields[i]].c_str()))
                        {
                            if (document[slabel.c_str()][market_labels[nmarkets][fields[i]].c_str()].IsString())
                            {
                                keeper.clear();
                                keeper = document[slabel.c_str()][market_labels[nmarkets][fields[i]].c_str()].GetString();
                                stream_clear(fields[i]);
                            }
                            else
                            {
                                number_keeper = document[slabel.c_str()][market_labels[nmarkets][fields[c]].c_str()].GetInt();
                            }

                        }
                    }
                    increase_dimension = false;
                }
                if (document.HasMember(market_labels[nmarkets][fields[c]].c_str()))
                {
                    if (document[market_labels[nmarkets][fields[c]].c_str()].IsString())
                    {
                        keeper.clear();
                        keeper = document[market_labels[nmarkets][fields[c]].c_str()].GetString();
                        stream_clear(fields[c]);
                    }
                    else
                    {
                        number_keeper = document[market_labels[nmarkets][fields[c]].c_str()].GetInt();
                    }
                }
            }
        }
    }
    increase_dimension = true;
}

