#include "stdafx.h"
#include "Shape.h"


Shape::~Shape()
{
}

std::ostream& operator<<(std::ostream& out, const Shape& obj)
{
  obj.print(out);
  return out;

  // Works just as fine, but the choice above is easier to read if you don't know what print returns.
  // return obj.print(out); 
}
