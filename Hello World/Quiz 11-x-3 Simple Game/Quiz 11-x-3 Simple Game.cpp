// Quiz 11-x-3 Simple Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
  { "dragon", 'D', 20, 4, 100 },
  { "orc", 'o', 4, 2, 25 },
  { "slime", 's', 1, 1, 10 },
};

std::string getPlayerName()
{
  std::cout << "Enter your name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Welcome, " << name << "." <<  std::endl;
  return name;
}

int main()
{
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
  rand(); // get rid of first result

  for (int i = 0; i < 10; ++i)
  {
    Monster m = Monster::getRandomMonster();
    std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
  }
}


