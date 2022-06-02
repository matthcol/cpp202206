#include "Form.h"

Form::Form(const std::string& name):mName(name)
{
}

const std::string& Form::getName() const
{
    return mName;
}

void Form::setName(const std::string& name)
{
    mName = name;
}
