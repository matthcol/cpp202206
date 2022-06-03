#include "Buffer.h"

Buffer::Buffer(uint64_t size):
    mData(nullptr),mSize(size)
{
    mData = new int[size];
}

Buffer::~Buffer()
{
    delete[] mData;
}

int& Buffer::operator[](uint64_t index)
{
    return mData[index];
}

const int& Buffer::operator[](uint64_t index) const
{
    return mData[index];
}
