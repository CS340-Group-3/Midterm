#include <iostream>
#include <algorithm>

#include "MovieList.h"

using namespace std;

MovieList::MovieList() {
}

void MovieList::Add(const Movie& movie) {
}

void MovieList::Sort() {
}

void MovieList::PrintFirst10Movies() {
	unsigned int len = min((int) movies.size(), 10);

	for (unsigned int index = 0; index < len; ++index) {
		cout << index << ". \t" << movies[index].GetMovie();
	}
}
