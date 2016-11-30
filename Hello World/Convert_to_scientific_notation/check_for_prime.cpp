// Convert_to_scientific_notation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>


int main()
{
    int number = getNumber();
    if (!checkIfPositive(number))
    {
        std::cout << "The number has to be a positive integer." << std::endl << "Exiting now." << std::endl;
        return 0;
    }
    bool isPrime;
    isPrime = calculateIfPrime(number);
    writeAnswer(isPrime);
    return 0;
}

