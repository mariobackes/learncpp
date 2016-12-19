#include "stdafx.h"
#include "Player.h"

Player::Player(std::string name)
  : Creature(name, '@', 10, 1, 0)
{

}

void Player::levelUp()
{
  ++m_level;
  ++m_dpa;
}

int Player::getLevel()
{
  return m_level;
}

bool Player::hasWon()
{
  return (m_level >= 20);
}
