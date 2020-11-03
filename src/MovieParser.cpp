#include "MovieParser.h"

void MovieParser::ParseMovie(MovieList& list, Tokenizer& tokenizer) {
	Movie movie;

	tokenizer.NextToken(); // imdb_title_id

	tokenizer.NextToken(); // title (unused)

	movie.title = tokenizer.NextToken();

	string token = tokenizer.NextToken();
	if (token.length() == 4) {
		movie.year = stoi(token);
	} else {
		cout << "Error parsing year token '" << token << "' for movie title '" << movie.title << '\'' << endl;
	}

	tokenizer.NextToken(); // date

	movie.genres = tokenizer.NextToken();

	movie.duration = stoi(tokenizer.NextToken());

	movie.countries = tokenizer.NextToken();

	movie.languages = tokenizer.NextToken();

	movie.directors = tokenizer.NextToken();

	movie.writers = tokenizer.NextToken();

	tokenizer.NextToken(); // production company

	movie.actors = tokenizer.NextToken();

	movie.description = tokenizer.NextToken();

	movie.rating = stod(tokenizer.NextToken());

	// skip the remaining tokens:
	//    budget
	//    usa_gross_income
	//    worlwide_gross_income
	//    metascore
	//    reviews_from_users
	//    reviews_from_critics

	list.Add(movie);
}
