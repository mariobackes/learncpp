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
  Fraction(int num = 1, int denom = 1)
    : m_numerator{ num }
    , m_denominator{ denom }
  {
    reduce();
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

  friend std::ostream& operator<<(std::ostream& out, const Fraction fraction)
  {
    out << fraction.m_numerator;
    if (fraction.m_denominator != 1)
    {
      out << "/" << fraction.m_denominator;
    }
    return out;
  }

  friend std::istream& operator>> (std::istream& in, Fraction& fraction)
  {
    in >> fraction.m_numerator;
    in >> fraction.m_denominator;
    fraction.reduce();
    return in;
  }

  void print()
  {
    reduce();
    std::cout << m_numerator << "/" << m_denominator << std::endl;
  }
};

int main()
{

  Fraction f1;
  std::cout << "Enter fraction 1: ";
  std::cin >> f1;

  Fraction f2;
  std::cout << "Enter fraction 2: ";
  std::cin >> f2;

  std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';

  return 0;
}

