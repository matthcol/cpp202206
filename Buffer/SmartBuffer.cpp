#include "SmartBuffer.h"

SmartBuffer::SmartBuffer(uint64_t size) :
    mData(new int[size]), mSize(size)
{
}

SmartBuffer::~SmartBuffer()
{
    // mData destroyed automatically 
    // and call delete og underlying array
}

int& SmartBuffer::operator[](uint64_t index)
{
    return mData[index];
}

const int& SmartBuffer::operator[](uint64_t index) const
{
    return mData[index];
}

