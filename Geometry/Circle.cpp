#include "Circle.h"

#include <sstream>

Circle::Circle(const std::string& name, const Point2D& center, double radius):
    Form(name),Mesurable2D(),mCenter(center),mRadius(radius)
{
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
    return 0.0;
}

double Circle::perimeter() const
{
    return 0.0;
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
