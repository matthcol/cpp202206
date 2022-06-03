#include "Form.h"

#include <iostream>

Form::Form(const std::string& name):mName(name)
{
}

Form::~Form()
{
    std::clog << "Form destroyed: " << getName() << std::endl;
}

const std::string& Form::getName() const
{
    return mName;
}

void Form::setName(const std::string& name)
{
    mName = name;
}
