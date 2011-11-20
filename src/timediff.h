#ifndef TIMEDIFF_H
#define TIMEDIFF_H
#include<time.h>
#include<sys/time.h>

double operator - (timeval& t0, timeval& t1)
{
    return (t0.tv_sec - t1.tv_sec) + 1e-6*(t0.tv_usec - t1.tv_usec);
}


#endif
// TIMEDIFF_H
