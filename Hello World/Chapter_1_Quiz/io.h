#pragma once
#include <iostream>
//#ifndef NOT_INT
//#define NOT_INT 970000

//#endif 


#ifndef IO_FUNCTIONS//_SUPER_UNIQUE_NAME_HERE_JUST_TO_BE_SURE
#define IO_FUNCTIONS//_SUPER_UNIQUE_NAME_HERE_JUST_TO_BE_SURE

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



#endif