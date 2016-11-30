// strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void cinStringsProblems()
{
    using namespace std;
    cout << "Enter your full name: ";
    string name;
    cin >> name;    // This will not work, because cin breaks on whitespace.
                    // After the whitespace the second part of the name stays in the cin buffer and waits for the next call to cin.


    cout << "Enter your age: ";
    string age;
    cin >> age;

    cout << "Your name is " << name << " and your age is " << age << "." <<  endl;
}


void getlineToInputText()
{
    using namespace std;
    cout << "Enter your full name: ";
    string fullName;
    getline(cin, fullName); //Reads a full line of text.

    cout << "Enter your age: ";
    string age;
    getline(cin, age);

    cout << "Your name is " << fullName << " and your age is " << age << "." << endl;
}

void mixingCinAndGetline()
{
    using namespace std;
    cout << "Pick 1 or 2: ";
    int choice;
    cin >> choice;  // If you enter a numeric value using cin, it will capture the newline symbol along with the entered number (e.g '2\n')
                    // The 2 will be extracted to the variable "choice, leaving the newline at the input stream, and figures we entered an empty string.

                    // After reading a numeric value with cin, remove the trailing newline from the stream.
                    // This is shown in the cinIgnore() function.

    cout << "Now enter your name: ";
    string name;
    getline(cin, name);

    cout << "Hello, " << name << ", you picked " << choice << endl;
}

void cinIgnore()
{
    // std::cin.ignore(32767, '\n');
    // This ^ line of code will ignore up to 32767 characters until a \n is removed.

    using namespace std;
    cout << "Pick 1 or 2: ";
    int choice;
    cin >> choice;

    cin.ignore(32767, '\n');

    cout << "Now enter your name: ";
    string name;
    getline(cin, name);
    cout << "Hello, " << name << ", you picked " << choice << endl;
}

int main()
{
    std::string myName = "Alex";
    myName = "Mario";
    std::cout << "My name is: " << myName << std::endl;

    //cinStringsProblems();

    getlineToInputText();

    mixingCinAndGetline();

    cinIgnore();

    return 0;
}

