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

  unsigned int GetPin() const;

  double GetBalance() const;

  std::string GetUsername() const;

  bool CheckPin(unsigned int pin) const;

  Konto& operator+=(double rhs);

  Konto& operator-=(double rhs);
};

