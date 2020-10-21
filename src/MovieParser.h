#ifndef MOVIEPARSER_H
#define MOVIEPARSER_H

#include "MovieList.h"
#include "Tokenizer.h"

class MovieParser {
public:
	void ParseMovie(MovieList& list, Tokenizer& tokenizer);
};

#endif
