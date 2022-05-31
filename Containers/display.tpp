template <class T>
void displayT(const std::vector<T>& vector) {
	std::cout << vector.size() << "/[";
	//std::vector<T>::const_iterator it = vector.cbegin();
	auto it = vector.cbegin();
	auto last = vector.cend();
	if (it != last) {
		std::cout << *it;
		++it;
	}
	while (it != last) {
		const auto& e = *it; // if you need the element in a variable
		std::cout << "," << e;
		++it;
	}
	std::cout << "]";
}

template <class InputIt>
void displayIt(InputIt first, InputIt last) {
	std::cout 
		<< std::distance(first,last)
		<< "/[";

	if (first != last) {
		std::cout << *first;
		++first;
	}
	while (first != last) {
		const auto& e = *first; // if you need the element in a variable
		std::cout << "," << e;
		++first;
	}
	std::cout << "]";
}


template <class InputIt>
void _displayPart(InputIt first, InputIt last, std::ostream& out=std::cout) {
	if (first != last) {
		out << *first;
		++first;
	}
	while (first != last) {
		const auto& e = *first; // if you need the element in a variable
		out << "," << e;
		++first;
	}
}

template <class InputIt>
void displayItOpt(InputIt first, InputIt last, 
		int thresholdDisplay, std::ostream& out) 
{
	auto size = std::distance(first, last);
	std::cout << size << "/[";
	if (size <= 2 * thresholdDisplay) {
		_displayPart(first, last, out);
	} else {
		_displayPart(first, std::next(first, thresholdDisplay));
		std::cout << " ... ";
		std::advance(first, size - thresholdDisplay);
		_displayPart(first, last, out);
	}
	std::cout << "]";
}

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vector)
{
	displayItOpt(vector.cbegin(), vector.cend(), 3, out);
	return out;
}



