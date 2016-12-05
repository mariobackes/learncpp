#pragma once
#ifndef POINT2D_H
#define POINT2D_H

class Point2d
{
public:
    Point2d(double x = 0.0, double y = 0.0)
        : m_x{ x }, m_y{ y }
    {

    }

    void print();
    double distanceTo(Point2d point);
    friend double distanceFrom(Point2d first, Point2d second);

private:
    double m_x;
    double m_y;
};

double distanceFrom(Point2d first, Point2d second);

#endif // !POINT2D_H