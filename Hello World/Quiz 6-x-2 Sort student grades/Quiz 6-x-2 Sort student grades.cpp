// Quiz 6-x-2 Sort student grades.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


struct Student
{
    std::string name;
    unsigned int grade;
};



int main()
{
    std::cout << "Enter the amount of students you want to enter: ";
    int amountOfStudents;
    while (true)
    {
        std::cin >> amountOfStudents;
        if (std::cin.fail())
        {
            std::cout << "Invalid input, try again." << std::endl;
            std::cin.ignore(32767, '\n');
            std::cin.clear();
        }
        else
        {
            break;
        }
    }
    int counter = 1;
    std::vector<Student> classroom(amountOfStudents);

    for(auto& i : classroom)
    {
        std::cout << "Enter the name of student #" << counter << " :" << std::endl;
        counter++;
        std::cin >> i.name;
        std::cout << "Enter the Grade (0 - 100) of Student " << i.name << "." << std::endl;
        std::cin >> i.grade;
        if (std::cin.fail() || i.grade > 100 )      /* Unsigned int, no need to check for i < 0 */
        {
            std::cout << "Invalid input, exiting..." << std::endl;
            exit(1);
        }
    }

    for (int startIndex = 0; startIndex < amountOfStudents; ++startIndex)
    {
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < amountOfStudents; ++currentIndex)
        {
            if (classroom[currentIndex].grade < classroom[smallestIndex].grade)
            {
                smallestIndex = currentIndex;
            }
        }
        std::swap(classroom[startIndex], classroom[smallestIndex]);
    }
    for(const auto& i : classroom)
    {
        std::cout << i.name << " got a grade of " << i.grade << "." << std::endl;
    }

    return 0;
}

