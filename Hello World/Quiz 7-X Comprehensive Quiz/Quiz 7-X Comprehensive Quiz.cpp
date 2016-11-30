// Quiz 7-X Comprehensive Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

// 1) a:
double max(double value1, double value2);
// Solution was correct

// b:
void swap(int& value1, int& value2);
// Solution was correct

// c:
int getLargestElement(std::vector<int> vector, int vectorLength);
// Solution was incorrect. Correct solution was:
int& getLargestElement(int* arrayName, int arrayLength);
// int* arrayName can not be const here, because returning a non-const reference would be a const violation.

int findAverage(int x, int y)
{
    return (x + y) / 2;
}


int binarySearch(int *arrayName, int target, int min, int max)
{
    // Get the center of the array.
    int currentIndex;     // TODO: If min is non-zero this will not be working correctly.
    while (min <= max)
    {
        //currentIndex = findAverage(min, max);
        currentIndex = min + ((max - min) / 2);
        // Discard the top of the array.
        if (arrayName[currentIndex] > target)
        {
            max = currentIndex - 1;
        }
        // Discard the bottom of the array.
        else if (arrayName[currentIndex] < target)
        {
            min = currentIndex + 1;
        }
        // If a match is found return the index.
        else
        {
            return currentIndex;
        }
    }
    return -1;
}




int main()
{
    int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    const int numTestValues = 9;

    // Here are the test values
    int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };

    // And here are the expected results for each value
    int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Loop through all of the test values
    for (int count = 0; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index = binarySearch(array, testValues[count], 0, 14);

        // If it matches our expected value, then great!
        if (index == expectedValues[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }


    return 0;
}

