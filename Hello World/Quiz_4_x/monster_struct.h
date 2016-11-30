#pragma once
#include <string>

#ifndef MONSTER_STRUCT_H
#define MONSTER_STRUCT_H

enum class MonsterType
{
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME
};




struct Monster
{
    std::string name;
    MonsterType type;
    int healthPoints;
};

#endif // !MONSTER_STRUCT_H
