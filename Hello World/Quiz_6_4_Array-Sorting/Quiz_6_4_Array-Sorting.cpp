// Quiz_6_4_Array-Sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    const int length = 5;
    int testArray[length] = { 30, 50, 20, 10, 40 };
    for (int index = 0; index < length; ++index)
    {
        std::cout << testArray[index] << " ";
    }
    std::cout << std::endl;
    for (int startIndex = 0; startIndex < length; ++startIndex)
    {
        int largestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            if (testArray[currentIndex] > testArray[largestIndex])
            {
                largestIndex = currentIndex;
            }
            
        }
        std::swap(testArray[startIndex], testArray[largestIndex]);

        for (int index = 0; index < length; ++index)
        {
            std::cout << testArray[index] << " ";
        }
        std::cout << std::endl;
    }



    return 0;
}

