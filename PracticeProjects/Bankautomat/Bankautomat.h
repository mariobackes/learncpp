#pragma once
#include "Konto.h"
#include <vector>

int Choice(std::vector<char> choices);

bool PinIsValid(unsigned int pin);

void PrintPin(unsigned int pin);

int GeneratePin();

bool VerifyUsername(const std::string & uName);

Konto CreateAccount(std::vector<Konto>& konto);