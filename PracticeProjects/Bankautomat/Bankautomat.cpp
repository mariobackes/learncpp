// Bankautomat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Konto.h"
#include "Bankautomat.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
#include <Windows.h>
#undef max

const int g_maxPinEntryTries = 5;

unsigned int enterPin()
{                       // TODO: Make the pin entry non visible in the console
  std::string sPin;
  while (true)
  {
    
    //std::getline(std::cin, sPin);
    std::cin >> sPin;
    std::cin.ignore(32767, '\n');
    if (sPin.size() != 4)
    {
      std::cout << "The pin you entered is not four digits long, please try again" << std::endl;
      continue;
    }
    else
    {
      bool flag = false;
      for (const auto& iii : sPin)
      {
        if (iii < '0' || iii > '9')
        {
          flag = true;
          break;
        }
      }
      if (flag)
      {
        std::cout << "Input was invalid, try again." << std::endl;
        continue;
      }
      return std::stoi(sPin);
    }
  }
}

int choice(std::vector<char> choices)
{
  char input;
  std::cin >> input;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (std::cin.fail())
  {
    std::cin.clear();
  }
  input = tolower(input);
  int i = 0;
  for (const auto& character : choices)
  {
    ++i;
    if (character == input)
    {
      return i;
    }
  }
  return 0; // If no match is found
}

inline bool pinIsValid(unsigned int pin)
{
  return pin > 9999 ? false : true;
}

inline void printPin(unsigned int pin)
{
  std::cout << std::setw(4) << std::setfill('0') << std::setiosflags(std::ios::left) << pin << std::endl;
}

inline int generatePin()
{
  return rand() % 10000;
}

bool verifyUsername(const std::string& uName)
{
  size_t invalidTokenAt = uName.find_first_of(" \t"); // Look for an invalid token in the users input.
  if (invalidTokenAt != std::string::npos) // If an invalid token is found.
  {
    std::cout << "Invalid token at " << invalidTokenAt << ": '" << uName.at(invalidTokenAt) << "'" << std::endl;
    return false;
  }
  else
  {
    return true;
  }
}

Konto createAccount()
{
  while (true)
  {
    std::cout << "Pleaser enter an username of your choice:" << std::endl;
    std::string username;
    std::cin.clear();
    std::getline(std::cin, username, '\n');
    size_t invalidTokenAt = username.find_first_of(" \t"); // Look for an invalid token in the users input.
    if (!verifyUsername(username)) // If an invalid token is found.
    {
      continue;
    }

    // If there is no invalid token continue here
    std::cout << "Do you want to [g]enerate a random pin or [e]nter your own?" << std::endl;
    int userChoice = choice(std::vector<char>{'g', 'e'});
    while (userChoice == 0)
    {
      std::cout << "You entered an invalid choice. Please try again." << std::endl;

      userChoice = choice(std::vector<char>{'g', 'e'});
    }
    unsigned int pin = 0;
    switch (userChoice)
    {
    case 1:
    std::cout << "Generating pin... \n";
    pin = generatePin();
    std::cout << "Your pin is now: " << std::endl;
    printPin(pin);
    break;

    case 2:

    while (true)
    {
      std::cout << "Enter a pin of your choice (Four digits)." << std::endl;
      unsigned int pin = enterPin();
      std::cout << "Your pin is now: " << std::endl; // TODO: When entering 0001 as pin the program responds your pin is now: 1000 fix this. 
      printPin(pin);
      break;

    }
    break;


    default: // nop
    break;
    }
    std::cout << "You sucessfully created your account." << std::endl;
    return Konto(username, pin);
  }
}

int main()
{
  srand(time(0));
  rand(); // Discarding once because of a visual studio (bug?)
  // TODO
  // connect and register on/to adevice

  std::vector<Konto> konten;
  while (true)
  {
    // Get user input
    std::cout << "Select what you want to do:\n[L]og into your account\n[C]reate a new account\n[E]xit this application (Data will be lost)" << std::endl;
    char cInput;
    std::cin >> cInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail())
    {
      std::cin.clear();
    }

    switch (cInput)
    {
    case 'L':
    case 'l':
    {
      while (true)
      {
        std::cout << "Enter the name of your account." << std::endl;
        std::string sInput;
        std::getline(std::cin, sInput);
        if (!verifyUsername(sInput))
        {
          continue;
        }
        for (const Konto& iii : konten)
        {
          if (iii.getUsername() == sInput) // TODO: make this check case insensitive.
          {
            for (int failedPins = 0; failedPins < g_maxPinEntryTries; ++failedPins) // TODO: entering the correct pin does not work
            {
              std::cout << "You have " << g_maxPinEntryTries - failedPins << " tries left." << std::endl;
              std::cout << "Please enter your pin." << std::endl;
              unsigned int pin = enterPin();
              if (iii.checkPin(pin))
              {
                std::cout << "Welcome, " << iii.getUsername() << std::endl;
              }
              else
              {
                std::cout << "This pin was incorrect." << std::endl;
              }
            }
          }
        }
      }
      break;
    }

    case 'C':
    case 'c':
    konten.push_back(createAccount());
    break;

    case 'E':
    case 'e':
    return 0;

    default:
    break;
    }



    // TODO add selection on what the user wants to do.
    // Open a new account
    // read balance from existing one
    // add money from balance
    // remove money from balance
  }
}

// TODO 
// add integration to the test rack
// left/right light turns on when pin is correct/incorrect
// add alternative input via the buttons on the test rack
// optional: add support for the screen that is on the buttons to show e.g. the account balance