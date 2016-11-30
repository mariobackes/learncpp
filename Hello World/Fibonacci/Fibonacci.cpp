// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int fibonacci(int count)
{
    if (count == 0)
    {
        return 0;
    }
    if (count == 1)
    {
        return 1;
    }
    return fibonacci(count - 1) + fibonacci(count - 2);
}

int main()
{
    std::cout << fibonacci(144);
    return 0;
}

