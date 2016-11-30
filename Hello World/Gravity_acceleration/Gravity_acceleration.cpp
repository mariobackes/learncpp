// Gravity_acceleration.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
    int planetID;
    planetID = getGravity();
    if (planetID == error_ids::general_error)
    {
        std::cout << "getGravity() reported an error. Exiting now.\n";
        return 1; // There probably is a better way to exit here than just returning.
    }
    int intervallId;
    intervallId = getIntervall();
    if (intervallId == error_ids::general_error)
    {
        std::cout << "getIntervall() reported an error. Exiting now\n";
        return 1;
    }
    int heightOfTower;
    heightOfTower = getTowerHeight();
    if (heightOfTower == error_ids::value_out_of_reach)
    {
        std::cout << "ERROR: getTowerHeight() reported input that is out of reach. Exiting now.\n";
        return 1;
    }
    if (heightOfTower == error_ids::general_error)
    {
        std::cout << "ERROR: getTowerHeight() reported an error. Exiting now.\n";
        return 1;
    }
    forLoop(intervallId, planetID, heightOfTower);
    return 0;
}

