#include "stdafx.h"
#include "Circle.h"


Circle::Circle(Point center, int radius)
  : m_center { center }
  , m_radius { radius }
{

}

std::ostream & Circle::print(std::ostream & out) const
{
  out << "Center: " << m_center << ", radius: " << m_radius << std::endl;
  return out;
}

Circle::~Circle()
{
}
