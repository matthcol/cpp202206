#include "Movie.h"

#include <iostream>
#include <sstream>

//Movie::Movie():mTitle("#N/A"),mYear(-1),mDuration(-1)
//{
//}

Movie::Movie(const std::string& title, int year):Movie(title,year,-1)
{
}

Movie::Movie(const std::string& title, int year, int duration):
	mTitle(title),mYear(year),mDuration(duration)
{
	//mTitle = title;
	//this->mYear = year;
	//(*this).mDuration = duration;
}

Movie::~Movie()
{
	std::clog << "Movie destroyed: " << this << std::endl;
}

bool Movie::operator==(const Movie& other)
{
	// TODO (opt) : check if same object in memory
	return (this->mTitle == other.mTitle)
		&& (this->mYear == other.mYear);
}

bool Movie::operator!=(const Movie& other)
{
	return !(*this == other);
}

bool Movie::operator<(const Movie& other)
{
	if (this->mYear == other.mYear) 
	{
		return this->mTitle < other.mTitle;
	}	
	else 
	{
		return this->mYear > other.mYear;
	}
}

bool Movie::operator<=(const Movie& other)
{
	return (*this < other) || (*this == other);
}

bool Movie::operator>(const Movie& other)
{
	return !((*this < other) || (*this == other));
}

bool Movie::operator>=(const Movie& other)
{
	return !(*this < other);
}

const std::string& Movie::getTitle() const
{
	return mTitle;
}

void Movie::setTitle(const std::string& title)
{
	this->mTitle = title;
}

int Movie::getYear() const
{
	return  mYear;
}

void Movie::setYear(int year)
{
	this->mYear = year;
}

int Movie::getDuration() const
{
	return mDuration;
}

void Movie::setDuration(int duration)
{
	this->mDuration = duration;
}

std::string Movie::toString() const
{
	return (std::stringstream()
		<< mTitle
		<< " ("
		<< mYear
		<< " ; "
		<< mDuration
		<< " mn)")
		.str();
}

std::ostream& operator<<(std::ostream& out, const Movie& movie)
{
	return out << movie.toString();
}
