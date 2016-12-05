// Quiz 8-X OOP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << std::endl;
    std::cout << "Distance between two points: " << distanceFrom(first, second) << std::endl;

    return 0;
}

