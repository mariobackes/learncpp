// Bankautomat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Konto.h"
#include "Bankautomat.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <DeviceStackClient\KeepAliveSettings.h>
#include <DeviceStackClient\devicestackclient.h>
#undef max



const int g_maxPinEntryTries = 5;

void SetConfiguration()
{
  return;
}

int Choice(std::vector<char> choices)
{
  char input;
  std::cin >> input;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (std::cin.fail())
  {
    std::cin.clear();
  }
  input = tolower(input);
  int i = 0;
  for (const auto& character : choices)
  {
    ++i;
    if (character == input)
    {
      return i;
    }
  }
  return 0; // If no match is found
}

// String Case Insensitive Compare
bool SciCompare(const std::string& lhs, const std::string& rhs)
{
  if (lhs.size() != rhs.size())
  {
    return false;
  }
  for (unsigned int i = 0; i < lhs.size(); ++i)
  {
    if (tolower(lhs[i]) != tolower(rhs[i]))
    {
      return false;
    }
  }
  return true;
}

unsigned int EnterPin()
{
  std::string sPin;
  while (true)
  {

    //std::getline(std::cin, sPin);
    //std::cin >> sPin;

    char ch = _getch();
    while (ch != 13) // The ASCII code for ener is 13
    {
      sPin.push_back(ch);
      std::cout << "*";
      ch = _getch();
    }
    std::cout << std::endl;


    //std::cin.ignore(32767, '\n');
    if (sPin.size() != 4)
    {
      std::cout << "The pin you entered is not four digits long, please try again" << std::endl;
      sPin = "";
      continue;
    }
    else
    {
      bool flag = false;
      for (const auto& iii : sPin)
      {
        if (iii < '0' || iii > '9')
        {
          flag = true;
          break;
        }
      }
      if (flag)
      {
        std::cout << "Input was invalid, try again." << std::endl;
        continue;
      }
      return std::stoi(sPin);
    }
  }
}

inline bool PinIsValid(unsigned int pin)
{
  return pin > 9999 ? false : true;
}

inline void PrintPin(unsigned int pin)
{
  std::cout << std::setw(4) << std::setfill('0') << std::setiosflags(std::ios::right) << pin << std::endl;
}

inline int GeneratePin()
{
  return rand() % 10000;
}

bool VerifyUsername(const std::string& uName)
{
  size_t invalidTokenAt = uName.find_first_of(" \t"); // Look for an invalid token in the users input.
  if (invalidTokenAt != std::string::npos) // If an invalid token is found.
  {
    std::cout << "Invalid token at " << invalidTokenAt << ": '" << uName.at(invalidTokenAt) << "'" << std::endl;
    return false;
  }
  else
  {
    return true;
  }
}

void SaveData(const std::vector<Konto>& konten, std::string filename = "savedata.txt")
{
  std::cout << "Saving data to: " << filename << std::endl;
  std::ofstream ofs(filename);
  if (ofs.is_open())
  {
    for (const auto& konto : konten)
    {
      ofs << konto.GetUsername() << " " << konto.GetPin() << " " << konto.GetBalance() << "\n";
    }
    std::cout << "Data successfully saved." << std::endl;
  }
  else
  {
    std::cout << "Can not open open " << filename << std::endl;
  }
}

void LoadData(std::vector<Konto>& konten, std::string filename = "savedata.txt")
{
  std::cout << "Loading data from file: " << filename << std::endl;
  std::ifstream ifs(filename);
  if (ifs.is_open())
  {
    std::string line;
    while (std::getline(ifs, line))
    {
      std::string username;
      std::string pin;
      std::string balance;
      bool uNameDone = false;
      bool pinDone = false;
      for (const char ch : line)
      {
        if (ch != ' ' && !uNameDone)
        {
          username += ch;
          continue;
        }
        if (!uNameDone)
        {
          uNameDone = true;
          continue;
        }
        if (ch != ' ' && !pinDone)
        {
          pin += ch;
          continue;
        }
        if (!pinDone)
        {
          pinDone = true;
          continue;
        }
        if (ch != ' ')
        {
          balance += ch;
          continue; // just to be consistent
        }
      }
      konten.push_back(Konto(username, std::stoi(pin), std::stol(balance)));
    }
    std::cout << "File successfully loaded." << std::endl;
  }
  else
  {
    std::cout << "Can not open file." << std::endl;
  }
}

Konto CreateAccount(const std::vector<Konto>& konten)
{
  while (true)
  {
    std::cout << "Pleaser enter a username of your choice:" << std::endl;
    std::string username;
    std::cin.clear();
    std::getline(std::cin, username, '\n');
    size_t invalidTokenAt = username.find_first_of(" \t"); // Look for an invalid token in the users input.
    if (!VerifyUsername(username)) // If an invalid token is found.
    {
      continue;
    }
    bool usernameTaken = false;
    for (const Konto& konto : konten)
    {
      if (username == konto.GetUsername())
      {
        std::cout << "This username is already in use. Please choose another username." << std::endl;
        usernameTaken = true;
      }
    }
    if (usernameTaken) { continue; }

    // If there is no invalid token continue here
    std::cout << "Do you want to [g]enerate a random pin or [e]nter your own?" << std::endl;
    int userChoice = Choice({ 'g', 'e' });
    while (userChoice == 0)
    {
      std::cout << "You entered an invalid choice. Please try again." << std::endl;

      userChoice = Choice({ 'g', 'e' });
    }
    unsigned int pin = 0;
    switch (userChoice)
    {
    case 1:
    std::cout << "Generating pin... \n";
    pin = GeneratePin();
    std::cout << "Your pin is now: " << std::endl;
    PrintPin(pin);
    break;

    case 2:

    while (true)
    {
      std::cout << "Enter a pin of your choice (Four digits)." << std::endl;
      pin = EnterPin();
      std::cout << "Your pin is now: " << std::endl;
      PrintPin(pin);
      break;

    }
    break;


    default: // nop
    break;
    }
    std::cout << "You sucessfully created your account." << std::endl;
    return Konto(username, pin);
  }
}

void loggedIn(Konto& konto)
{
  while (true)
  {
    bool backToSelection = false;
    std::cout << "Select what you want to do:\n[P]ay in/out\n[S]ee your current balance\n[L]og out" << std::endl;
    int loginMenuChoice = Choice(std::vector<char>{'p', 's', 'l'});
    while (loginMenuChoice == 0)
    {
      std::cout << "You entered an invalid choice. Please try again." << std::endl;
      loginMenuChoice = Choice({ 'p', 's', 'l' });
    }
    switch (loginMenuChoice)
    {
    case 1: // pay in/out
    {
      std::cout << "Do you want to pay money [i]n or [o]ut?" << std::endl;
      int inOutChoice = Choice({ 'i', 'o' });
      while (inOutChoice == 0)
      {
        std::cout << "You entered an invalid choice. Please try again." << std::endl;
        loginMenuChoice = Choice({ 'i', 'o' });
      }
      std::cout << "Please enter the amount of money you want to transfer." << std::endl;
      double dTransferAmount;
      while (!backToSelection)
      {
        std::cin >> dTransferAmount;
        if (std::cin.fail())
        {
          std::cin.ignore(32727, '\n');
          std::cin.clear();
          std::cout << "Invalid input. Try again." << std::endl;
          dTransferAmount = 0;
          continue;
        }
        if (inOutChoice == 1)
        {
          konto += dTransferAmount;
        }
        if (inOutChoice == 2)
        {
          if (konto.GetBalance() < dTransferAmount)
          {
            std::cout << "This transaction would bring your balance below 0. No transaction will be made." << std::endl;
          }
          else
          {
            konto -= dTransferAmount;
          }
        }
        dTransferAmount = 0;
        std::cout << "Your balance is now: " << konto.GetBalance() << std::endl;
        backToSelection = true;
      }
      break;
    }
    case 2: // see balance
    std::cout << "Your current balance is: " << konto.GetBalance() << std::endl;

    break;

    case 3: // logout 
    std::cout << "Logging out..." << std::endl;
    return;
    break;

    default:  // No op. This line should never be executed.
    break;
    }
  }
}

void printError(const Gira::IDeviceStackClient::ErrorCode errCode)
{
  switch (errCode)
  {
  case 0:
  std::cout << "No error" << std::endl;
  break;
  case 1:
  std::cout << "General error" << std::endl;
  break;
  case 2:
  std::cout << "Internal device stack error" << std::endl;
  break;
  case 3:
  std::cout << "Invalid device manager state" << std::endl;
  break;
  case 100:
  std::cout << "Application not registered" << std::endl;
  break;
  case 101:
  std::cout << "Invalid registration request" << std::endl;
  break;
  case 102:
  std::cout << "Unknown Command" << std::endl;
  break;
  case 103:
  std::cout << "Invalid command parameter" << std::endl;
  break;
  case 110:
  std::cout << "Invalid Object ID" << std::endl;
  break;
  case 111:
  std::cout << "Unknown Object ID" << std::endl;
  break;
  case 112:
  std::cout << "Unknown Object Name" << std::endl;
  break;
  case 1001:
  std::cout << "General Client side Error" << std::endl;
  break;
  case 1002:
  std::cout << "Internal Client side Error" << std::endl;
  break;
  }
}

int main()
{
  srand(time(0));
  rand(); // Discarding once because of a visual studio (bug?)
  bool deviceConnceted = true;

  std::string uri = "wss://192.168.137.30:4432/gds/api";

  std::unique_ptr<Gira::IDeviceStackClient> client = Gira::CreateDeviceStackClient(uri, "device", "device");
  if (!client)
  {
    std::cout << "Could not connect to device." << std::endl;
    deviceConnceted = false;
  }
  if (!client->RegisterApplication("MBA"))
  {
    deviceConnceted = false;
    std::cout << "Registration on device failed." << std::endl;
    printError(client->GetLastError().Code());
    return 2;
  }
  else
  {
    std::cout << "Registration on device successfull" << std::endl;
  }
  // TODO: connect and register on/to adevice

  SetConfiguration();


  std::vector<Konto> konten;
  LoadData(konten);
  bool backToMainMenu = false;
  while (true)
  {
    backToMainMenu = false;
    // Get user input
    std::cout << "Select what you want to do:\n[L]og into your account\n[C]reate a new account\n";
    std::cout << "[E]xit this application" << std::endl;
    char cInput;
    std::cin >> cInput;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::cin.fail())
    {
      std::cin.clear();
    }

    switch (cInput)
    {
    case 'L':
    case 'l':
    {
      while (!backToMainMenu)
      {
        std::cout << "Enter the name of your account." << std::endl;
        std::string sInput;
        std::getline(std::cin, sInput);
        if (!VerifyUsername(sInput))
        {
          continue;
        }
        for (Konto& iii : konten)
        {
          if (SciCompare(iii.GetUsername(), sInput))
          {
            for (int failedPins = 0; failedPins < g_maxPinEntryTries; ++failedPins)
            {
              std::cout << "Please enter your pin." << std::endl;
              std::cout << "You have " << g_maxPinEntryTries - failedPins << " tries left." << std::endl;
              unsigned int pin = EnterPin();
              if (iii.CheckPin(pin))
              {
                std::cout << "Welcome, " << iii.GetUsername() << std::endl;
                loggedIn(iii);
                backToMainMenu = true;
                break;
              }
              else
              {
                std::cout << "This pin was incorrect." << std::endl;
              }
            }
          }
        }
      }
      break;
    }

    case 'C':
    case 'c':
    {
      Konto newKonto = CreateAccount(konten);
      konten.push_back(newKonto);
      break;
    }


    case 'E':
    case 'e':
    SaveData(konten);
    return 0;

#ifdef _DEBUG

    case 'a': // Show all loaded konten(accounts)
    for (const auto& konto : konten)
    {
      std::cout << "Username: " << konto.GetUsername() << " Pin: " << konto.GetPin() << " Balance: " << konto.GetBalance() << std::endl;
    }
    break;
#endif // _DEBUG

    default:
    std::cout << "Unrecognized input. Try again." << std::endl;
    break;
    }
  }
}

// TODO 
// add integration to the test rack
// left/right light turns on when pin is correct/incorrect
// add alternative input via the buttons on the test rack
// optional: add support for the screen that is on the buttons to show e.g. the account balance