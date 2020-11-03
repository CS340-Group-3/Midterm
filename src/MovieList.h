#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <vector>

#include "MovieElement.h"
#include "UserInput.h"

/*
 * A MovieList holds a list of MovieElements,
 * which can be sorted by user input.
 */
class MovieList {
public:
	MovieList();

	/* Adds a movie to the movie list */
	void Add(const Movie& movie);

	/*
	 * Sorts the movie list using data from user input
	 * to calculate weighted sums for each movie in the
	 * list.
	 *
	 * After weights are calculated, the movie list will
	 * be sorted in decending order based on their weight.
	 */
	void Sort(const UserInput& input);

	/* Prints the first 10 movies from the movie list */
	void PrintFirst10Movies() const;

private:
	/* the list of movies */
	vector<MovieElement> movies;
};

#endif