#include <iostream>
#include <string>

#include <fstream>

#include "Tokenizer.h"
#include "MovieList.h"
#include "MovieParser.h"

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

	ifstream input;

	input.open("res/IMDb movies.csv");

	if (input.fail()) {
		cout << "Error. Cannot open file" << endl;
		exit(1);
	}

	MovieList list;
	MovieParser parser;
	Tokenizer tokenizer;
	string csvLine;

	cout << "Parsing movie library" << endl;

	// skip the first csv line, its just
	// the format of the csv data
	getline(input, csvLine);
	tokenizer.Tokenize(csvLine);

	while (getline(input, csvLine)) {
		tokenizer.Tokenize(csvLine);
		parser.ParseMovie(list, tokenizer);
	}

	input.close();

	UserInput in;
	in.genres.push_back("Action");
	in.countries.push_back("USA");
	in.countries.push_back("UK");
	in.languages.push_back("English");
	in.rating = 7.0;
	in.year = 2010;

	list.Sort(in);
	

	return 0;
}
