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

void fightMonster(Player& player, Monster& monster)
{
  std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")." << std::endl;
  while (true)
  {
    std::cout << "(R)un or (F)ight: ";

    char playerChoice;
    std::cin >> playerChoice;
    std::cin.ignore(32767, '\n');

    bool playerFights;
    switch (playerChoice)
    {
    case 'R':
    case 'r': // Intended fall-through
    playerFights = false;
    break;
    case 'F':
    case 'f':
    playerFights = true;
    break;
    }

    if (!playerFights)
    {
      // Player flees and succeded.
      if (rand() % 2 == 0) // 50 %
      {
        std::cout << "You successfully fled." << std::endl;
        return;
      }
      // Player flees and failed.
      else
      {
        std::cout << "You failed to flee." << std::endl;
        std::cout << "The " << monster.getName() << " hit you for " << monster.getDpa() << " damage." << std::endl;
        player.reduceHealth(monster.getDpa());
      }
    }
    // Player fights
    else
    {
      std::cout << "You hit the " << monster.getName() << " for " << player.getDpa() << " damage." << std::endl;
      monster.reduceHealth(player.getDpa());
      if (monster.isDead())
      {
        player.addGold(monster.getGold());
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << std::endl;
        std::cout << "You found " << monster.getGold() << " gold." << std::endl;
        return;
      }
      else
      {
        std::cout << "The " << monster.getName() << " hit you for " << monster.getDpa() << " damage." << std::endl;
        player.reduceHealth(monster.getDpa());
      }
    }
    if (player.isDead())
    {
      return;
    }
  }
}

int main()
{
  srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
  rand(); // get rid of first result

  Player player = getPlayerName();

  while (true)
  {
    Monster monster = Monster::getRandomMonster();
    fightMonster(player, monster);
    if (player.isDead())
    {
      std::cout << "You died at level " << player.getLevel() << " and had " << player.getGold() << "gold." << std::endl;
      return 0;
    }
    if (player.hasWon())
    {
      std::cout << "Congratulations, you won!" << std::endl;
      std::cout << "You have " << player.getGold() << " gold." << std::endl;
      return 0;
    }

  }

  return 0;
}


