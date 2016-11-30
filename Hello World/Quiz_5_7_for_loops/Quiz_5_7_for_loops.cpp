// Quiz_5_7_for_loops.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int sumTo(int x)
{
    int retVal;
    retVal = 0;
    for (int i = 1; i <= x; ++i)
    {
        retVal += i;
    }
    return retVal;
}

int main()
{
    for (int i = 0; i <= 20; i++)
    {
        std::cout << i << std::endl;
    }
    int factorial;
    std::cin >> factorial;
    factorial = sumTo(factorial);
    std::cout << factorial << std::endl;
    return 0;
}