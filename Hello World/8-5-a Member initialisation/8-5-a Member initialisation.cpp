// 8-5-a Member initialisation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


class Foo
{
public:
    Foo(int x)
    {
        std::cout << "Foo " << x << std::endl;
    }

};


class Bar
{
private:
    Foo m_foo;
public:
    Bar(int y)
        : m_foo(y - 1)  // Call Foo(int) constructor to initialize member m_foo
    {
        std::cout << "Bar " << y << std::endl;
    }
};


int main()
{
    Bar b(5);
    return 0;
}

