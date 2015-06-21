#ifndef DATA_PARSER_H
#define DATA_PARSER_H

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

class parsed_data{
private:
  std::vector<std::string> markets;
  std::map<std::string,std::string> label_pairs;
	std::stringstream str;
	std::string keeper;
	unsigned short c = 0;
  const char * cmember_number;
  const char * c_stringer;
  const char * const fields [7] =  {"date", "buy", "daily_high", "last", "daily_low", "sell", "volume"};
  rapidjson::Document document;
  rapidjson::Document conf_doc;
  std::ifstream conf_file {"config.json"};
  debug debug_logger;
public:
    //use the public variables as a callable interface for the calling class
  parsed_data();
  int64_t time_number;
	float buy;
  double last;
	float sell;
	float daily_high;
	float daily_low;
  double volume;
  //write the data into a readable form, stores in the same object, for every call.
  void read_config();
  void stream_clear(std::string input);
  void to_cstring(std::string& data);
  void okcoin_data_writer(std::string& data);
  void btcchina_data_writer(std::string& data);
  void bitstamp_data_writer(std::string& data);
  void bitfinex_data_writer(std::string& data);
};


#endif //DATA_PARSER_H
