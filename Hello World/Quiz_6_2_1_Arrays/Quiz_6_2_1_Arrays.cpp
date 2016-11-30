// Quiz_6_2_1_Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

namespace ANIMALS
{
    enum ANIMALS
    {
        ANIMAL_CHICKEN,
        ANIMAL_DOG,
        ANIMAL_CAT,
        ANIMAL_ELEPHANT,
        ANIMAL_DUCK,
        ANIMAL_SNAKE,
        ANIMAL_MAXSIZE
    };
}

/*
void printNumberOfLegsElephant(int animalArray)
{
    std::cout << animalArray[ANIMALS::ANIMAL_ELEPHANT] << std::endl;
}
*/

int main()
{
    // This line was for question #1
    // double temperatureHigh[365] = { 0.0 };

    int animals[ANIMALS::ANIMAL_MAXSIZE] = { 2, 4, 4 , 4, 2, 0 };
    std::cout << "An elephant has " << animals[ANIMALS::ANIMAL_ELEPHANT] << " legs." << std::endl;
    return 0;
}

