// Quiz 9-8 Overloading the subscript operator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct StudentGrade
{
  std::string name;
  char        grade;

  StudentGrade(const std::string& name)
    : name{std::move(name)}
    , grade{'?'}
  {
    
  }
};

class GradeMap
{
private:
  std::vector<StudentGrade> m_vector;
public:
  GradeMap()
  {
  }
  char& operator[](const std::string& name)
  {
    for (StudentGrade element : m_vector)
    {
      if (element.name == name)
      {
        return element.grade;
      }
    }
    m_vector.push_back(StudentGrade(name));
    return m_vector.back().grade;
  }
};

int main()
{
  GradeMap grades;
  //grades["Joe"] = 'A';
  //grades["Frank"] = 'B';
  std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
  std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}

