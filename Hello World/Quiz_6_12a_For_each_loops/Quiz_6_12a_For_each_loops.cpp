// Quiz_6_12a_For_each_loops.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    const int arrayLength = 8;
    std::string names[arrayLength] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };

    std::string userInput;
    std::cout << "Enter a name: ";
    std::cin >> userInput;
    bool match = false;
    for (std::string element : names)
    {
        if (element == userInput)
        { 
            match = true;
        }
    }
    if (match == true)
    {
        std::cout << "The name you entered matched with an element of the array." << std::endl;
    }
    else
    {
        std::cout << "The name you entered did not match." << std::endl;
    }
    return 0;
}

