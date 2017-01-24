#pragma once
#include <string>

class Konto
{
private:
  double      m_balance;
  char        m_pin[4];
  std::string m_username;

public:
  Konto();
  ~Konto();
};

