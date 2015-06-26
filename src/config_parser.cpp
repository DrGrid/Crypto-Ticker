#include "config_parser.h"

config_data::config_data()
{
    increase_dimension = true;
    read_config();
    parse_config();
}

void config_data::read_config() //read the json config file and add the parameters.
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

void config_data::parse_config()
{
    do //as long as there are more market types, execute the loop
    {
        str.str("");
        str.clear();
        keeper.clear();
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
            if (conf_doc["json_config"][cmember_number].HasMember("url"))
            {
                keeper = conf_doc["json_config"][cmember_number]["url"].GetString();
                str_url.push_back(keeper.c_str());
                keeper.clear();
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
            market_labels.push_back(label_pairs);
        }
        c++;
    }
    while (conf_doc["json_config"].HasMember(cmember_number));
}

