#include <iostream>
#include <string>

#include <fstream>

#include "MovieLibrary.h"
#include "UserInput.h"

using namespace std;

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

	MovieLibrary library;
	library.LoadLibrary("res/IMDb movies.csv");

	UserInput in;

	{// test user input
		in.genres.push_back("Action");
		in.countries.push_back("USA");
		in.countries.push_back("UK");
		in.languages.push_back("English");
		in.rating = 7.0;

		library.Sort(in);
		library.PrintFirst10Movies();
	}

	{// now test with year 2015
		in.year = 2015;
		library.Sort(in);
		library.PrintFirst10Movies();
	}

	{// now test with duration of 100 minutes (1:40:00)
		in.duration = 100; // 1:40:00
		library.Sort(in);
		library.PrintFirst10Movies();
	}

	library.Sort(in);
	return 0;
}
