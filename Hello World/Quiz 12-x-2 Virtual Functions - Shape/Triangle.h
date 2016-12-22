#pragma once
#include "Shape.h"
#include "Point.h"

class Triangle : public Shape
{
private:
  Point m_a;
  Point m_b;
  Point m_c;

public:
  Triangle(Point a, Point b, Point c);
  std::ostream& print(std::ostream& out) const override;

  virtual ~Triangle();
};