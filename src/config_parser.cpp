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
    smember_number = "1";
    while (conf_doc.HasMember(smember_number.c_str()))
    {
        if (conf_doc.HasMember(smember_number.c_str()))
        {
            cmember_name.clear();
            cmember_name = conf_doc[smember_number.c_str()].GetString();
            markets.push_back(cmember_name);
            if (conf_doc[cmember_name.c_str()].HasMember("dimensions"))
            {
                dimensions.push_back(conf_doc[cmember_name.c_str()]["dimensions"].GetInt());
            }
            if (conf_doc[cmember_name.c_str()].HasMember("url"))
            {
                str_url.push_back(conf_doc[cmember_name.c_str()]["url"].GetString());
            }
            for (unsigned short i = 0; i <= 6; i++)
            {
                if (conf_doc[cmember_name.c_str()].HasMember(fields[i])) //extract fields and put them into the map.
                {
                    label_pairs.insert(std::pair<std::string, std::string>(fields[i], conf_doc[cmember_name.c_str()][fields[i]].GetString()));
                }
            }
            if (conf_doc[cmember_name.c_str()].HasMember("label"))
            {
                //Use value to read number of Container/DOM dimensions
                label_pairs.insert(std::pair<std::string, std::string>("label", conf_doc[cmember_name.c_str()]["label"].GetString()));
                smarket.clear();
                smarket = label_pairs["label"].c_str();
                for (unsigned short j = 0; j <= 6; j++)
                {
                    if (conf_doc[cmember_name.c_str()][smarket.c_str()].HasMember(fields[j]))
                    {
                        label_pairs.insert(std::pair<std::string, std::string>(fields[j], conf_doc[cmember_name.c_str()][smarket.c_str()][fields[j]].GetString()));
                    }
                }
            }
            market_labels.push_back(label_pairs);
        }
        label_pairs.clear();
        c++;
        str.str("");
        str.clear();
        smember_number.clear();
        str << c;
        str >> smember_number;
    }
}

