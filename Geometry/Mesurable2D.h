#pragma once
#include <iostream>

class Mesurable2D
{
public:
	virtual ~Mesurable2D() {
		std::clog << "Mesurable2D destroyed: " << std::endl;
	}
	virtual double surface() const = 0;
	virtual double perimeter() const = 0;
};

