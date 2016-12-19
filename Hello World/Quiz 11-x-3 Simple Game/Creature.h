#pragma once
#include <string>
class Creature
{
protected:
  std::string m_name;
  char        m_symbol;
  int         m_health;
  int         m_dpa;    // Damage per attack
  int         m_gold;   // Amount of gold the creature is carrying.

public:
  // Default constructor
  Creature(std::string name, char symbol, int health, int dmgPerAtk, int gold)
    : m_name{ name }
    , m_symbol{ symbol }
    , m_health{ health }
    , m_dpa{ dmgPerAtk }
    , m_gold{ gold }
  {

  }

  // Getter functions
  std::string getName();

  char getSymbol();

  int getHealth();

  int getDpa();

  int getGold();

  // Other functions
  void reduceHealth(int amount);

  bool isDead();

  void addGold(int amount);
};

