// Quiz 6-x-4 c style string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void printCStyleString(char* string)
{
    while(*string != '\0')
    {
        std::cout << *string;
        string++;
    }
}

int main()
{
    char hi[] = "Hello, world!\n";
    printCStyleString(hi);
    return 0;
}

