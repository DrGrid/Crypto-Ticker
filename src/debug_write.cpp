#include "debug_write.h"

debug::debug()
{
    debug_log.open("debug.log", std::ofstream::out | std::ofstream::trunc);
    debug_log.close();
}

void debug::write_debug(const char * input)
{
    debug_log.open("debug.log", std::ios::app);
    debug_log << input;
    debug_log.close();
}
