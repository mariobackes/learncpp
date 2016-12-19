// Quiz 11-x-2 Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Fruit
{
private:

protected:
  std::string m_name;
  std::string m_color;
public:
  Fruit(std::string color, std::string name)
    : m_name{ name }
    , m_color{ color }
  {

  }

  std::string getName()   { return m_name; }
  std::string getColor()  { return m_color; }
};

class Apple : public Fruit
{
private:

protected:

public:
  Apple(std::string color = "green", std::string name = "Apple")
    : Fruit( color, name)
  {

  }

};

class Banana : public Fruit
{
private:

protected:

public:
  Banana(std::string color = "Yellow", std::string name = "Banana")
    : Fruit(color, name )
  {

  }
};

class GrannySmith : public Apple
{
private:

protected:

public:
  GrannySmith(std::string color = "green", std::string name = "GrannySmith Apple")
    : Apple(color, name)
  {

  }

};

int main()
{
  Apple a("red");
  Banana b;
  GrannySmith c;

  std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
  std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
  std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

  return 0;
}

