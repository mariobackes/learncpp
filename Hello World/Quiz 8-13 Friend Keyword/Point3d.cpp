#include "stdafx.h"

void Point3d::print()
{
    std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")" << std::endl;
}

void Point3d::moveByVector(const Vector3d& vector)
{
    m_x += vector.m_a;
    m_y += vector.m_b;
    m_z += vector.m_c;
}