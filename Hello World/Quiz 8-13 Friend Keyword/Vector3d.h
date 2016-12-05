#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3d.h"

class Vector3d
{

private:
    double m_a;
    double m_b;
    double m_c;

public:
    Vector3d(double a = 0.0, double b = 0.0, double c = 0.0)
        : m_a{ a }, m_b{ b }, m_c{ c }
    {

    }

    void print();
    friend void Point3d::moveByVector(const Vector3d& vector);
};



#endif // !VECTOR3D_H