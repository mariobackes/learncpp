#include "stdafx.h"
#include <iostream>

int getNumber()
{
    using namespace std;
    int number;
    cout << "Please, enter a positive integer!" << endl;
    cin >> number;
    cout << endl;
    return number;
}

bool checkIfPositive(int number)
{
    bool retVal;
    if (number < 0)
    {
        retVal = false;
    }
    else
    {
        retVal = true;
    }
    return retVal;
}

int writeAnswer(bool isPrime)
{
    if (isPrime == true)
    {
        std::cout << "The number you entered is a prime." << std::endl;
    }
    else
    {
        std::cout << "The number you entered is not a prime." << std::endl;
    }
    return 0;
}

bool calculateIfPrime(int number)
{
    int upperLimit = number;
    bool isPrime = true;
    int checking;
    // We start with 2, because a prime is defined as a number that is noly divisible by itself and 1.
    for (checking = 2; checking < number; ++checking)
    {
        if (number % checking == 0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}