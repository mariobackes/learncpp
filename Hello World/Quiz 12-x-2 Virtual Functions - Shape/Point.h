#pragma once
#include <iostream>

class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;
 
public:
  Point(int x, int y, int z);
 
  friend std::ostream& operator<<(std::ostream& out, const Point& p);
};