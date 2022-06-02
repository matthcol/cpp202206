#pragma once
#include <string>

class Form
{
protected:
	Form(const std::string& name);
public:
	// pure virtual method i.e. abstract
	virtual void translate(double deltaX, double deltaY)=0;
	virtual std::string toString() = 0;
private:
	std::string mName;
};

