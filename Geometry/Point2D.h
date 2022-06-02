#pragma once

#include "Form.h"

class Point2D: public Form
{
public:
	Point2D(const std::string& name, double x, double y);

	virtual void translate(double deltaX, double deltaY) override;
	double distance(const Point2D& other) const;

private:
	double mX;
	double mY;
};

