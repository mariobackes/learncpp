#include "stdafx.h"

void Point2d::print()
{
    std::cout << "Point2d(" << m_x << ", " << m_y << ")" << std::endl;
}

double Point2d::distanceTo(Point2d point)
{
    return sqrt((point.m_x - m_x) * (point.m_x - m_x) + (point.m_y - m_y) * (point.m_y - m_y));
}

double distanceFrom(Point2d first, Point2d second)
{
    return sqrt((first.m_x - second.m_x) * (first.m_x - second.m_x) + (first.m_y - second.m_y) * (first.m_y - second.m_y));
}