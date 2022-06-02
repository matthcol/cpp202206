#include "WeightedPoint.h"

WeightedPoint::WeightedPoint(const std::string& name, double x, double y, double weight):
    Point2D(name,x,y), mWeight(weight)
{
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
