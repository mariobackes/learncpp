// StringPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>

// This string permutation program would be useless, it is annoying to write it and just too hard. Also I hate writing algorithms.
// UNFINISHED

// Also the solution on tha page I found this challenge on is recursive. Which makes it exponentially harder for me to understand.

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage: '" << argv[0] << " string'" << std::endl;
  }

  std::string string = argv[1];
  for (int i = 1; i < (string.length() - 1); ++i)
  {
    std::swap(string[i - 1], string[i]);
  }
  std::cout << string << std::endl;

  // Current output is a dereferenced null ptr. Might come back in a few months to fix this program.
  // Ressources: 
  // http://stackoverflow.com/questions/1995328/are-there-any-better-methods-to-do-permutation-of-string
  // http://www.cprogramming.com/challenges/permute.html
  
  return 0;
}

