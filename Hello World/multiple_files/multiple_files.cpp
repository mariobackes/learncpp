// multiple_files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "add.h"

int add(int x, int y);

int main()
{
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << std::endl;
    return 0;
}

