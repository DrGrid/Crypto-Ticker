#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include "debug_write.h"

class config_data{
private:
  std::map<std::string, std::string> label_pairs;
  std::stringstream str;
	std::string keeper;
  bool increase_dimension;
	unsigned short c = 0;
  const char * cmember_number;
  const char * c_stringer;
  const char * const fields [7] =  {"date", "buy", "daily_high", "last", "daily_low", "sell", "volume"};
  std::string str_fields [7] =  {"date", "buy", "daily_high", "last", "daily_low", "sell", "volume"};
  rapidjson::Document conf_doc;
  std::ifstream conf_file {"config.json"};
  debug debug_logger;
public:
  std::vector<std::map<std::string,std::string>> market_labels;
  std::vector<unsigned short> dimensions;
  //use the public variables as a callable interface for the calling class
	std::vector<std::string> markets;
  std::vector<const char *> str_url;
  config_data();
  //write the data into a readable form, stores in the same object, for every call.
  void read_config();
  void parse_config();
};


#endif //CONFIG_PARSER_H
