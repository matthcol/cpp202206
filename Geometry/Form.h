#pragma once
#include <string>

class Form
{
protected:
	Form(const std::string& name);
public:
	virtual ~Form();
	// pure virtual method i.e. abstract
	virtual void translate(double deltaX, double deltaY)=0;
	virtual std::string toString() const = 0;

	const std::string& getName() const;
	void setName(const std::string& name);
private:
	std::string mName;
};

