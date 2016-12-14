// Quiz 9-X-4 Fixed point number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class FixedPoint2
{
private:
  int m_firstPart;
  int m_fractionalPart;
public:  
  FixedPoint2(int val1 = 0, int val2 = 0)
    : m_firstPart{ val1 }
    , m_fractionalPart{ val2 }
  {
    if (val2 < -99 || val2 > 99)
    {
      std::cout << "Fractional part in default constructor was out of bounds." << std::endl;
      std::cout << "Setting fractional part to 0." << std::endl;
      m_fractionalPart = 0;
    }
  }
  FixedPoint2(double value)
    : m_firstPart{ static_cast<int>(value) }
  {

    //std::cout << "Input: " << value << std::endl;
    m_fractionalPart = static_cast<int>((value - m_firstPart) * 100 + (value < 0 ? -0.5 : 0.5));

    //std::cout << "output: " << m_firstPart << " " << m_fractionalPart << std::endl;
  }

  FixedPoint2(int value)
    : m_firstPart{ value }
    , m_fractionalPart{ 0 }
  {
  }



  friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& obj)
  {
  /*  if (obj.m_firstPart < 0 || obj.m_fractionalPart < 0)
    {
      out << "-" << obj.m_firstPart << "." << (obj.m_fractionalPart < 10 ? "0" : "") << obj.m_fractionalPart;
    }
    else
    {
      out << obj.m_firstPart << "." << (obj.m_fractionalPart < 10 ? "0" : "") << obj.m_fractionalPart;
    }*/

    if (obj.m_firstPart == 0 && obj.m_fractionalPart < 0)
    {
      out << "-";
    }
    out << obj.m_firstPart << ".";
    if (obj.m_fractionalPart < 0)
    {
      
      out << (obj.m_fractionalPart > -10 ? "0" : "")  << -obj.m_fractionalPart;
    }
    else
    {
      out << (obj.m_fractionalPart < 10 ? "0" : "") << obj.m_fractionalPart;
    }

    return out;
  }

  FixedPoint2 operator-() const
  {
    return FixedPoint2(-m_firstPart, -m_fractionalPart);
  }

  FixedPoint2 operator+(const FixedPoint2& operand)
  {
    double temp = operand.m_firstPart + (operand.m_fractionalPart / 100) + m_firstPart + (m_fractionalPart / 100);
    return FixedPoint2(temp);
  }

  friend std::istream& operator >> (std::istream& in, FixedPoint2& point)
  {
    double value;
    in >> value;
    point = FixedPoint2(value);

    return in;
  }

  operator double()
  {
    return m_firstPart + (m_fractionalPart / 100);
  }

};

void testAddition()
{
  std::cout << std::boolalpha;
  std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
  std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
  std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
  std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
  std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
  std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
  std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
  std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
  testAddition();

  FixedPoint2 a(34, 56);
  std::cout << a << '\n';

  std::cout << -a << '\n';

  std::cout << "Enter a number: "; // enter 5.678
  std::cin >> a;

  std::cout << "You entered: " << a << '\n';

  return 0;
}

