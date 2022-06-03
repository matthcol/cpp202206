#pragma once
#include "Point2D.h"
class WeightedPoint :
    public Point2D
{
public:
    WeightedPoint() = default;
    WeightedPoint(const std::string& name, double x, double y, double weight);
    virtual ~WeightedPoint();

    double getWeight() const;
    void setWeight(double weight);

    virtual std::string toString() const override;
    std::string toStringNotVirtual() const;

private:
    double mWeight;
};

