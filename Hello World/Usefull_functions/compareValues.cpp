#include "stdafx.h"
#include <iostream>
#include <cmath>


// return true, if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b.
bool approxEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if numbers are really close -- needed when comparing near zero.
    double diff = fabs(a - b);
    if (diff <= absEpsilon)
    {
        return true;
    }
    // Otherwise fall back to Donald Knuth's algorithm.
    return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}