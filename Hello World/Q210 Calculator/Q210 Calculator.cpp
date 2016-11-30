// Q210 Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int main()
{
    double value1, value2;
    value1 = getDouble();
    value2 = getDouble();
    char op;
    op = getOperator();
    op = verifyOperator(op);
    if (op == 'E')
    {
        std::cout << "Exiting now.\n";
        return 1;
    }
    double solution;
    solution = calculate(value1, value2, op);
    printAnswer(solution);
    return 0;
}

