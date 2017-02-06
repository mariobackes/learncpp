#pragma once
#include "Konto.h"
#include <vector>

int choice(std::vector<char> choices);

bool pinIsValid(unsigned int pin);

void printPin(unsigned int pin);

int generatePin();

Konto createAccount();