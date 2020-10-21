#ifndef MOVIEELEMENT_H
#define MOVIEELEMENT_H

#include <string>

#include "Movie.h"

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
	void CalculateWeightedSum(
		int year, int duration, double rating,
		const vector<string>& genre,
		const vector<string>& countries,
		const vector<string>& languages,
		const vector<string>& directors,
		const vector<string>& writers,
		const vector<string>& actors);

private:
	Movie movie;
	int weightedSum;
};

#endif