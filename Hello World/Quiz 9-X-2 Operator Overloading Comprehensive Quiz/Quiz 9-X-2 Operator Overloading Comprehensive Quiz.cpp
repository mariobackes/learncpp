// Quiz 9-X-2 Operator Overloading Comprehensive Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class Average
{
private:
  int32_t sumOfAllNumbers;
  int8_t numbersSeen;

public:
  Average()
    : sumOfAllNumbers{ 0 }
    , numbersSeen{ 0 }
  {

  }

  Average operator+=(int value)
  {
    sumOfAllNumbers += value;
    ++numbersSeen;
    return *this;
  }

  friend std::ostream& operator<< (std::ostream& out, const Average avg)
  {
    out << static_cast<double>(avg.sumOfAllNumbers) / avg.numbersSeen;

    // To allow chaining.
    return out;
  }

  Average& operator=(const Average& avg)
  {
    // In case of self assignment just return *this pointer to prevent dangling pointers.
    // Also no operation is needed then since the two objects have the same value anyways.
    if (this == &avg)
    {
      return *this;
    }

    numbersSeen = avg.numbersSeen;
    sumOfAllNumbers = avg.sumOfAllNumbers;
    return *this;
  }

};


int main()
{
  Average avg;

  avg += 4;
  std::cout << avg << '\n'; // 4 / 1 = 4

  avg += 8;
  std::cout << avg << '\n'; // (4 + 8) / 2 = 6

  avg += 24;
  std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

  avg += -10;
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

  (avg += 6) += 10; // 2 calls chained together
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

  Average copy = avg;
  std::cout << copy << '\n';

  return 0;
}

