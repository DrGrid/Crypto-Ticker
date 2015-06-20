#ifndef DEBUG_WRITE_H
#define DEBUG_WRITE_H

#include <fstream>

class debug
{
private:
    std::ofstream debug_log;
public:
    void write_debug(const char * input);
};
#endif
