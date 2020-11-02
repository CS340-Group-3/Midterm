#include <iostream>
#include <string>

#include <fstream>

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

	list.PrintFirst10Movies();

	return 0;
}
