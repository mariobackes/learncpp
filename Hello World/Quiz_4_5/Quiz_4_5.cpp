// Quiz_4_5.cpp : Defines the entry point for the console application.
// http://www.learncpp.com/cpp-tutorial/45-enumerated-types/

#include "stdafx.h"

enum MonsterType
{
    MONSTER_ORCS,
    MONSTER_GOBLINS,
    MONSTER_TROLLS,
    MONSTER_OGRES,
    MONSTER_SKELETONS
};


int main()
{
    MonsterType monsterXYZ = MONSTER_TROLLS;
    return 0;
}

