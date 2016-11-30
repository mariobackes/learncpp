// Funct_parameters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


// This function takes no parameters, therefore it does not rely on the caller!
void doPrint()
{
	std::cout << "In doPrint()" << std::endl;
	// return is not needed, because the function is of type "void" and therefore does not return a value.
	// The function ends, when it hits the closing bracket.
}

void printValue(int x)
{
	std::cout << x << std::endl;
}

int multiply(int Value1, int Value2)
{
	return Value1 * Value2;
}

int add(int x, int y)
{
	return x + y;
}

int doubleNumber(int foo)
{
	return foo * 2;
}

int main()
{
	// Testing some functions
	doPrint();
	printValue(42);
	int Var1, Var2;
	std::cout << "Enter an integer" << std::endl;
	std::cin >> Var1;
	std::cout << "Enter another integer" << std::endl;
	std::cin >> Var2;
	// Tested whether you can call a function in a function call. It does work!
	std::cout << add(multiply(Var1, Var1), multiply(Var2, Var2)) << std::endl;
	std::cout << "Enter an integer, that will be doubled." << std::endl;
	// Thought about reusing Var1 or Var2 here, but that would be a mess.
	int willBeDoubled;
	std::cin >> willBeDoubled;
	std::cout << doubleNumber(willBeDoubled) << std::endl;
    return 0;
}

