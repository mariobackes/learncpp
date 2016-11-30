// PrintDecimalAsBitpattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// 
int printBitReturnNextDecimal(int decimal, int powerOfTwo)
{
    int retVal;
    retVal = decimal;
    if (decimal >= powerOfTwo)
    {
        std::cout << "1";
        retVal = decimal - powerOfTwo;
    }
    else
    {
        std::cout << "0";
    }
    return retVal;
}

int main()
{
    std::cout << "Enter a number between 255 and  0" << std::endl;
    int decimal;
    std::cin >> decimal;
    if (decimal > 255 || decimal < 0)
    {
        std::cout << "The number you entered is not in the supported range. Exiting now." << std::endl;
        return 1;
    }
    decimal = printBitReturnNextDecimal(decimal, 128);
    decimal = printBitReturnNextDecimal(decimal, 64);
    decimal = printBitReturnNextDecimal(decimal, 32);
    decimal = printBitReturnNextDecimal(decimal, 16);
    std::cout << " ";
    decimal = printBitReturnNextDecimal(decimal, 8);
    decimal = printBitReturnNextDecimal(decimal, 4);
    decimal = printBitReturnNextDecimal(decimal, 2);
    decimal = printBitReturnNextDecimal(decimal, 1);
    std::cout << std::endl;
    return 0;
}

