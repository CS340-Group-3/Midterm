#ifndef MOVIEPARSER_H
#define MOVIEPARSER_H

#include "MovieList.h"
#include "Tokenizer.h"

/*
 * A MovieParser can parse a Movie into a MovieList
 * using a tokenizer.
 */
class MovieParser {
public:
    /* Parses a movie into a movie list using a tokenizer */
	void ParseMovie(MovieList& list, Tokenizer& tokenizer);
};

#endif
