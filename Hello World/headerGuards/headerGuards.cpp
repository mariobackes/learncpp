// headerGuards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "square.h"
#include <iostream>

int main()
{
	std::cout << "a square has " << getSquareSides() << "sides" << std::endl;
	std::cout << "a square of length 5 has perimtere length" << getSquarePerimeter(5) << std::endl;

    return 0;
}

