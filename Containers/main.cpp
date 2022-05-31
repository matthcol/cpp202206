#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <set>
#include <list>

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
		// << vector.size() 
		<< "[";

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



void test_vector() {
	// random access, cost O(1)
	std::vector<int> emptyVector; // call default constructor
	std::cout << emptyVector.size() << std::endl;
	emptyVector.push_back(3);
	std::cout << emptyVector.size() << std::endl << std::endl;

	std::vector<int> evenNumbers{2, 4, 6, 8}; // call constructor with initializer list
	auto nb = evenNumbers[0]; // index not checked
	auto nb2 = evenNumbers.front();
	auto nb3 = evenNumbers.back();
	auto nb4 = evenNumbers.at(3); // iden [3] with exceptions
	std::cout << nb << std::endl
		<< nb2 << std::endl
		<< nb3 << std::endl
		<< nb4 << std::endl
		<< evenNumbers.size()
		<< std::endl << std::endl;

	std::vector<int> bigData(1000000);
	std::vector<int> bigData2(1000000,1);
	std::cout << bigData.size() << " : " << bigData[0] << std::endl << std::endl;
	std::cout << bigData2.size() << " : " << bigData2[0] << std::endl << std::endl;


	std::vector<int> copyEvenNumbers(evenNumbers); // copy constructeur
	copyEvenNumbers[0]++; // operator[] return a reference
	std::cout << evenNumbers[0] << "/" << copyEvenNumbers[0] << std::endl << std::endl;

	// std::vector<int> bigData10(bigData.cbegin(), bigData.cbegin() + 10);
	std::vector<int> bigData10(bigData.cbegin(), std::next(bigData.cbegin(), 10));
	std::cout << bigData10.size() << " : " << bigData[0] << std::endl << std::endl;;
} // call destructor of all vectors in stack (clean data in the heap)


void test_vector_set_list() {
	std::vector<int> evenNumbers{ 10, 2, 4, 22, 6, 8 };
	std::set<int> orderedEvenNumbers(evenNumbers.cbegin(), evenNumbers.cend());
	std::list<int> listEvenNumbers(orderedEvenNumbers.cbegin(), std::next(orderedEvenNumbers.cbegin(),3));
	displayT(evenNumbers);
	displayIt(evenNumbers.cbegin(), evenNumbers.cend());
	displayIt(evenNumbers.begin(), evenNumbers.end());
	displayIt(evenNumbers.rbegin(), evenNumbers.rend());
	displayIt(evenNumbers.crbegin(), evenNumbers.crend()-2);
	std::cout << std::endl;
	displayIt(orderedEvenNumbers.cbegin(), orderedEvenNumbers.cend());
	std::cout << std::endl;
	displayIt(listEvenNumbers.cbegin(), listEvenNumbers.cend());
	std::cout << std::endl;
}

void test_vector_string() {
	std::vector<std::string> villes{ "Toulouse", "Balma", "Pau" };
	villes.push_back("Blagnac");
	displayT(villes);
}

void test_vector_vector_string() {
	std::vector<std::vector<std::string>> villesByDep{ {"Toulouse", "Balma"}, {"Pau", "Bayonne"} };
	// displayT(villesByDep); // operator << not defined between ostream & vector<string>
}

void test_arrays() {
	// static arrays : stack
	int nombrePairs[] = { 2,4,6,8 };
	int buffer[10];
	//int bufferStackOverflow[1000000]; // => StackOverflow

	// dynamic arrays : heap
	std::string input;
	std::cin >> input;
	int* bigData = new int[300000000];
	std::cin >> input;
	std::cout << "All is good" << std::endl;
	delete[] bigData;
}

void print_args(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		std::cout << " - Argv[" << i << "] = " << argv[i] << std::endl;
	}
}

//int main() // aucun argument en entrée
int main(int argc, char* argv[]) // argument en ligne de commande
//int main(int argc, char* argv[], char** arge) // idem + env
{
	//print_args(argc, argv);
	//test_arrays();
	//std::string input;
	//std::cin >> input;
	// test_vector();
	test_vector_set_list();
	test_vector_string();
	return EXIT_SUCCESS;
}