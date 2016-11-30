// Quiz 6-X-3 Swap values.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void swapValues(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 1;
    int y = 8;
    std::cout << "x = " << x << " y = " << y << " before swap" << std::endl;
    swapValues(x, y);
    std::cout << "x = " << x << " y = " << y << " after swap" << std::endl;


    return 0;
}

