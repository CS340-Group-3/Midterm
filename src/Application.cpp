#include <iostream>
#include <string>

#include "Tokenizer.h"
#include "MovieList.h"
#include "MovieParser.h"

using namespace std;

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

	MovieList list;
	MovieParser parser;
	Tokenizer tokenizer;

	// loop -> tempLine should be next line in csv file
	{
		tokenizer.Tokenize(tempLine);
		parser.ParseMovie(list, tokenizer);
	}

	// list.sort(user_input)

	list.PrintFirst10Movies();

	return 0;
}
