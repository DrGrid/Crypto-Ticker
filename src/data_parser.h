#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <iostream>
#include <sstream>
#include <string>

class parsed_data{
private:
	std::stringstream str;
	std::string keeper;
	unsigned short c = 0;
public:
    long int time_number;
	float buy;
	float last;
	float sell;
	float daily_high;
	float daily_low;
	void data_writer(std::string& data);
};

class five_step{
private:
    float tester;
    float price[5];
public:
    float high_price;
    float low_price;
    void memory_stepping(float new_price);
};

#endif //DATA_PARSER_H
