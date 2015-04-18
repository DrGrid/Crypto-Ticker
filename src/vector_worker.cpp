#include "vector_worker.h"

vector_worker::vector_worker(QObject *parent) :
    QObject(parent)
{
    position = 0;
}


void vector_worker::vector_memory_stepping()
{
    if (position < plot_time) //populates the vector for the first hundred time steps (default case would be price every second)
    {
        history[position] = current_last;
        position++;
    }
    else
    {
        history[plot_time] = current_last;
        for (unsigned short c(0); c < plot_time; c++ ) //step through the past hundred seconds and update them to their nearest cell.
        {
            history[c] = history[c+1];
        }
    }
}
