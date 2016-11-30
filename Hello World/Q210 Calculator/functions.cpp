#include "stdafx.h"
#include <iostream>

double getDouble()
{
    using namespace std;
    cout << "Enter a number, please." << endl;
    double number;
    cin >> number;
    cin.clear();
    return number;
}

char getOperator()
{
    using namespace std;
    cout << "Enter the operator you want to be used.\nAvailable operators are: +    -   *   /." << endl;
    char op;
    cin >> op;
    cin.clear();
    return op;
}

char verifyOperator(char op)
{
    char retVal;
    switch (op)
    {
    case '/': 
    case '*':
    case '+':
    case '-':
        break;
    default: std::cout << "Operator is not valid. Reporting error to main." << std::endl;
        op = 'E';
        break;
    }
    return op;
}

int printAnswer(double answer)
{
    using namespace std;
    cout << "The solution of the calculation is: " << answer << endl;
    return 0;
}

double calculate(double value1, double value2, char op)
{
    double retVal;
    switch (op)
    {
    case '/': retVal = value1 / value2;
        break;
    case '*': retVal = value1 * value2;
        break;
    case '+': retVal = value1 + value2;
        break;
    case '-': retVal = value1 - value2;
        break;
    default: std::cout << "Something went terribly wrong in calculate().";
        break;
    }
    return retVal;
}