// Usefull_functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>


int main()
{
    unsigned char option_viewed = 0x01;
    unsigned char option_edited = 0x02;
    unsigned char option_favorited = 0x04;
    unsigned char option_shared = 0x08;
    unsigned char option_deleted = 0x80;
    
    unsigned char myArticleFlags;

    myArticleFlags |= option_viewed;
    myArticleFlags &= ~option_favorited;
    return 0;
}

