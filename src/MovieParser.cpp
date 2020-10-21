#include "MovieParser.h"

void MovieParser::ParseMovie(MovieList& list, Tokenizer& tokenizer) {
	Movie movie;

	tokenizer.NextToken(); // imdb_title_id
	movie.title = tokenizer.NextToken();
	tokenizer.NextToken(); // original_title
	movie.year = stoi(tokenizer.NextToken());
	tokenizer.NextToken(); // date
	movie.genre = tokenizer.NextToken();
	movie.duration = stoi(tokenizer.NextToken());
	movie.country = tokenizer.NextToken();
	movie.language = tokenizer.NextToken();
	movie.director = tokenizer.NextToken();
	movie.writer = tokenizer.NextToken();
	tokenizer.NextToken(); // production company
	movie.actors = tokenizer.NextToken();
	movie.description = tokenizer.NextToken();
	movie.rating = stod(tokenizer.NextToken());

	// skip the remaining tokens:
	// budget
	// usa_gross_income
	// worlwide_gross_income
	// metascore
	// reviews_from_users
	// reviews_from_critics

	list.Add(movie);
}
