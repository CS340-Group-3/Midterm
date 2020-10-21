#include <iostream>
#include <string>

#include "Movie.h"
#include "MovieList.h"
#include "MovieElement.h"
#include "Tokenizer.h"

using namespace std;

Movie ParseMovie(Tokenizer& tokenizer);

// entry point
int main() {
	/*
	Create Tokenizer
	Open csv file:
	For each line of csv:
		tokenize(line)
		Parse tokens into Movie object
		Add Movie into MovieList
	Input menu for user input:
	movieList.sort(input)
	movieList.PrintFirst10Movies()
	*/

	string tempLine = R"(tt0002101,Cleopatra,Cleopatra,1912,1912-11-13,"Drama, History",100,USA,English,Charles L. Gaskill,Victorien Sardou,Helen Gardner Picture Players,"Helen Gardner, Pearl Sindelar, Miss Fielding, Miss Robson, Helene Costello, Charles Sindelar, Mr. Howard, James R. Waite, Mr. Osborne, Harry Knowles, Mr. Paul, Mr. Brady, Mr. Corker",The fabled queen of Egypt's affair with Roman general Marc Antony is ultimately disastrous for both of them.,5.2,446,$ 45000,,,,25.0,3.0)";
	//string tempLine = R"(imdb_title_id,title,original_title,year,date_published,genre,duration,country,language,director,writer,production_company,actors,description,avg_vote,votes,budget,usa_gross_income,worlwide_gross_income,metascore,reviews_from_users,reviews_from_critics)";

	Tokenizer tokenizer;
	MovieList list;

	// loop -> tempLine should be next line in csv file
	tokenizer.Tokenize(tempLine);
	list.Add(ParseMovie(tokenizer));

	list.PrintFirst10Movies();

	return 0;
}

Movie ParseMovie(Tokenizer& tokenizer) {
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

	return movie;
}
