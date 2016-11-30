// Check_for_even_number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


bool isEven(int number)
{
    bool retVal;
    if (number % 2 == 0)
    {
        retVal = true;
    }
    else
    {
        retVal = false;
    }
    return retVal;
}

int getUserInput()
{
    int number;
    std::cout << "Enter an integer, please.\n";
    std::cin >> number;
    std::cin.clear();
    return number;
}

int main()
{
    int input;
    input = getUserInput();
    bool numberIsEven;
    numberIsEven = isEven(input);
    std::cout << "The number you entered is ";
    if (!numberIsEven)
    {
        std::cout << "not ";
    }
    std::cout << "even.\n";
    return 0;
}

