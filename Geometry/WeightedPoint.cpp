#include "WeightedPoint.h"

#include <iostream>

WeightedPoint::WeightedPoint(const std::string& name, double x, double y, double weight):
    Point2D(name,x,y), mWeight(weight)
{
}

WeightedPoint::~WeightedPoint()
{
    std::clog << "WP destroyed: " << getName() << std::endl;
}

double WeightedPoint::getWeight() const
{
    return mWeight;
}

void WeightedPoint::setWeight(double weight)
{
    mWeight = weight;
}

std::string WeightedPoint::toString() const
{
    return Point2D::toString() + "#" + std::to_string(mWeight);
}

std::string WeightedPoint::toStringNotVirtual() const
{
    return "WP";
}
