#ifndef DEBUG_WRITE_H
#define DEBUG_WRITE_H

#include <fstream>

class debug
{
private:
    static std::ofstream debug;
public:
    void write_debug();
}
#endif
