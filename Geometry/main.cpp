#include <vector>
#include <functional>
#include <iostream>

#include "Form.h"
#include "Point2D.h"
#include "WeightedPoint.h"
#include "display.h"
#include "Circle.h"

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
	delete fD_ptr;
}

void test_vector_forms() {
	Point2D ptA("A", 3.5, 4.25);
	Point2D ptB("B", 3.6, 3.25);
	Point2D ptD("D", 3.7, 2.25);
	WeightedPoint ptE("E", 3.8, 1.25, 2.5);
	Circle circleC1("C1", ptA, 5.0);
	Circle circleC2("C2", ptB, 4.0);

	std::vector<Point2D> points {ptA, ptB, ptD, ptE };
	std::vector<std::reference_wrapper<Form>> forms{ptA, ptB, ptD, ptE, circleC1, circleC2 };
	std::vector<Form*> formPtrs{&ptA, &ptB, &ptD, &ptE, &circleC1, &circleC2 };

	std::cout << "Points: " << points << std::endl;
	std::cout << "Forms (&): " << forms << std::endl;
	std::cout << "Forms (*): " << formPtrs << std::endl;

	// use inheritance in the dirction child => parent
	for (Form& f : forms) {
		std::clog << "Translate: " << f.getName() << std::endl;
		f.translate(1.0, -1.0);
	}
	std::cout << "Forms after translation (&): " << forms << std::endl;

	// use inheritance in the dirction parent => child
	double totalWeight=0;
	for (const Form* f_ptr : formPtrs) {
		if (const WeightedPoint* wp_ptr = dynamic_cast<const WeightedPoint*>(f_ptr)) {
			totalWeight += wp_ptr->getWeight();
		}
	}
	std::cout << "Total weight: " << totalWeight << std::endl;

}


int main() {
	test_vector_forms();
}