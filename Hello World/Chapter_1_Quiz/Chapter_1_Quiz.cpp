// Chapter_1_Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define NOT_INT 970000

int errorCode(int errortoken)
{
    int retVal;
    switch (errortoken)
    {
    case NOT_INT : std::cout << "ERROR: Input type is not int. Program will exit now\n";
        retVal = 1;
        break;
    default: std::cout << "No errortoken corresponding to \n" << errortoken;
        retVal = 0;
        break;
    }
    return retVal;
}

int checkForErrors(int variable)
{
    int sanityCheck = 0;
    if (variable == NOT_INT)
    {
        sanityCheck = errorCode(variable);
        if (sanityCheck == 0)
        {
            std::cout << "ERROR: checkForErrors reported an error, but errorCode can not find a corresponding error roken. Debug you code!";
        }
        
    }
    return sanityCheck;
}

int main()
{
    int summand1, summand2, sum;
    int errorPresent;
    summand1 = readNumber();
    errorPresent = checkForErrors(summand1);
    if (errorPresent == 1)
    {
        std::cout << "Exiting the program duo to an error that occured.\n";
        return 1;
    }
    
    summand2 = readNumber();
    errorPresent = checkForErrors(summand2);
    if (errorPresent == 1)
    {
        std::cout << "Exiting the program duo to an error that occured.\n";
        return 1;
    }

    sum = summand1 + summand2;
    writeAnswer(sum);
    return 0;
}

