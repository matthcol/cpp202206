#include "display.h"

#include <iostream>

/**
 * with iterator implicit (foreach)
*/
void display1(const std::vector<int>& vector) {
	std::cout << vector.size() << "/[";
	for (const auto& e : vector) {
		std::cout << e << ",";
	}
	std::cout << "]";
}

/**
* with iterator explicit (while)
*/
void display2(const std::vector<int>& vector) {
	std::cout << vector.size() << "/[";
	//std::vector<int>::const_iterator it = vector.cbegin();
	auto it = vector.cbegin();
	auto last = vector.cend();
	if (it != last) {
		std::cout << *it;
		++it;
	}
	while (it != last) {
		const auto& e = *it; // if you need the element in a variable
		std::cout << "," << e ;
		++it;
	}
	std::cout << "]";
}

/**
* with iterator explicit (for)
*/
void display3(const std::vector<int>& vector) {
	std::cout << vector.size() << "/[";
	//std::vector<int>::const_iterator it = vector.cbegin();
	for (auto it = vector.cbegin(), last = vector.cend(); it != last; ++it)
	{
		const auto& e = *it;
		std::cout << e << ",";
	}
	std::cout << "]";
}

//std::ostream& operator<<(std::ostream& out, const std::vector<std::string>& strlist) {
//	displayItOpt(strlist.cbegin(), strlist.cend(), 3, out);
//	return out;
//}