#ifndef MOVIELIST_H
#define MOVIELIST_H

#include <vector>

#include "MovieElement.h"

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
	 * Sorts the movie list using the parameters to
	 * calculate weighted sums for each movie in the
	 * list.
	 *
	 * After weights are calculated, the movie list
	 * will be sorted in decending order based on
	 * their weight.
	 */
	void Sort(
		int year, int duration, double rating,
		const vector<string>& genres,
		const vector<string>& countries,
		const vector<string>& languages,
		const vector<string>& directors,
		const vector<string>& writers,
		const vector<string>& actors);

	/* Prints the first 10 movies from the movie list */
	void PrintFirst10Movies() const;

private:
	/* the list of movies */
	vector<MovieElement> movies;
};

#endif