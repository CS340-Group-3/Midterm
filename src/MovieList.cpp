#include <iostream>
#include <algorithm>

#include "MovieList.h"

using namespace std;

MovieList::MovieList()
	: movies(0) {
}

void MovieList::Add(const Movie& movie) {
	// uses implicit MovieElement constructor
	movies.push_back(movie);
}

void MovieList::Sort(
	int year, int duration, double rating,
	const vector<string>& genres,
	const vector<string>& countries,
	const vector<string>& languages,
	const vector<string>& directors,
	const vector<string>& writers,
	const vector<string>& actors) {

	unsigned int size = min((int)movies.size(), 10);
	unsigned int index;

	for (index = 0; index < size; ++index) {
		movies[index].CalculateWeightedSum(
			year, duration, rating,
			genres, countries, languages,
			directors, writers, actors
		);
	}

	sort(movies.begin(), movies.end());
}

void MovieList::PrintFirst10Movies() const {
	unsigned int size = min((int) movies.size(), 10);
	unsigned int index;

	for (index = 1; index <= size; ++index) {
		Movie movie = movies[index - 1].GetMovie();
		cout << index << ". '" << movie.title << '\'' << endl;
		cout << '\t' << "Duration:    " << movie.duration << " minutes" << endl;
		cout << '\t' << "Rated:       " << movie.rating << endl;
		cout << '\t' << "Description: " << movie.description << endl;
		cout << endl;
	}
}
