// years_per_letter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

std::string getName()
{
    using namespace std;
    cout << "Enter your full name: " << endl;
    string name;
    getline(cin, name);
    return name;
}

int getAge()
{
    using namespace std;
    cout << "Enter your age: " << endl;
    int age;
    cin >> age;
    return age;
}

bool ageIsPositive(int age)
{
    bool retVal;
    if (age > 0)
    {
        retVal = true;
    }
    else
    {
        retVal = false;
    }
    return retVal;
}

int main()
{
    using namespace std;
    string name;
    name = getName();
    int age;
    age = getAge();
    if (!ageIsPositive(age))
    {
        cout << "Invalid input detected. Did you enter zero or a negative number?" << endl << "Exiting now." << endl;
    }
    float agePerLetter;
    agePerLetter = static_cast<float>(age) / name.length();
    cout << "You lived " << agePerLetter << " years for each letter in your name." << endl;
    return 0;
}

