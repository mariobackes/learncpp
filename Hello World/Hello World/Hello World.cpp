// Hello World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <ctime>


class Point3d
{
public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }
    void print()
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << std::endl;
    }

private:
    int m_x;
    int m_y;
    int m_z;
};

int main()
{
	//std::cout << "Hello, world!" << std::endl;
  /*
   * unsigned int x;
   * std::cout << "Enter an integer!" << std::endl;
   * std::cin >> x;
   * std::cout << x << std::endl;
   */
    /*
    unsigned short count = 100;

    while (count >= 0)
    {
        std::cout << count << " ";
        Sleep(1);
        --count;
    }
    */

    Point3d point;
    point.setValues(1, 2, 3);
    point.print();
    
    
    
    /*
    srand(static_cast<unsigned int>(time(0)));
    rand();
    std::cout << rand();
    */

  return 0;
}

