// Quiz 7-4-A return by value reference address.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

struct Employee
{
    std::string name;
};


///////////////////////////////////


int sumTo(int number);

void printEmployeeName(/*const*/Employee& employee);

void minMax(int i_min, int i_max, int& o_min, int& o_max);

int getIndexOfLargestValue(const int* arrayName, int arraySize);

const int& getElement(const int* arrayName, int index);



int main()
{
    return 0;
}

