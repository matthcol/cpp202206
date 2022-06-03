#pragma once
#include <cstdint>
#include <memory>

class SmartBuffer
{
public:
	SmartBuffer(uint64_t size);
	virtual ~SmartBuffer();
	int& operator[](uint64_t index);
	const int& operator[](uint64_t index) const;
private:
	std::unique_ptr<int[]> mData;
	uint64_t mSize;
};

