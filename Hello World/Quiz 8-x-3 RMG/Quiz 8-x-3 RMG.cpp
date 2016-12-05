// Quiz 8-x-3 RMG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <ctime>

const int g_hpMax = 100;
const int g_hpMin = 0;

class Monster
{
public:
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

    Monster(MonsterType type, std::string name, std::string roar, int hp)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hp}
    {

    }
    void print()
    {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
    }


private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int    m_hitPoints;
    std::string getTypeString()
    {
        switch (m_type)
        {
        case Monster::Dragon:   return "Dragon";
        case Monster::Goblin:   return "Goblin";
        case Monster::Ogre:     return "Ogre";
        case Monster::Orc:      return "Orc";
        case Monster::Skeleton: return "Skeleton";
        case Monster::Troll:    return "Troll";
        case Monster::Vampire:  return "Vampire";
        case Monster::Zombie:   return "Zombie";
        }

    }


};


class MonsterGenerator
{
private:


public:

    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    

    static Monster generateMonster()
    {
        
        // Get random monster type
        int type = getRandomNumber(static_cast<int>(Monster::MonsterType::Dragon), static_cast<int>(Monster::MonsterType::MAX_MONSTER_TYPES - 1));

        // Get random hp
        int hp = getRandomNumber(g_hpMin, g_hpMax);

        static std::string s_names[6]{"Bones", "Alexstrasza", "Rakgu", "Sans", "Papyrus", "Pikachu"};

        static std::string s_roars[6]{ "*rattle*", "*pika*", "*ROAR*", "*grunt*", "*sigh*", "*zzzZZZ*" };

        return Monster(static_cast<Monster::MonsterType>(type), 
            s_names[getRandomNumber(0, 5)], 
            s_roars[getRandomNumber(0, 5)], 
            hp);
    }
};


int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
    rand(); // If using Visual Studio, discard first random value

    Monster m = MonsterGenerator::generateMonster();
    m.print();


    return 0;
}

