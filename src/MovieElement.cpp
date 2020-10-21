#include <vector>

#include "MovieElement.h"

MovieElement::MovieElement()
	: movie(Movie()), weightedSum(0) {
}

MovieElement::MovieElement(const Movie& _movie)
	: movie(_movie), weightedSum(0) {
}

void MovieElement::CalculateWeightedSum(
	int year, int duration, double rating,
	const vector<string>& genres,
	const vector<string>& countries,
	const vector<string>& languages,
	const vector<string>& directors,
	const vector<string>& writers,
	const vector<string>& actors) {

	unsigned int index;
	unsigned int length;

	for (index = 0, length = genres.size(); index < length; ++index) {
		if (movie.genres.find(genres[index]) != string::npos) {
			weightedSum += 100;
		} else {
			weightedSum -= 100;
		}
	}

	for (index = 0, length = countries.size(); index < length; ++index) {
		if (movie.countries.find(countries[index]) != string::npos) {
			weightedSum += 100;
		} else {
			weightedSum -= 100;
		}
	}

	for (index = 0, length = languages.size(); index < length; ++index) {
		if (movie.languages.find(languages[index]) != string::npos) {
			weightedSum += 100;
		} else {
			weightedSum -= 100;
		}
	}

	for (index = 0, length = directors.size(); index < length; ++index) {
		if (movie.directors.find(directors[index]) != string::npos) {
			weightedSum += 100;
		} else {
			weightedSum -= 100;
		}
	}

	for (index = 0, length = writers.size(); index < length; ++index) {
		if (movie.writers.find(writers[index]) != string::npos) {
			weightedSum += 100;
		} else {
			weightedSum -= 100;
		}
	}

	for (index = 0, length = actors.size(); index < length; ++index) {
		if (movie.actors.find(actors[index]) != string::npos) {
			weightedSum += 100;
		} else {
			weightedSum -= 100;
		}
	}

	if (year != -1) {
		int deltaYear = movie.year - year;
		// carries less weight the larger the difference
		weightedSum -= deltaYear * deltaYear;
	}

	if (duration != -1) {
		int deltaDuration = movie.duration - duration;
		// carries less weight the larger the difference
		weightedSum -= deltaDuration * deltaDuration;
	}

	if (rating != -1) {
		int deltaRating = movie.rating - rating;

		if (rating < movie.rating) {
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

bool MovieElement::operator<(const MovieElement& other) {
	return other.weightedSum < weightedSum; // decending order
}


