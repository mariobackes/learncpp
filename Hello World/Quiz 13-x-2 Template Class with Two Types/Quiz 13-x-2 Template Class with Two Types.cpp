// Quiz 13-x-2 Template Class with Two Types.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template<typename T, typename T1>
class Pair
{
private:
  T   m_val1;
  T1  m_val2;
public:
  Pair(const T& val1, const T1& val2)
    : m_val1{ val1 }
    , m_val2{ val2 }
  {

  }

  T  first()  const { return m_val1; }
  T  first()        { return m_val1; }
  T1 second() const { return m_val2; }
  T1 second()       { return m_val2; }
};

template<typename T1>
class StringValuePair : public Pair<std::string, T1>
{
public:
  StringValuePair(const std::string& key, const T1& value)
    : Pair<std::string, T1>(key, value)
  {

  }
};

int main()
{
  Pair<int, double> p1(5, 6.7);
  std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

  const Pair<double, int> p2(2.3, 4);
  std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

  return 0;
}

