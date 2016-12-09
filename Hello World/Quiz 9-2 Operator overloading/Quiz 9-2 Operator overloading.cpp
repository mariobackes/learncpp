// Quiz 9-2 Operator overloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Declare a operator overloading function via the friend keyword in public or private space?

class Fraction
{
private:
  int m_numerator;
  int m_denominator;

  int gcd(int a, int b)
  {
    return b == 0 ? a : gcd(b, a % b);
  }

  void reduce()
  {
    int foo = gcd(m_numerator, m_denominator);
    m_numerator /= foo;
    m_denominator /= foo;
  }
  
public:
  Fraction(int num, int denom)
    : m_numerator{ num }
    , m_denominator{ denom }
  {
  }

  friend Fraction operator*( const Fraction& lhs, const Fraction& rhs)
  {
    int numerator = lhs.m_numerator* rhs.m_numerator;
    int denominator = lhs.m_denominator* rhs.m_denominator;
    return Fraction(numerator, denominator);
  }

  friend Fraction operator*(const Fraction& lhs, const int rhs)
  {
    int numerator = lhs.m_numerator * rhs;
    return Fraction(numerator, lhs.m_denominator);
  }

  friend Fraction operator*(const int rhs, const Fraction& lhs)
  {
    int numerator = lhs.m_numerator * rhs;
    return Fraction(numerator, lhs.m_denominator);
  }

  void print()
  {
    reduce();
    std::cout << m_numerator << "/" << m_denominator << std::endl;
  }
};

int main()
{
  Fraction f1(2, 5);
  f1.print();

  Fraction f2(3, 8);
  f2.print();

  Fraction f3 = f1 * f2;
  f3.print();

  Fraction f4 = f1 * 2;
  f4.print();

  Fraction f5 = 2 * f2;
  f5.print();

  Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.print();

  return 0;
}

