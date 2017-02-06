#include "stdafx.h"
#include "Konto.h"


Konto::Konto(std::string username, unsigned int pin, double balance)
  : m_username{username}
  , m_balance{balance}
  , m_pin{pin}
{
}


Konto::~Konto()
{
}

double Konto::getBalance() const
{
  return m_balance;
}

std::string Konto::getUsername() const
{
  return m_username;
}

bool Konto::checkPin(unsigned int pin) const
{
  return (pin == m_pin);
}
