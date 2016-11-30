// Quiz_5_3_case.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

enum class Animal
{
    PIG,
    CHICKEN,
    GOAT,
    DOG,
    OSTRICH
};


int calculate(int value1, int value2, char op)
{
    int retVal;
    
    switch (op)
    {
    case '+': retVal = value1 + value2;
    break;
    case '-': retVal = value1 - value2;
    break;
    case '*': retVal = value1 * value2;
    break;
    case '/': retVal = value1 / value2;
    break;
    case '%': retVal = value1 % value2;
    break;
    default: std::cout << "ERROR: Operator is unknown. Returning 0.";
    retVal = 0;
    break;
    }
    return retVal;
}

std::string getAnimalName(Animal animal)
{
    std::string animalString;

    switch (animal)
    {
    case Animal::PIG:       animalString = "Pig";
        break;
    case Animal::CHICKEN:   animalString = "Chicken";
        break;
    case Animal::GOAT:      animalString = "Goat";
        break;
    case Animal::DOG:       animalString = "Dog";
        break;
    case Animal::OSTRICH:   animalString = "Ostrich";
        break;
    default: std::cout << "ERROR: Default case in getAnimalName. Returning error.";
        animalString = "error";
        break;
    }
    return animalString;
}

int printNumberOfLegs(Animal animal)
{
    int retVal;

    switch (animal)
    {
    case Animal::PIG:       retVal = 4;
        break;
    case Animal::CHICKEN:   retVal = 2;
        break;
    case Animal::GOAT:      retVal = 4;
        break;
    case Animal::DOG:       retVal = 4;
        break;
    case Animal::OSTRICH:   retVal = 2;
        break;
    default: std::cout << "ERROR: Default case in printNumberOfLegs. Returning 0.";
        retVal = 0;
        break;
    }
    return retVal;
}

int main()
{
    std::cout << "A " << getAnimalName(Animal::DOG)     << " has " << printNumberOfLegs(Animal::DOG)     << " legs." << std::endl;
    std::cout << "A " << getAnimalName(Animal::CHICKEN) << " has " << printNumberOfLegs(Animal::CHICKEN) << " legs." << std::endl;
    return 0;
}

