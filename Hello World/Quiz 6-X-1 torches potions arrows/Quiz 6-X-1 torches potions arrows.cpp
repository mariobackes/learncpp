// Quiz 6-X-1 torches potions arrows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

enum Item
{
    ITEM_TORCH,
    ITEM_POTION,
    ITEM_ARROW,
    ITEM_MAXCOUNT
};


int countTotalItems(int bag[], int arrayLength)
{
    int count = 0;
    for (int i = 0; i < arrayLength; ++i)
    {
        count += bag[i];
    }
    return count;
}


int main()
{
    int bag[ITEM_MAXCOUNT];
    bag[ITEM_TORCH] = 5;
    bag[ITEM_ARROW] = 10;
    bag[ITEM_POTION] = 2;
    std::cout << "Total items are " << countTotalItems(bag, ITEM_MAXCOUNT);
    return 0;
}

