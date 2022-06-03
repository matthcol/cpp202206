#pragma once

#include<cstdint>

class Buffer
{
public:
	Buffer(uint64_t size);
	virtual ~Buffer();
	int& operator[](uint64_t index);
	const int& operator[](uint64_t index) const;
private:
	int* mData;
	uint64_t mSize;
};

