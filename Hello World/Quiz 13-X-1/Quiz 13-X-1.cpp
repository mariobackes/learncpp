// Quiz 13-X-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template<typename T>
class Pair1
{
private:
  T m_val1;
  T m_val2;
public:
  Pair1(T val1, T val2)
    : m_val1{ val1 }
    , m_val2{ val2 }
  {

  }

  T first() const
  {
    return m_val1;
  }

  T second() const
  {
    return m_val2;
  }

};



int main()
{
  Pair1<int> p1(5, 8);
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair1<double> p2(2.3, 4.5);
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  return 0;
}

