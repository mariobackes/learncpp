// Quiz 12-x-2 Virtual Functions - Shape.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

int getLargestRadius(std::vector<Shape*>& v)
{
  int largest = 0;
  for (unsigned int i = 0; i < v.size(); ++i)
  {
    Circle* c = dynamic_cast<Circle*>(v[i]);
    if (!c)
    {
      continue;
    }
    if (c->getRadius() > largest)
    {
      largest = c->getRadius();
    }
  }
  return largest;
}

int main()
{
  std::vector<Shape*> v;
  v.push_back(new Circle(Point(1, 2, 3), 7));
  v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
  v.push_back(new Circle(Point(4, 5, 6), 3));

  // print each shape in vector v on its own line here

  std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

                                                                         // delete each element in the vector here
  for (int i = 0; i < v.size(); ++i)
  {
    delete[] v[i];
  }
}

