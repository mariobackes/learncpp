// Quiz_6_3_Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    const int arrayLength(9);
    int arrayy[arrayLength] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int number = 0;

    while (true)
    {
        std::cout << "Enter an integer between 1 and 9: ";
        std::cin >> number;
        std::cout << std::endl;

        if (std::cin.fail())
        {
            std::cin.clear();   // Reset any error flags
            std::cin.ignore(32767, '\n');       // Ignore any characters in the input buffer.
        }

        if (number <= 9 || number >= 1)         // If valid input is entered.
        {
            for (int i = 0; arrayLength > i; ++i) // Print the array
            {
                std::cout << arrayy[i] << " ";
            }
            std::cout << std::endl << std::endl;
            std::cout << "The array-index of the number you entered is: ";          // I think it is possible to just need a single for loop that prints the whole array
            for (int i = 0; arrayLength > i; ++i)                                   // And at the same times looks for the corresponding index.
            {
                if (arrayy[i] == number)
                {
                    std::cout << i + 1 << std::endl;    // + 1 because our array index starts with 0.
                }
            }
        }

    }
    return 0;
}

