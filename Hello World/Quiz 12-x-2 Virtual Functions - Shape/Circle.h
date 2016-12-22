#pragma once
#include "Shape.h"
#include "Point.h"
class Circle : public Shape
{
private:
  Point m_center;
  int   m_radius;

public:
  Circle(Point center, int radius);

  std::ostream& print(std::ostream& out) const override;

  int getRadius()
  {
    return m_radius;
  }

  virtual ~Circle();
};

