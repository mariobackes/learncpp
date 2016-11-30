// Quiz_6_9_a_Dynamic_Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

unsigned int amountOfNames()
{
    bool failure = true;
    unsigned int amount;
    while (failure)
    {
        failure = false;
        std::cout << "Please enter how many names you want to enter(max. 100): ";
        std::cin >> amount;
        if (std::cin.fail() || amount > 100u)
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Please enter valid input." << std::endl;
            failure = true;
        }
    }
    return amount;
}

// Just the ordinary selection sort algorithm.
void selectionSort(std::string* unsortedArray, int arrayLength)
{
    for (int startIndex = 0; startIndex < arrayLength; ++startIndex)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < arrayLength; ++currentIndex)
        {
            if (unsortedArray[currentIndex] < unsortedArray[smallestIndex])
            {
                smallestIndex = currentIndex;
            }

            
        }
        std::swap(unsortedArray[startIndex], unsortedArray[smallestIndex]);
    }
}

int main()
{
    unsigned int amountNames = amountOfNames();;

    std::string* names = new std::string[amountNames];    // Create a dynamic array of desired size.

    for (unsigned i = 0u; i < amountNames; ++i)
    {
        std::cout << "Enter Name #" << i + 1 << ": ";    // Ask for user input for every element in the array.
        std::cin >> names[i];
    }
    selectionSort(names, amountNames);                   // Sort the array.     // I might add another sorting algorithm for practice.

    for (unsigned i = 0u; i < amountNames; ++i)                // Print the array.
    {
        std::cout << names[i] << std::endl;
    }
    delete[] names;
    names = nullptr;
    return 0;
}

