// hi-lo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Generate random number between min and max (inclusive)
// Assumes srand() has already been called
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void playHiLo()
{
    int solution = getRandomNumber(g_lo, g_hi);     // A random number between g_lo and g_hi. (Should be 0 and 100)
    int number = g_hi + 1;                       // Having the number out of reach, so the for loop can not be skipped.
    int counter = 1;
    for (; counter <= g_triesPerRun && solution != number; ++counter)
    {
        number = getUserInput();
        std::cout << "Guess #" << counter << ": " << number << std::endl;
        if (solution < number)
        {
            std::cout << "Your guess is too high." << std::endl;
        }
        else if (solution > number)
        {
            std::cout << "Your guess is too low." << std::endl;
        }
        else // (number == solution)
        {
            std::cout << "Correct! You win!" << std::endl;
        }
    }
    if (counter > g_triesPerRun)
    {
        std::cout << "Sorry, you lost. The correct number was " << solution << std::endl;
    }
    
    
}

int getUserInput()
{
    while (true)
    {
        std::cout << "Enter an integer value: ";
        int input;
        std::cin >> input;

        // Check for failed extraction.
        if (std::cin.fail())    // Has a previous execution failed?
        {
            std::cin.clear();               // Get cin back to 'normal mode'
            std::cin.ignore(32767, '\n');   // Remove any input in the cin-buffer
            std::cout << "That input is invalid. Please try again." << std::endl;
        }
        else
        {
            std::cin.ignore(32767, '\n');   // Remove leftover input from the buffer.
            return input;
        }
    }
}

bool playAgain()
{
    while (true)    // Loop until valid input is entered.
    {
      std::cout << "Do you want to play again?" << std::endl << "y = yes | n = no" << std::endl;
      char yesNo;
      std::cin >> yesNo;
      std::cin.ignore(32767, '\n');     // Remove leftover input from the buffer.

      // Check whether the user entered valid input 
      bool retVal;
      if (yesNo == 'y' || yesNo == 'Y' )
      {
          return true;
      }
      else if (yesNo == 'n' || yesNo == 'N')
      {
          return false;
      }
      else
      {
          std::cout << "That input is invalid. Please try again." << std::endl;
      }
    }
}

int main()
{
    bool again = true;
    srand(static_cast<int>(time(0)));
    rand(); // rand() needs to be discarded once after seeding it. Thank you, Visual Studio.
    while (again)
    {
        std::cout << "Let's play a game. I'm thinking of a number between " << g_lo << " and " << g_hi << ". You have " << g_triesPerRun << " tries to guess which number it is." << std::endl;
        playHiLo();
        again = playAgain();
    }
    std::cout << "Thank you for playing" << std::endl;
    return 0;
}

