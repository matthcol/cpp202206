#pragma once

#include <vector>
#include <iostream>
#include <iterator>

void display1(const std::vector<int>& vector);

void display2(const std::vector<int>& vector);

void display3(const std::vector<int>& vector);

template <class T>
void displayT(const std::vector<T>& vector);

template <class InputIt>
void displayIt(InputIt first, InputIt last);

template <class InputIt>
void displayItOpt(InputIt first, InputIt last, 
	int thresholdDisplay=3, std::ostream& out=std::cout);

//std::ostream& operator<<(std::ostream& out, const std::vector<std::string>& strlist);

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector);

#include "display.tpp"