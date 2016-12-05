// Quiz 8-x-2.cpp : Defines the entry point for the console application.
// TODO: Write a destructor for this class.

#include "stdafx.h"


class HelloWorld
{
private:
    char* m_data;

public:
    HelloWorld()
    {
        m_data = new char[14]{ "Hello, World!" };
    }

    ~HelloWorld()
    {
        delete[] m_data;
    }
};


int main()
{
    return 0;
}

