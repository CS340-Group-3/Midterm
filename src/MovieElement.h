#ifndef MOVIEELEMENT_H
#define MOVIEELEMENT_H

#include "Movie.h"
#include <string>

using namespace std;

class MovieElement {
public:
	MovieElement();

	explicit MovieElement(const Movie& movie);

	bool operator<(const MovieElement& other);

	const Movie& GetMovie() const {
		return movie;
	}

private:
	void CalculateWeightedSum(/* user input */);

private:
	Movie movie;
	int weightedSum;
};

#endif