#include <vector>
#include <functional>
#include <iostream>

#include "Form.h"
#include "Point2D.h"

void test_forms() {
	//Form f; // Form is abstract, not instantiable
	//Form* f_ptr = new Form();
	Point2D ptA("A", 3.5, 4.25);
	
	// substitution de Lyskov with ref
	Point2D& pt = ptA;
	// Form f = ptA; // forbidden
	Form& f = ptA;

	// substitution de Lyskov with pointer
	Point2D* ptA_ptr = &ptA; // NB: use ref instead
	Point2D* ptB_ptr = new Point2D("B", 10.0, 5.5);
	Form* f_ptr = &ptA;
	Form* fD_ptr = new Point2D("D", 12.3, 14.3);

	delete ptB_ptr;
}

void test_vector_forms() {
	Point2D ptA("A", 3.5, 4.25);
	Point2D ptB("B", 3.5, 4.25);
	Point2D ptD("D", 3.5, 4.25);
	std::vector<Point2D> points {ptA, ptB, ptD};
	std::vector<std::reference_wrapper<Form>> forms{ptA, ptB, ptD};
	std::vector<Form*> formPtrs{&ptA, &ptB, &ptD};

	std::cout << "Points: " << points << std::endl;
	std::cout << "Forms (&): " << points << std::endl;
	std::cout << "Forms (*): " << points << std::endl;
}


int main() {

}