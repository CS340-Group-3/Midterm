#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <vector>

#include "MovieElement.h"

class MovieList {
public:
	MovieList();

	void Add(const Movie& movie);

	void Sort(/* user input */);

	void PrintFirst10Movies() const;

private:
	vector<MovieElement> movies;
};

#endif