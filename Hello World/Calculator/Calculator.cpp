// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define BAD_ARGS 85
#define WRONG_OPERATOR 75
#define TOO_MANY_ATTEMPTS 65
#define CIN_FAILURE 55

bool getUserInput(int& value)
{
	bool retVal = true;
	std::cout << "Enter an integer: ";
	std::cin >> value;
	if (std::cin.fail())
	{
		std::cin.clear();
		char c;
		std::cin >> c;
		retVal = false;
	}
	return retVal;
}

int getOperator(int& op)
{
	int retVal;
	op = 0;
	for (int i = 3; i > 0 && op <= 1 || op >= 4 && i > 0; --i)
	{
		std::cout << "Please enter which operator you want (1 = +, 2 = -, 3 = *, 4 = /): ";
		std::cout << "\nEntering invalid input " << i << " times will terminate the input query\n";
		std::cin >> op;

		if (std::cin.fail())
		{
			std::cin.clear();
			char c;
			std::cin >> c;
			retVal = CIN_FAILURE;
			return retVal;
		}

		if (op >= 1 && op <= 4)
		{
			retVal = 0;
			break;
		}

		if (i == 1)
		{
			retVal = TOO_MANY_ATTEMPTS;
		}

	}

	return retVal;
}

int calculateResult(int Var1, int Var2, int op)
{
	int retArg;
	switch (op)
	{
	case 1: retArg = Var1 + Var2;
		break;
	case 2: retArg = Var1 - Var2;
		break;
	case 3: retArg = Var1 * Var2;
		break; 
	case 4: retArg = Var1 / Var2;
		break;
	case BAD_ARGS: std::cout << "\"calculateResult\" received BAD_ARGS (" << BAD_ARGS << ") as argument for the variable \"op\"";
		retArg = BAD_ARGS;
		break;
	default: std::cout << "ERROR: The value of the variable \"op\" handed to \"calculateResult\" can not be used. \"op\" value: " << op;
		break;
	}
	return retArg;
}

void printResult(int result)
{
	std::cout << "Your result is: " << result << std::endl;
}

int main()
{
	int value1;
	int value2;
	int op;

	if(! getUserInput(value1))
	{ 
		std::cout << "ERROR: cin could not read the input. Did you enter a char?\nExiting now\n";
		return 1;
	}
	if (! getUserInput(value2))
	{
		std::cout << "ERROR: cin could not read the input. Did you enter a char?\nExiting now\n";
		return 1;
	}
	switch (getOperator(op))
	{
	case CIN_FAILURE: std::cout << "ERROR: cin encountered an error. Expected type for input was int. Did you enter a character?\nExiting now.\n";
		return 1;
		break;
	case TOO_MANY_ATTEMPTS: std::cout << "ERROR: Too many failed attempts for input. Exiting now\n";
		return 1;
		break;
	default: std::cout << "SUCCESS: It seems the input is correct.\n";
		break;
	}
	int result = calculateResult(value1, value2, op);
	printResult(result);
    return 0;
}

