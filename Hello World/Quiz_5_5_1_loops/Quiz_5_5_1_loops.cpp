// Quiz_5_5_1_loops.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    char currentLetter;
    currentLetter = 'a';
    char lastLetter;
    lastLetter = 'z';   // A better solution would have been to not use lastLetter.
                        // Instead I sould have made the while condition 'while (currentLetter <= 'z')'
    while (currentLetter <= lastLetter)
    {
        std::cout << currentLetter << " " << static_cast<int>(currentLetter) << std::endl;
        currentLetter++;
    }
    std::cout << "done" << std::endl;
    return 0;
}

