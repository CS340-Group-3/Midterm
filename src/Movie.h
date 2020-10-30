#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

/*
 * Represents data for a movie
 */
struct Movie {
	string title;
	int year = -1;
	string genres;
	int duration = -1;
	string countries;
	string languages;
	string directors;
	string writers;
	string description;
	string actors;
	double rating = -1;

	friend ostream& operator<<(ostream& os, const Movie& movie) {
		os << movie.title << endl;
		os << movie.year << endl;
		os << movie.genres << endl;
		os << movie.duration << endl;
		os << movie.countries << endl;
		os << movie.languages << endl;
		os << movie.directors << endl;
		os << movie.writers << endl;
		os << movie.description << endl;
		os << movie.actors << endl;
		os << movie.rating << endl;
		return os;
	}
};

#endif
