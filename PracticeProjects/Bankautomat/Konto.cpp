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

double Konto::GetBalance() const
{
  return m_balance;
}

std::string Konto::GetUsername() const
{
  return m_username;
}

bool Konto::CheckPin(unsigned int pin) const
{
  return (pin == m_pin);
}

Konto& Konto::operator+=(double rhs)
{
  this->m_balance += rhs;
  return *this;
}

Konto& Konto::operator-=(double rhs)
{
  this->m_balance -= rhs;
  return *this;
}

unsigned int Konto::GetPin() const
{
  return m_pin;
}
