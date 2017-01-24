// LineCounter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

void printUsage(char filename[])
{
  std::cout << "Usage: '" << filename << " filename'" << std::endl;
}


int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printUsage(argv[0]);
    return 1;
  }
  
  std::ifstream file(argv[1]);

  if (!file)
  {
    std::cout << "File " << argv[1] << "not found. Exiting now..." << std::endl;
    return 2;
  }

  using buf_iter = std::istreambuf_iterator<char>;

  int lineCounter = 0;
  for (buf_iter i(file), e; i != e; ++i)
  {
    if (*i == '\n')
    {
      ++lineCounter;
    }
  }

  file.seekg(0, std::ios::end);
  int fileSize = 0;

  std::cout << "Counted " << lineCounter << " line(s)." << std::endl;
  std::cout << "The file is " << file.tellg() << " bytes long." << std::endl;
  

  return 0;
}

