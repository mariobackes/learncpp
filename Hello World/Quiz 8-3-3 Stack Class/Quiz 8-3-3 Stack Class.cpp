// Quiz 8-3-3 Stack Class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include <iostream>

class Stack
{
public:
    Stack();
    ~Stack();
    void reset()
    {
        stackLength = 0;
        for (int i = 0; i < 10; ++i)
        {
            array[i] = 0;
        }
    }

    bool push(int value)
    {
        if (stackLength > 9)
        {
            return false;
        }
        else
        {
            array[stackLength] = value;
            ++stackLength;
            return true;
        }
    }

    int pop()
    {
        assert(stackLength > 0);
        int retVal = array[stackLength];
        array[stackLength] = 0;
        --stackLength;
        return retVal;
        
    }

    void print()
    {
        for (int i = 0; i < stackLength; ++i)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int array[10];
    int stackLength;

};

Stack::Stack()
{
}

Stack::~Stack()
{
}

int main()
{
    Stack stack;
    stack.reset();

    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}

