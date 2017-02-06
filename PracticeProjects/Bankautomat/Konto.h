#pragma once
#include <string>

class Konto
{
private:
  double  m_balance;
  unsigned int m_pin;
  std::string m_username;

public:
  Konto(const std::string username, unsigned int pin, double balance = 0);
  ~Konto();

  double getBalance() const;

  std::string getUsername() const;

  bool checkPin(unsigned int pin) const;

  // TODO
  // add getter and setter function for balance
};

