#pragma once
#include <string>
#include "Creature.h"

class Monster : public Creature
{
public:   // This enum has to be before the constructor....a fix might be to have this class in seperate files.
  enum Type
  {
    DRAGON,
    ORC,
    SLIME,
    MAX_TYPES
  };

  Monster(Type type);

  static Monster getRandomMonster();

protected:

  struct MonsterData
  {
    std::string name;
    char        symbol;
    int         health;
    int         damage;
    int         gold;
  };

  static MonsterData monsterData[MAX_TYPES];

};