#include "Circle.h"

#include <sstream>
#include <cmath>
#include <numbers> // C++20
#include <iostream>

//const double Circle::PI = 4.0*atan(1.0);
const double Circle::PI = acos(-1.0);
//const double Circle::PI = std::numbers::pi;

Circle::Circle(const std::string& name, const Point2D& center, double radius):
    Form(name),Mesurable2D(),mCenter(center),mRadius(radius)
{
}

Circle::~Circle()
{
    std::clog << "Circle destroyed: " << getName() << std::endl;
}

double Circle::getRadius() const
{
    return mRadius;
}

void Circle::setRadius(double radius)
{
    mRadius = radius;
}

Point2D Circle::getCenter() const
{
    return mCenter;
}

void Circle::setCenter(const Point2D& center)
{
    mCenter = center;
}

double Circle::surface() const
{
    return PI*pow(mRadius,2.0); // PI.r^2
}

double Circle::perimeter() const
{
    return 0.0; // 2.PI.r
}

void Circle::translate(double deltaX, double deltaY)
{
    mCenter.translate(deltaX, deltaY);
}

std::string Circle::toString() const
{
    return (std::stringstream()
        << "<n="
        << getName()
        << "; c="
        << mCenter.toString() //.getName()
        << "; r="
        << mRadius
        << ">").str();
}
