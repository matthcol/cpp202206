#pragma once
#include "Point2D.h"
class WeightedPoint :
    public Point2D
{
public:
    WeightedPoint(const std::string& name, double x, double y, double weight);

    double getWeight() const;
    void setWeight(double weight);

    virtual std::string toString() const override;

private:
    double mWeight;
};

