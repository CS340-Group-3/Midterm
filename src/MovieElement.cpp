#include <vector>

#include "MovieElement.h"

MovieElement::MovieElement()
	: movie(Movie()), weightedSum(0) {
}

MovieElement::MovieElement(const Movie& _movie)
	: movie(_movie), weightedSum(0) {
}

void MovieElement::CalculateWeightedSum(const UserInput& input) {
	// reset sum before calculating
	weightedSum = 0;

	CalculateWeight(input.genres,    movie.genres,    10);
	CalculateWeight(input.countries, movie.countries, 10);
	CalculateWeight(input.languages, movie.languages, 10);
	CalculateWeight(input.directors, movie.directors, 10);
	CalculateWeight(input.writers,   movie.writers,   10);
	CalculateWeight(input.actors,    movie.actors,    10);

	if (input.year != -1) {
		int deltaYear = movie.year - input.year;
		// carries less weight the larger the difference
		weightedSum -= (double) deltaYear * deltaYear;
	}

	if (input.duration != -1) {
		int deltaDuration = movie.duration - input.duration;
		// carries less weight the larger the difference
		weightedSum -= (double) deltaDuration * deltaDuration;
	}

	if (input.rating != -1) {
		double deltaRating = movie.rating - input.rating;

		if (input.rating < movie.rating) {
			// carries more weight if the movie rating
			// is better than user input
			weightedSum += deltaRating * deltaRating;
		} else {
			// carries less weight if the movie rating
			// is worse than user input
			weightedSum -= deltaRating * deltaRating;
		}
	}
}

void MovieElement::CalculateWeight(const vector<string> list, const string& str, double weight) {
	unsigned int length = list.size();
	unsigned int index = 0;

	for (; index < length; ++index) {
		if (str.find(list[index]) != string::npos) {
			// found, carries more weight
			weightedSum += weight * weight;
		} else {
			// not found, carries less weight
			weightedSum -= weight * weight;
		}
	}
}

bool MovieElement::operator<(const MovieElement& other) {
	return other.weightedSum < weightedSum; // decending order
}


