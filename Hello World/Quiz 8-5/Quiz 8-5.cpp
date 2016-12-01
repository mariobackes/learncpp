// Quiz 8-5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Ball
{
public:
    // Constructors:
    Ball()
    {
        m_color = ("Black");
        m_radius = (10.0);
    }
    Ball(int radius)
    {
        m_radius = radius;
        m_color = "Black";
    }
    Ball(std::string color, int radius = 10.0)
    {
        m_color = color;
        m_radius = radius;
    }

    // Destructor:
    ~Ball();

    /////////////////

    void print()
    {
        std::cout << "Color: " << m_color << ", radius: " << m_radius << std::endl;
    }

private:
    std::string m_color;
    double      m_radius;
};

Ball::~Ball()
{
}

int main()
{
    Ball def;
    def.print();

    Ball blue("blue");
    blue.print();

    Ball twenty(20.0);
    twenty.print();

    Ball blueTwenty("blue", 20.0);
    blueTwenty.print();

    return 0;
}

