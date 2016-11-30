// crashingProgram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void foo(int *&p)
{

}

int main()
{
    int* p;  // Create an uninitialised pointer
    foo(p);  // Trick the compiler into thinking we're going to assign this a valid value
    int a = 123;
    int& b = a;
    std::cout << *p;
    return 0;
}

