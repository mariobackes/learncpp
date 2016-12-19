// Quiz 11-4 Basic Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Fruit
{
private:
  std::string m_name;
  std::string m_color;
public:
  Fruit(std::string name, std::string color)
    : m_name{ name }
    , m_color{ color }
  {

  }
  std::string getName () const { return m_name;  }
  std::string getColor() const { return m_color; }
};

class Apple : public Fruit
{
private:
  double m_fiber;
public:
  Apple(std::string name, std::string color, double fiber)
    : Fruit(name, color)
    , m_fiber{ fiber }
  {

  }

  friend std::ostream& operator<<(std::ostream& out, const Apple& apple)
  {
    out << "Name: " << apple.getName() << ", Color: " << apple.getColor() << ", Fiber: " << apple.m_fiber << std::endl;
    return out;
  }
  
};

class Banana : public Fruit
{
private:

public: 
  Banana(std::string name, std::string color)
    : Fruit(name, color)
  {

  }
  friend std::ostream& operator<<(std::ostream& out, const Banana& banana)
  {
    out << "Name: " << banana.getName() << ", Color: " << banana.getColor() << std::endl;
    return out;
  }
};

int main()
{
  const Apple a("Red delicious", "red", 4.2);
  std::cout << a;

  const Banana b("Cavendish", "yellow");
  std::cout << b;

  return 0;
}

