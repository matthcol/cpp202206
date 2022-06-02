#include "Point2D.h"

#include <sstream>
#include <cmath>

Point2D::Point2D(const std::string& name, double x, double y):
	Form(name), mX(x), mY(y)
{
}

double Point2D::getX() const
{
	return mX;
}

void Point2D::setX(double x)
{
	mX = x;
}

double Point2D::getY() const
{
	return mY;
}

void Point2D::setY(double y)
{
	mY = y;
}



void Point2D::translate(double deltaX, double deltaY)
{
	mX += deltaX;
	mY += deltaY;
}

std::string Point2D::toString() const
{
	return (std::stringstream()
		<< this->getName()
		<< "("
		<< mX
		<< ","
		<< mY
		<< ")"
		).str();
}

double Point2D::distance(const Point2D& other) const
{
	return std::hypot(
		this->mX - other.mX,
		this->mY - other.mY
	);
}

