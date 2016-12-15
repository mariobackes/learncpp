// Quiz 9-X-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Write your own integer array class named IntArray from scratch.
// Do not use std::array or std::vector!
// Size of the array shall be passed in when it is created.
// The array should be dynamically allocated.
// Use assert statements to guard against bad data.

class IntArray
{
private:
  int m_arraySize = 0;
  int* m_array = nullptr;

public:
  // Constructor
  IntArray(int arraySize)
    : m_arraySize(arraySize)
  {
    assert(arraySize > 0);
    m_array = new int[arraySize] { 0 };
    std::cout << "Default constructor" << std::endl;
  }

  // Copy constructor 
  IntArray(const IntArray& ary)
    : m_array(new int[m_arraySize])
    , m_arraySize(ary.m_arraySize)
  {
    std::cout << "Copy constructor" << std::endl;
    for (int i = 0; i < m_arraySize; ++i)
    {
      m_array[i] = ary.m_array[i];
    }
  }

  // Destructor
  ~IntArray()
  {
    std::cout << "address to delete:" << m_array <<std::endl;
    delete[] m_array;
  }

  IntArray& operator= (const IntArray& ary)
  {
    if (this == &ary)
    {
      return *this;
    }
    if (m_array)
    {
      std::cout << "Deleting in operator=" << m_array << std::endl;
      delete[] m_array;
    }
    m_arraySize = ary.m_arraySize;
    m_array = new int[m_arraySize];
    for (int i = 0; i < m_arraySize; ++i)
    {
      m_array[i] = ary.m_array[i];
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& out, const IntArray& ary)
  {
    for (int i = 0; i < ary.m_arraySize; ++i)
    {
      out << ary.m_array[i] << " ";
    }
    return out;
  }

  int& operator[](const int index)
  {
    // Use assert only to debug
    assert(index < m_arraySize);
    // std::cout << "Assert skipped" << std::endl;
    return m_array[index];
  }

  // For const objects
  const int& operator[] (const int index) const
  {
    assert(index < m_arraySize);
    return m_array[index];
  }

};



IntArray fillArray()
{
  IntArray a(5);
  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;
 
  return a;
}

int main()
{
  IntArray a = fillArray();
  std::cout << a << std::endl;

  IntArray b(2);
  a = a;
  b = a;
  
  std::cout << b << '\n';

  return 0;
}