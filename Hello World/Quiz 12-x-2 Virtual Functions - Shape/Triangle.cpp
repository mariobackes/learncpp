#include "stdafx.h"


Triangle::Triangle(Point a, Point b, Point c)
  : m_a { a }
  , m_b { b }
  , m_c { c }
{
}

std::ostream & Triangle::print(std::ostream & out) const
{
  out << "Triangle" << m_a << ", " << m_b << ", " << m_c << std::endl;
  return out;
}


Triangle::~Triangle()
{
}
