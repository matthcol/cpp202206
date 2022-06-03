#include "SmartBuffer.h"

SmartBuffer::SmartBuffer(uint64_t size) :
    mData(nullptr), mSize(size)
{
    mData = new int[size];
}

SmartBuffer::~SmartBuffer()
{
    delete[] mData;
}

int& SmartBuffer::operator[](uint64_t index)
{
    return mData[index];
}

const int& SmartBuffer::operator[](uint64_t index) const
{
    return mData[index];
}

