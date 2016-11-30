// Quiz 7-11 Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int factorial(int number)
{
    //std::cout << "calling fac(" << number << ")" << std::endl;
    if (number <= 1)
    {
        //std::cout << "returning 1" << std::endl;
        return 1;
    }
    else
    {
        //std::cout << "returning fac(" << (number - 1) << ") * " << number << std::endl;
        return factorial(number - 1) * number;
    }
}

int sumOfAllNumbers(int number)
{
    if (number < 10)
    {
        return number;
    }
    return sumOfAllNumbers(number / 10) + (number % 10);
}

void binary(int foo)
{
    if(foo > 0)
    {
        binary(foo / 2);
        std::cout << foo % 2;
    }
}


int main()
{
    //std::cout << factorial(5);
    //std::cout << sumOfAllNumbers(93427);
    binary(197);
    return 0;
}

