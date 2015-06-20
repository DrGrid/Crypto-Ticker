#include "debug_write.h"

debug::debug()
{
    debug.open("debug.log", std::ofstream::out | std::ofstream::trunc);
    debug.close();
}


void debug::write_debug(const char * input)
{
    debug.open ("debug.log", std::ios::app);
    debug << input;
    debug.close();
}
