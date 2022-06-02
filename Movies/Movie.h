#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie
{
public:
	// Movie() = delete;  // delete gift
	Movie() = default; // reactivate gift
	// Movie(); // custom
	Movie(const std::string& title, int year);
	Movie(const std::string& title, int year, int duration);
	//Movie(const Movie& other) = delete;
	//Movie(Movie&& other) = delete;

	virtual ~Movie();

	//Movie& operator=(const Movie& other) = delete;
	bool operator==(const Movie& other) const;
	bool operator!=(const Movie& other) const;
	bool operator<(const Movie& other) const;
	bool operator<=(const Movie& other) const;
	bool operator>(const Movie& other) const;
	bool operator>=(const Movie& other) const;

	const std::string& getTitle() const;
	void setTitle(const std::string& title);

	int getYear() const;
	void setYear(int year);

	int getDuration() const;
	void setDuration(int duration);

	std::string toString() const;

private:
	std::string mTitle;
	int mYear;
	int mDuration;
};

std::ostream& operator<<(std::ostream& out, const Movie& movie);

#endif // !MOVIE_H



