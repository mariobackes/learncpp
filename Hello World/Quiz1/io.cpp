#include "stdafx.h"
#include <iostream>

int readNumber()
{
    int retVal;
    std::cout << "Enter a summand\n";
    std::cin >> retVal;
    if (std::cin.fail())
    {
        std::cin.clear();
        char c;
        std::cin >> c;
        std::cout << "ERROR: cin failure. Did you enter a character?\n";
        retVal = 970000;
    }
    return retVal;
}

int writeAnswer(int answer)
{
    std::cout << "The sum of the two entered summands is : " << answer << std::endl;
    return 0;
}