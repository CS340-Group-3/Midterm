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

	MovieList list;
	MovieParser parser;
	Tokenizer tokenizer;

	ifstream input;

	input.open("res/IMDb movies.csv");

	if (input.fail()) {
		cout << "Error. Cannot open file" << endl;
		exit(1);
	}

	string csvLine;
	getline(input, csvLine);
	tokenizer.Tokenize(csvLine);

	while (getline(input, csvLine)) {
		tokenizer.Tokenize(csvLine);
		parser.ParseMovie(list, tokenizer);
	}

	input.close();

	// list.sort(user_input)

	list.PrintFirst10Movies();

	return 0;
}
