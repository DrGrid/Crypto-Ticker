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
    c = 1;
    cmember_number = "1";
    keeper.clear();
    while (conf_doc.HasMember(cmember_number))
    {
        if (conf_doc.HasMember(cmember_number))
        {
            keeper = conf_doc[cmember_number].GetString();
            markets.push_back(keeper);
            cmember_name = keeper.c_str();
            keeper.clear();
            if (conf_doc[cmember_name].HasMember("dimensions"))
            {
                dimensions.push_back(conf_doc[cmember_name]["dimensions"].GetInt());
            }
            if (conf_doc[cmember_name].HasMember("url"))
            {
                str_url.push_back(conf_doc[cmember_name]["url"].GetString());
            }
            for (unsigned short i = 0; i <= 6; i++)
            {
                if (conf_doc[cmember_name].HasMember(fields[i])) //extract fields and put them into the map.
                {
                    label_pairs.insert(std::pair<std::string, std::string>(fields[i], conf_doc[cmember_name][fields[i]].GetString()));
                }
            }
            if (conf_doc[cmember_name].HasMember("label"))
            {
                //Use value to read number of Container/DOM dimensions
                label_pairs.insert(std::pair<std::string, std::string>("label", conf_doc[cmember_name]["label"].GetString()));
                c_stringer = label_pairs["label"].c_str();
                for (unsigned short j = 0; j <= 6; j++)
                {
                    if (conf_doc[cmember_name][c_stringer].HasMember(fields[j]))
                    {
                        label_pairs.insert(std::pair<std::string, std::string>(fields[j], conf_doc[cmember_name][c_stringer][fields[j]].GetString()));
                    }
                }
            }
            market_labels.push_back(label_pairs);
        }
        label_pairs.clear();
        c++;
        str.str("");
        str.clear();
        keeper.clear();
        str << c;
        str >> keeper;
        cmember_number = keeper.c_str();
        debug_logger.write_debug(cmember_number);
    }
    debug_logger.write_debug("The config was corectly parsed");
}

