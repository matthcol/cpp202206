#include <iostream>
#include <cstdlib>

#include "Buffer.h"

void test_buffer() {
	Buffer buf(100000000000);
} // call destructor buffer

int main() {
	test_buffer();
	std::string choice;
	std::cin >> choice;
	return EXIT_SUCCESS;
}
