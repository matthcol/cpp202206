#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>

#include "Form.h"

template<class InputIt>
std::ostream& write(std::ostream& out, InputIt first, InputIt last) {
	auto n = std::distance(first, last);
	out << n << "#[";
	if (first != last) {
		out << *first;
		++first;
	}
	while (first != last) {
		out << "," << * first;
		++first;
	}
	out << "]";
	return out;
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector) {
	return write(out, vector.cbegin(), vector.cend());
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set) {
	return write(out, set.cbegin(), set.cend());
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& list) {
	return write(out, list.cbegin(), list.cend());
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	return out << form.toString();
}

std::ostream& operator<<(std::ostream& out, const Form* form_ptr) {
	return out << form_ptr->toString();
}
