#pragma once

#include "Form.h"

class Point2D: public Form
{
public:
	Point2D() = default;
	Point2D(const std::string& name, double x, double y);
	virtual ~Point2D();

	virtual void translate(double deltaX, double deltaY) override;
	double distance(const Point2D& other) const;

	virtual std::string toString() const override;
	std::string toStringNotVirtual() const;

	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);
private:
	double mX;
	double mY;
};

