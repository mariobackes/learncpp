#include "stdafx.h"

Monster::Monster(Type type)
  : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold)
{

}

//static 
Monster Monster::getRandomMonster()
{
  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
  int temp = (static_cast<int>( rand() * fraction * ((MAX_TYPES - 1) - 0 + 1) + 0));
  return Monster(static_cast<Monster::Type>(temp));
}
