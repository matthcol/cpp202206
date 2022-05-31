#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <set>
#include <list>

#include "display.h"




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
	display2(evenNumbers);

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
	// add vector elements in an ordered set
	std::set<int> orderedEvenNumbers(evenNumbers.cbegin(), evenNumbers.cend());
	// add an extract of the set in a list
	std::list<int> listEvenNumbers(orderedEvenNumbers.cbegin(), std::next(orderedEvenNumbers.cbegin(),3));

	displayT(evenNumbers);
	displayItOpt(evenNumbers.cbegin(), evenNumbers.cend());
	displayItOpt(evenNumbers.begin(), evenNumbers.end());
	displayItOpt(evenNumbers.rbegin(), evenNumbers.rend());
	displayItOpt(evenNumbers.crbegin(), evenNumbers.crend()-2);
	std::cout << std::endl;
	
	// play with set
	displayItOpt(orderedEvenNumbers.cbegin(), orderedEvenNumbers.cend());
	orderedEvenNumbers.insert(3);
	std::vector<int> others{ 54, 66, 98, 18, 4, 104 };
	orderedEvenNumbers.insert(others.cbegin(), others.cend());
	std::cout << std::endl;
	displayItOpt(orderedEvenNumbers.cbegin(), orderedEvenNumbers.cend());
	std::cout << std::endl;
	
	// play with vector
	evenNumbers.insert(evenNumbers.begin() + 2, 55);
	evenNumbers.insert(evenNumbers.end() - 1, others.cbegin(), others.cend());
	displayItOpt(evenNumbers.cbegin(), evenNumbers.cend());
	displayItOpt(evenNumbers.cbegin(), evenNumbers.cend(), 4);
	std::cout << std::endl;

	// play with list
	displayItOpt(listEvenNumbers.cbegin(), listEvenNumbers.cend());
	std::cout << std::endl;
	listEvenNumbers.insert(std::next(listEvenNumbers.begin(), 2), 55);
	listEvenNumbers.insert(std::prev(listEvenNumbers.end(),1), others.cbegin(), others.cend());
	displayItOpt(listEvenNumbers.cbegin(), listEvenNumbers.cend());
	std::cout << std::endl;
}

void test_vector_string() {
	std::vector<std::string> villes{ "Toulouse", "Balma", "Pau" };
	villes.push_back("Blagnac");
	displayT(villes);
	displayItOpt(villes.cbegin(), villes.cend());
	std::cout << std::endl;
	std::cout << "Villes (ou): " << villes << std::endl;
	std::cerr << "Villes (err): " << villes << std::endl;
}

void test_vector_vector_string() {
	std::vector<std::vector<std::string>> villesByDep{ {"Toulouse", "Balma"}, {"Pau", "Bayonne"} };
	displayT(villesByDep); // operator << not defined between ostream & vector<string> => ok now
	std::cout << std::endl
		<< villesByDep << std::endl; // call twice overload of operator<< with std::vector 

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
	test_vector_vector_string();
	return EXIT_SUCCESS;
}