// Quiz_4_x.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

std::string getMonsterTypeString(Monster monster)
{
    int monsterType;
    monsterType = static_cast<int>(monster.type);
    std::string retVal;

    switch (monsterType)
    {
    case 0: retVal = "Ogre";
    break;
    case 1: retVal = "Dragon";
    break;
    case 2: retVal = "Orc";
    break;
    case 3: retVal = "Giant Spider";
    break;
    case 4: retVal = "Slime";
    break;
    default: retVal = "Unknown";
    break;
    }
    return retVal;
}

void printMonster(Monster monster)
{
    using namespace std;
    cout << "This " << getMonsterTypeString(monster);
    cout << " has " << monster.healthPoints << " HP, and is called " << monster.name << "." << endl;
}


int main()
{
    Monster ogreTorg = { "Torg", MonsterType::OGRE, 578 };
    Monster slimeBlurp = { "Blurp", MonsterType::SLIME, 212};
    printMonster(ogreTorg);
    printMonster(slimeBlurp);
    return 0;
}

