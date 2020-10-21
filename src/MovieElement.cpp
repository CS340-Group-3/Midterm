#include "MovieElement.h"

MovieElement::MovieElement(const Movie& _movie)
	: movie(_movie), weightedSum(0) {
}

void MovieElement::CalculateWeightedSum() {
}

bool MovieElement::operator<(const MovieElement& other) {
	return other.weightedSum < weightedSum; // decending order
}


