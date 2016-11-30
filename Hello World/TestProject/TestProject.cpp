// TestProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>


void foo()
{
    foo();  // Crashing your program 101
}

int main()
{
    /*
    srand(time(0));
    // rand needs to be dicarded once before using it. thx visual studio..
    rand();
    std::cout << rand();
    */
    foo();
    return 0;

}

