// Quiz 9-9 Overloading the parenthesis operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Mystring
{
private:
  std::string m_string;
public:
  Mystring(const std::string string = "")
    : m_string{ string }
  {

  }

  std::string operator()(int startIndex, int amountOfChars)
  {
    std::string retVal;
    for (int i = 0; amountOfChars > i; ++i)
    {
      retVal += m_string[startIndex + i];
    }
    return retVal;
  }
};

int main()
{
  Mystring string("Hello, world!");
  std::cout << string(7, 5); // start at index 7 and return 5 characters

  return 0;
}

