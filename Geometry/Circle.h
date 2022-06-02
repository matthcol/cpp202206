#pragma once

#include "Form.h"
#include "Mesurable2D.h"
#include "Point2D.h"

class Circle:
	public Form,
	public Mesurable2D
{
public:
	Circle(const std::string& name, const Point2D& center, double radius);

	double getRadius() const;
	void setRadius(double radius);
	
	//const Point2D& getCenter() const;
	Point2D getCenter() const; // preferred way with composition
	void setCenter(const Point2D& center);

	double surface() const override;
	double perimeter() const override;
	void translate(double deltaX, double deltaY) override;
	std::string toString() const override;

private:
	double mRadius;

	// composition
	Point2D mCenter;

	//alt. aggregation
	//Point2D& mCenter; // card 1..1=1
	//Point2D* mCenter_ptr; // card 0..1
};

