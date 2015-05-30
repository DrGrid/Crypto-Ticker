#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <QVector>
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

class parsed_data{
private:
	std::stringstream str;
	std::string keeper;
	unsigned short c = 0;
public:
    //use the public variables as a callable interface for the calling class
  long int time_number;
	float buy;
  double last;
	float sell;
	float daily_high;
	float daily_low;
  double volume;
  //write the data into a readbble form, stores in the same object, for every call.
  void to_cstring(std::string& data);
  void okcoin_data_writer(std::string& data);
  void btcchina_data_writer(std::string& data);
  void bitstamp_data_writer(std::string& data);
  void bitfinex_data_writer(std::string& data);
};


#endif //DATA_PARSER_H
