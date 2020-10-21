#include <iostream>
#include <algorithm>

#include "MovieList.h"

using namespace std;

MovieList::MovieList()
	: movies(0) {
}

void MovieList::Add(const Movie& movie) {
	movies.push_back(MovieElement(movie));
}

void MovieList::Sort() {
}

void MovieList::PrintFirst10Movies() const {
	unsigned int len = min((int) movies.size(), 10);

	for (unsigned int index = 1; index <= len; ++index) {
		Movie movie = movies[index - 1].GetMovie();
		cout << index << ". '" << movie.title << '\'' << endl;
		cout << '\t' << "Duration: " << movie.duration << " minutes" << endl;
		cout << '\t' << "Rated: " << movie.rating << endl;
		cout << '\t' << "Description: " << movie.description << endl;
	}
}
