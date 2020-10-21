#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "MovieElement.h"
#include <vector>

class MovieList {
public:
	MovieList();

	void Add(const Movie& movie);

	void Sort(/* user input */);

	void PrintFirst10Movies();

private:
	vector<MovieElement> movies;
};

#endif