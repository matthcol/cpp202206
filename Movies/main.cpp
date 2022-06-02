#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>
// #include <compare>

#include "Movie.h"
#include "Movie.h"

void test_create_movies()
{
	// movies in the stack
	Movie m; // default constructor
	m.setTitle("Star Wars: Episode V - The Empire Strikes Back");
	m.setYear(1980);
	Movie m2(m); // copy constructor
	m2 = m; // operator copy (=)
	Movie m3("Rogue One", 2019, 133);
	std::cout
		<< "@m: " << &m << " ; " << m
		// << m.toString()
		//<< " ; title = " 
		//<< m.getTitle() 
		//<< " (" << m.getYear() << ";" << m.getDuration() << " mn)" 
		<< std::endl;
	std::cout << "@m2: " << &m2 << " ; " << m2 << std::endl;
	std::cout << "@m3: " << &m3 << " ; " << m3 << std::endl;
	
	// movies in the heap
	//Movie* movie_ptr = nullptr;
	Movie* movie_ptr = new Movie();
	Movie* movie2_ptr = new Movie(m);
	Movie* movie3_ptr = new Movie(*movie2_ptr);
	Movie* movie4_ptr = new Movie("Solo: A Star Wars Story", 2018);
	movie4_ptr->setDuration(135);

	std::cout
		<< "@movie: " << movie_ptr << " ; " << *movie_ptr << std::endl
		<< "@movie2: " << movie2_ptr << " ; " << *movie2_ptr << std::endl
		<< "@movie3: " << movie3_ptr << " ; " << *movie3_ptr << std::endl;
	std::clog << "@movie4: " << movie3_ptr << " ; " << *movie4_ptr << std::endl;

	delete movie3_ptr;
	delete movie2_ptr;
	delete movie_ptr;
} // m,m2 : call to destructor

void test_concat_string() {
	std::stringstream buf;
	std::string ville("Toulouse");
	buf << ville
		<< ", ville rose (" << 31000 << ")";
	std::string slogan = buf.str();
	std::cout << slogan << std::endl;
}

void test_operators_string() {
	std::string ville1("Toulouse");
	std::string ville2("Tarbes");

	std::cout << std::boolalpha
		<< "v1 == v2 : " << (ville1 == ville2) << std::endl
		<< "v1 == v1 : " << (ville1 == ville1) << std::endl
		<< "v1 != v2 : " << (ville1 != ville2) << std::endl
		<< "v1 < v2 : " << (ville1 < ville2) << std::endl
		<< "v1 <= v2 : " << (ville1 <= ville2) << std::endl
		<< "v1 > v2 : " << (ville1 > ville2) << std::endl
		<< "v1 >= v2 : " << (ville1 >= ville2) << std::endl
		// << "v1 <=> v2 is eq : " << std::is_eq(ville1 <=> ville2) << std::endl
		;
}


void test_operators_movie() {
	Movie movie1("Star Wars IV", 1977);
	Movie movie2("Star Wars V", 1980);
	Movie movie3(movie1);
	movie3.setDuration(120);
	Movie movie4("Saturday Night Fever", 1977);

	std::cout << std::boolalpha
		<< "v1 == v2 : " << (movie1 == movie2) << std::endl
		<< "v1 == v1 : " << (movie1 == movie1) << std::endl
		<< "v1 == v3 : " << (movie1 == movie3) << std::endl
		<< "v3 == v1 : " << (movie3 == movie1) << std::endl
		<< "v1 != v2 : " << (movie1 != movie2) << std::endl
		<< "v1 != v3 : " << (movie1 != movie3) << std::endl
		<< "v1 < v2 : " << (movie1 < movie2) << std::endl
		<< "v1 < v4 : " << (movie1 < movie4) << std::endl
		<< "v1 <= v2 : " << (movie1 <= movie2) << std::endl
		<< "v1 > v2 : " << (movie1 > movie2) << std::endl
		<< "v1 >= v2 : " << (movie1 >= movie2) << std::endl
		// << "v1 <=> v2 is eq : " << std::is_eq(ville1 <=> ville2) << std::endl
		;
}

void test_find() {
	// movies in a vector
	Movie movie1("Star Wars IV", 1977, 120);
	Movie movie2("Star Wars V", 1980, 120);
	Movie movie3("Saturday Night Fever", 1977, 120);
	Movie movie4("Star Wars VI", 1983, 120);
	std::vector<Movie> movies{ movie1, movie2, movie3, movie1, movie1, movie4 };
	// movie from a search form
	Movie movieForm("Star Wars IV", 1977);

	auto itFirst = movies.cbegin();
	auto itLast = movies.cend();
	auto itFound = itLast; // initialized value not used
	do {
		//itFound = std::find(itFirst, itLast, movieForm);
		std::cout << "Found movie" << *itFound << std::endl;
		itFirst = itFound + 1;
	} while (itFound != itLast);
}

bool filterYear1983(const Movie& movie)
{
	return movie.getYear() == 1983;
}

auto filterYear1983auto(const Movie& movie)
{
	return movie.getYear() == 1983;
}

// sol1: predicate defined with type std::function
//void find_predicate_aux(
//	const std::vector<Movie>& movies,
//	std::function<bool(const Movie&)> moviePredicate)
// 
// sol 2: predicate defined with auto type (c++20) 
//void find_predicate_aux(
//	const std::vector<Movie>& movies,
//	auto moviePredicate)
//
// sol 3: with template
template <class MoviePredicate>
void find_predicate_aux(
	const std::vector<Movie>& movies,
	MoviePredicate moviePredicate)
{
	auto itFound = std::find_if(
		movies.cbegin(),
		movies.cend(),
		moviePredicate
	);
	if (itFound != movies.cend()) {
		std::cout << "Movie found: " << *itFound << std::endl;
	}
	else {
		std::cout << "Movie not found" << std::endl;
	}
}

void test_find_predicate() {
	// movies in a vector
	Movie movie1("Star Wars IV", 1977, 120);
	Movie movie2("Star Wars V", 1980, 120);
	Movie movie3("Saturday Night Fever", 1977, 120);
	Movie movie4("Star Wars VI", 1983, 120);
	Movie movie5("Star Wars: Rogue One", 2016, 120);
	std::vector<Movie> movies{ movie1, movie2, movie3, movie4, movie5 };
	Movie movieForm("Saturday Night Fever", -1);
	int year = 1980;

	find_predicate_aux(
		movies,
		[](const Movie& movie)->bool
		{
			return movie.getYear() == 1977;
		});
	find_predicate_aux(
		movies,
		[](const auto& movie)
		{
			return movie.getYear() == 2016;
		});
	find_predicate_aux(
		movies,
		[year](const auto& movie)
		{
			return movie.getYear() == year;
		});
	find_predicate_aux(
		movies,
		// captures: movieForm by ref, year by copy
		[&movieForm, year](const auto& movie)
		{
			return (movie.getTitle() == movieForm.getTitle()) || (movie.getYear() == year);
		});
	//auto predicate5 : tout le monde by ref [&], by copy [=]
	std::function<bool(const Movie&)> predicate5 = [&](const auto& movie)
	{
		return (movie.getTitle() == movieForm.getTitle()) || (movie.getYear() == year);
	};
	find_predicate_aux(
		movies,
		predicate5);
	find_predicate_aux(
		movies,
		filterYear1983);
	find_predicate_aux(
		movies,
		filterYear1983auto);
}

int main()
{
	//test_create_movies();
	//test_concat_string();
	//test_operators_string();
	//test_operators_movie();
	//test_find();
	test_find_predicate();
	return EXIT_SUCCESS;
}