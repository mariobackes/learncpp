// Quiz_6_4_3_Bubble_Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Bubblesort
int main()
{
    const int length(9);
    int bubble[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    for (int i = 0; i <= length - 1; ++i)
    {
        for (int i = 0; i < length - 1; ++i)
        {
            if (bubble[i] > bubble[i + 1])
            {
                std::swap(bubble[i], bubble[i + 1]);
            }
        }
    }
    for (int i = 0; length > i; ++i)
    {
        std::cout << bubble[i] << " ";
    }
    return 0;
}

if ('a' > 'b')