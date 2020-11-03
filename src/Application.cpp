#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "MovieLibrary.h"
#include "UserInput.h"

using namespace std;

const int WIDTH = 50;

void printMenuLine(int number, string option) {
	string line;
	line += "| ";
	line += to_string(number);
	line += ". ";
	line += option;
	cout << left << setw(WIDTH) << line << setfill(' ') << "|" << endl;
}

void inputLoop(UserInput &in, MovieLibrary & library) {
	int choice;
	bool isRunning = true;
	cout << "\nYour current preference:" << endl;
	in.genres.push_back("Action");
	in.countries.push_back("USA");
	in.countries.push_back("UK");
	in.languages.push_back("English");
	in.rating = 7.0;
	in.print();
	while (isRunning) {
		cout << "+-------------------------------------------------+" << endl;
		cout << "|             Find movie menu                     |" << endl;
		printMenuLine(0, "Back to previous menu");
		printMenuLine(1, "Find movies with current preferences");
		printMenuLine(2, "Change movie year");
		printMenuLine(3, "Change duration");
		printMenuLine(4, "Change rating");
		printMenuLine(5, "Change genres");
		printMenuLine(6, "Change countries");
		printMenuLine(7, "Change languages");
		printMenuLine(8, "Change directors");
		printMenuLine(9, "Change writers");
		printMenuLine(10, "Change actors");
		cout << "+-------------------------------------------------+" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Going back to previous menu ..." << endl;
			isRunning = false;
			break;
		case 1:
			library.Sort(in);
			library.PrintFirst10MovieTitles();
			break;
		case 2:
			cout << "You choose 2" << endl;
			break;

		default:
			cout << "Invalid option." << endl;
			break;
		}
	}
}
void mainLoop(MovieLibrary& library) {
	int choice;
	bool isRunning = true;
	UserInput in;
	while (isRunning) {
		cout << "+-------------------------------------------------+" << endl;
		cout << "|             Movie Recommendation                |" << endl;
		printMenuLine(1, "Find a Movie");
		//printMenuLine(2, "See trending/popular movies");
		printMenuLine(2, "Exit program");
		cout << "+-------------------------------------------------+" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Going to find movie menu..." << endl;
			inputLoop(in, library);
			break;
		//case 2:
		//	cout << "You choose 2" << endl;
		//	break;
		case 2:
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

	MovieLibrary library;
	library.LoadLibrary("res/IMDb movies.csv");
	mainLoop(library);

	//UserInput in;
	//{// test user input
	//	in.genres.push_back("Action");
	//	in.countries.push_back("USA");
	//	in.countries.push_back("UK");
	//	in.languages.push_back("English");
	//	in.rating = 7.0;

	//	library.Sort(in);
	//	library.PrintFirst10MovieTitles();
	//}

	//{// now test with year 2015
	//	in.year = 2015;
	//	library.Sort(in);
	//	library.PrintFirst10MovieTitles();
	//}

	//{// now test with duration of 100 minutes (1:40:00)
	//	in.duration = 100; // 1:40:00
	//	library.Sort(in);
	//	library.PrintFirst10MovieTitles();
	//}

	cout << "Finished without error";
	return 0;
}
