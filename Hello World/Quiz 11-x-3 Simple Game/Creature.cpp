#include "stdafx.h"
#include "Creature.h"

// Getter functions
std::string Creature::getName()
{
  return m_name;
}

char Creature::getSymbol() 
{ 
  return m_symbol; 
}

int Creature::getHealth() 
{
  return m_health; 
}

int Creature::getDpa()
{ 
  return m_dpa; 
}

int Creature::getGold() 
{ 
  return m_gold; 
}

// Other functions

void Creature::reduceHealth(int amount)
{
  m_health -= amount;
}

bool Creature::isDead()
{
  return (m_health <= 0);
}

void Creature::addGold(int amount)
{
  m_gold += amount;
}
