// Quiz 8-13 Friend Keyword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main()
{
    Point3d     p(1.0, 2.0, 3.0);
    Vector3d    v(2.0, 2.0, -3.0);

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}
