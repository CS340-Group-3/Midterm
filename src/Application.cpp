#include <iostream>
#include <string>

#include "Movie.h"
#include "MovieList.h"
#include "MovieElement.h"
#include "Tokenizer.h"

using namespace std;

Movie ParseMovie(Tokenizer& tokenizer);

void menuLoop() {
	int choice;
	bool isRunning = true;
	while (isRunning) {
		cout << "+-----------------------------------------------+" << endl;
		cout << "|        Menu Recommendation Program            |" << endl;
		cout << "| 1. Find a movie.                              |" << endl;
		cout << "| 2. See trending/popular movies.               |" << endl;
		cout << "| 3. Exit program.                              |" << endl;
		cout << "|                                               |" << endl;
		cout << "+-----------------------------------------------+" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "You choose 1" << endl;
			break;
		case 2:
			cout << "You choose 2" << endl;
			break;
		case 3:
			cout << "You choose 3" << endl;
			isRunning = false;
				break;
		default:
			cout << "Invalid option." << endl;
			break;
		}
	}
}

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
	menuLoop();

	// string tempLine = R"(tt0002101,Cleopatra,Cleopatra,1912,1912-11-13,"Drama, History",100,USA,English,Charles L. Gaskill,Victorien Sardou,Helen Gardner Picture Players,"Helen Gardner, Pearl Sindelar, Miss Fielding, Miss Robson, Helene Costello, Charles Sindelar, Mr. Howard, James R. Waite, Mr. Osborne, Harry Knowles, Mr. Paul, Mr. Brady, Mr. Corker",The fabled queen of Egypt's affair with Roman general Marc Antony is ultimately disastrous for both of them.,5.2,446,$ 45000,,,,25.0,3.0)";
	// string tempLine = R"(imdb_title_id,title,original_title,year,date_published,genre,duration,country,language,director,writer,production_company,actors,description,avg_vote,votes,budget,usa_gross_income,worlwide_gross_income,metascore,reviews_from_users,reviews_from_critics)";

	// Tokenizer tokenizer;
	// MovieList list;

	// loop -> tempLine should be next line in csv file
	// tokenizer.Tokenize(tempLine);
	// list.Add(ParseMovie(tokenizer));
	// list.PrintFirst10Movies();

	

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
