#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <QVector>

class parsed_data{
private:
	std::stringstream str;
	std::string keeper;
	unsigned short c = 0;
public:
    long int time_number;
	float buy;
    double last;
	float sell;
	float daily_high;
	float daily_low;
    double volume;
    void okcoin_data_writer(std::string& data);
    void btcchina_data_writer(std::string& data);
    void bitstamp_data_writer(std::string& data);
    void bitfinex_data_writer(std::string& data);
};


#endif //DATA_PARSER_H
