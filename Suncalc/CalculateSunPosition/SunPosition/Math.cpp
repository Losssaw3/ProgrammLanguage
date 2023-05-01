#include "Math.h"

double radians(double deg)
{
    return deg * M_PI / 180.0;
}

double degrees(double rad)
{
    return rad * 180.0 / M_PI;
}

double into_range(double x, int  range_min, int  range_max)
{
    int shiftedx = x - range_min;
    int delta = range_max - range_min;
    return (((shiftedx % delta) + delta) % delta) + range_min;
}