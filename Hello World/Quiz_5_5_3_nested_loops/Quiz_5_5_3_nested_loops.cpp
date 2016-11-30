// Quiz_5_5_3_nested_loops.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
 * This code was for task 3).

int main()
{
    int outer = 1;
    while (outer <= 5)
    {
        int inner = 5;
        while (inner >= outer)
        {
            std::cout << inner << " ";
            --inner;
        }
        std::cout << std::endl;
        ++outer;
    }

    return 0;
}
*/

// This one is for task 4)

int main()
{
    int outer = 1;
    while (outer <= 5)
    {
        int inner;
        inner = 5;
        while (inner >= 1)
        {
            if (outer < inner)
            {
                std::cout << " ";
            }
            else
            {
                std::cout << inner;
            }
                --inner;
        }
        std::cout << std::endl;
        ++outer;
    }
    return 0;
}