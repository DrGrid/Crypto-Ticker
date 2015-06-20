#ifndef LEARNER_H
#define LEARNER_H

#include <vector>
#include <math.h>
#include <cstdio>
#include <fstream>
#include <string>
#include <map>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/filereadstream.h"

struct measurements
{
    bool direction;
    double price;
    void set_measurements(bool in_direction, double in_price)
    {
        direction = in_direction;
        price = in_price;
    }
};

class Learner
{
private:
    rapidjson::Document score;
    rapidjson::Value newValue, tickValue;
    double market_1, market_2;
    double diff;
    double okcoin_delta_five, okcoin_delta_ten, btcchina_delta_five, btcchina_delta_ten;
    std::vector<double> china1, china2, usd1, usd2;
    bool china_move, usd_move;
    bool china1_direction, china2_direction, usd1_direction, usd2_direction;
    bool china_measure, usd_measure;
    char fileBuffer[65536];
    FILE *fp;
    measurements china1_measure, china2_measure, usd1_measure, usd2_measure;
    void push_vector(double current, std::vector<double>& new_storage);
    bool zero_movement(std::vector<double> &once, std::vector<double> &twice);
    void track_record();
    void get_direction();
    void set_score();
    void write_json();
    bool read_json();
    std::ofstream debug;
    std::ifstream file {"json_output.json"};
    std::string json_string;
    const char * json_file;
    void write_debug(const char * input);
public:
    Learner();
    void data_feeder(double china1_current, double china2_current, double usd1_current, double usd2_current);
    double score_china1, score_china2, score_usd1, score_usd2;
};

#endif // LEARNER_H
