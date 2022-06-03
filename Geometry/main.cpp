#include <vector>
#include <functional>
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <optional>
#include <variant>
#include <map>

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

void handle_mesurable(Mesurable2D& mesurable) {

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

	double totalSurface = 0;
	for (const Form* f_ptr : formPtrs) {
		if (const Mesurable2D* mesurable_ptr = dynamic_cast<const Mesurable2D*>(f_ptr)) {
			totalSurface += mesurable_ptr->surface();
		}
	}
	std::cout << "Total surface: " << totalSurface << std::endl;

	std::cout << "Weighted point: " << ptE.toStringNotVirtual() << std::endl;
	Point2D& ptEref = ptE;
	std::cout << "Weighted point as a Point2D: " << ptEref.toStringNotVirtual() << std::endl;

}

void test_PI() {
	std::cout << "PI: " << Circle::PI << std::endl;
}


void test_destructor1() {
	WeightedPoint* wp = new WeightedPoint("A", 1.0, 2.0, 3.0);
	std::cout << " - test destructor wp as a wp" << std::endl;
	delete wp;
}

void test_destructor2() {
	Point2D* pt = new WeightedPoint("A", 1.0, 2.0, 3.0);
	std::cout << " - test destructor wp as a pt" << std::endl;
	delete pt;
}

void test_destructor3() {
	Form* f = new WeightedPoint("A", 1.0, 2.0, 3.0);
	std::cout << " - test destructor wp as a f" << std::endl;
	delete f;
}

void test_destructor4() {
	Point2D pt("A", 1.0, 1.0);
	Mesurable2D* m = new Circle("C", pt, 1.0);
	std::cout << " - test destructor c as m2d" << std::endl;
	delete m;
}

std::unique_ptr<Point2D> compute_with_smart_pointer(std::unique_ptr<Point2D> point_ptr) {
	std::cout << "compute 1: " << point_ptr << std::endl;
	point_ptr->translate(2.0, -2.0);
	std::cout << "compute 2: " << point_ptr << std::endl;
	return std::move(point_ptr);
}

void test_smart_pointer() {
	std::unique_ptr<Point2D> ptA_ptr(new Point2D("A", 1.0, 3.0));
	std::cout << "test 1: " << ptA_ptr << std::endl;
	ptA_ptr = compute_with_smart_pointer(std::move(ptA_ptr));
	std::cout << "test 2: return from subroutine" << std::endl;
	std::cout << "test 3: " << ptA_ptr << std::endl;
} // smart pointer pop from stack 
  //    => call destructor of smart pointer
  //    => call delete underlying object Point2D

void compute_with_shared_pointer(std::shared_ptr<Point2D> point_ptr) {
	std::cout << "compute 1: " << point_ptr
		<< " #" << point_ptr.use_count() << std::endl;
	point_ptr->translate(2.0, -2.0);
	std::cout << "compute 2: " << point_ptr
		<< " #" << point_ptr.use_count() << std::endl;
} // pop shared ptr from stack 
// => destructor
// => use_count 2 -> 1 (nothing to delete)

void test_smart_pointer_shared() {
	std::shared_ptr<Point2D> ptA_ptr(new Point2D("A", 1.0, 3.0));
	std::cout << "test 1: " << ptA_ptr 
		<< " #" << ptA_ptr.use_count() << std::endl;
	compute_with_shared_pointer(ptA_ptr);
	std::cout << "test 2: return from subroutine" << std::endl;
	std::cout << "test 3: " << ptA_ptr
		<< " #" << ptA_ptr.use_count() << std::endl;
} // smart pointer pop from stack 
  //    => call destructor of smart pointer
  //    => use_count 1 -> 0
  //    => call delete underlying object Point2D

//template<class InputIt>
//double minValue(InputIt first, InputIt last) {
//	auto itFound = std::min_element(first, last);
//	if (itFound != last) {
//		// found
//		return std::optional<double>(*itFound);
//	}
//	else {
//		return std::nullopt;
//	}
//}

//void handle_optional(const std::optional<double>& optDouble) {
//	if (optDouble.has_value()) {
//		std::cout << *optDouble << std::endl;
//		std::cout << optDouble.value() << std::endl;
//	}
//	else {
//		std::cout << "No double in the box" << std::endl;
//	}
//	std::cout << "Final value: " << optDouble.value_or(33.33333) << std::endl;
//}

//void test_optional()
//{
//	std::optional<double> optDouble{ 12.2 };
//	std::optional<double> emptyDouble;
//	handle_optional(optDouble);
//	handle_optional(emptyDouble);
//}

void test_map_reduce() {
	//1. vecteur de point pondere
	std::vector<WeightedPoint> wpoints{
		WeightedPoint("A",1.0,2.0,1.0),
		WeightedPoint("B",2.0,1.0,2.0),
		WeightedPoint("C",3.0,-1.0,3.0),
		WeightedPoint("D",4.0,-2.0,4.0),
		WeightedPoint("E",5.0,-3.0,5.0)
	};
	std::cout << "Weighted points: " << wpoints << std::endl;
	//2. transformer en un vecteur de poids
	std::vector<double> weights(wpoints.size());
	std::transform(
		wpoints.cbegin(), wpoints.cend(),  // source
		weights.begin(),	// dest
		[](const auto& wp) {return wp.getWeight(); } // function
		// WeightedPoint::getWeight // NOK in C++
	);
	std::cout << "Weights: " << weights << std::endl;
	//3. calculer la somme des poids
	double totalWeights = std::accumulate(
		weights.cbegin(), weights.cend(), 0.0);
	std::cout << "Total weight: " << totalWeights << std::endl;
	//4. produits
	double prodWeights = std::accumulate(
		weights.cbegin(), weights.cend(), 
		1.0, 
		std::multiplies<double>());
	std::cout << "Product of weights: " << prodWeights << std::endl;
	//5. min weight optional
}

//void testVariant() {
//	std::variant<int, std::string> data(12);
//	std::cout << std::get<int>(data) << std::endl;
//	// std::cout << std::get<std::string>(data) << std::endl; // std::bad_variant_access
//	data = "Toulouse";
//	std::cout << std::get<std::string>(data) << std::endl;
//}

void test_map_ptr() {
	Point2D ptA("A", 1.0, 2.0);
	Point2D ptB("B", 1.0, 2.0);
	Point2D ptC("C", 1.0, 2.0);
	Point2D ptD("D", 1.0, 2.0);
	std::map<std::string, Point2D*> indexPoints{
		{"B", &ptB},
		{"A", &ptA},
		{"D", &ptD},
	};
	std::cout << std::endl;
	write(std::cout, indexPoints.cbegin(), indexPoints.cend());
	std::cout << std::endl;

	indexPoints["C"] = &ptC;
	auto pt_ptr = indexPoints["A"];
	std::cout << "Point with key A: " << *pt_ptr << std::endl;

	std::cout << std::endl;
	write(std::cout, indexPoints.cbegin(), indexPoints.cend());
	std::cout << std::endl;

}

void test_map_copy() {
	Point2D ptA("A", 1.0, 2.0);
	Point2D ptB("B", 1.0, 2.0);
	Point2D ptC("C", 1.0, 2.0);
	Point2D ptD("D", 1.0, 2.0);
	std::map<std::string, Point2D> indexPoints{
		{"B", ptB},
		{"A", ptA},
		{"C", ptC},
	};
	std::cout << std::endl;
	write(std::cout, indexPoints.cbegin(), indexPoints.cend());
	std::cout << std::endl;

	indexPoints["D"] = ptD;
	auto pt = indexPoints["A"];
	std::cout << "Point with key A: " << pt << std::endl;

	std::cout << std::endl;
	write(std::cout, indexPoints.cbegin(), indexPoints.cend());
	std::cout << std::endl;
}

void test_write_file() {
	std::vector<WeightedPoint> wpoints{
		WeightedPoint("A",1.0,2.0,1.0),
		WeightedPoint("B",2.0,1.0,2.0),
		WeightedPoint("C",3.0,-1.0,3.0),
		WeightedPoint("D",4.0,-2.0,4.0),
		WeightedPoint("E",5.0,-3.0,5.0)
	};
	{
		int x = 3;
		std::ofstream out("wpoints.csv");
		out << "Name,X,Y,Weight" << std::endl;
		// write(out, wpoints.cbegin(), wpoints.cend());
		std::for_each(wpoints.cbegin(), wpoints.cend(),
			[&out](const auto& wp){
				out << wp.getName()
					<< "," << wp.getX()
					<< "," << wp.getY()
					<< "," << wp.getWeight()
					<< std::endl;
			});
		// out.close();
	} // => auto out.close by its destructor
	std::ifstream in("wpoints.csv");
	char buf[200];
	// std::fill(std::begin(buf), std::end(buf), 0);
	while (in.getline(buf, 200)) {
		std::string line(buf);
		std::cout << "Line CSV: " << line << std::endl;
	}
}

int main() {
	//test_vector_forms();
	//test_PI();
	//test_destructor1();
	//test_destructor2();
	//test_destructor3();
	//test_destructor4();
	//test_smart_pointer();
	//test_smart_pointer_shared();
	//test_map_reduce();
	/*test_optional();*/
	//testVariant();
	//test_map_copy();
	//test_map_ptr();
	test_write_file();
}