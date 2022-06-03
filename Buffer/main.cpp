#include <iostream>
#include <cstdlib>

#include "Buffer.h"
#include "SmartBuffer.h"

void test_buffer() {
	Buffer buf(1000000000);
} // call destructor buffer

void test_smartbuffer() {
	SmartBuffer buf(1000000000);
	buf[500] = 123;
	std::cout << "Read data: " << buf[500] << std::endl;
} // call destructor smart buffer

int main() {
	//test_buffer();
	test_smartbuffer();
	std::string choice;
	std::cin >> choice;
	return EXIT_SUCCESS;
}
