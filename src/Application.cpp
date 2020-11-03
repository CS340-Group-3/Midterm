#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "Tokenizer.h"
#include "MovieList.h"
#include "MovieParser.h"

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

void updateInput(short& value) {
	short tmp;
	system("CLS");
	cout << "Current value: ";
	if (value != -1) cout << value << endl;
	else cout << "(not set)" << endl;
	cout << "Enter new value: ";
	cin >> tmp;
	value = tmp;
	return;
}

void updateInput(double& value) {
	double tmp;
	system("CLS");
	cout << "Current value: ";
	if (value != -1) cout << value << endl;
	else cout << "(not set)" << endl;
	cout << "Enter new value: ";
	cin >> tmp;
	value = tmp;
	return;
}

void updateInput(vector <string> &v) {
	int choice;
	bool isRunning = true;
	while (isRunning) {
		system("CLS");
		string delim = "";
		string tmp;
		int indx;
		cout << "Current values: ";

		if (v.size() == 0) cout << "(not set)" << endl;
		else
		{
			for (auto value : v) {
				cout << delim << value;
				delim = ", ";
			}
			delim = "";
			cout << endl;
		}
		cout << "+-------------------------------------------------+" << endl;
		cout << "|             Update preference                   |" << endl;
		printMenuLine(0, "Back to previous menu");
		printMenuLine(1, "Remove element from preferences list");
		printMenuLine(2, "Add new element to preferences");
		cout << "+-------------------------------------------------+" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "Going back to previous menu ..." << endl;
			isRunning = false;
			system("CLS");
			break;
		case 1:
			
			for (int i = 0; i < v.size(); i++) {
				cout << i + 1 << ". " << v[i] << endl;
			}
			cout << "Select value to remove";
			cin >> indx;
			if (0 <= indx && indx <= v.size()) {
				v.erase(v.begin() + indx - 1);
			}
			break;
		case 2:
			cout << "Enter new value to add: ";
			cin >> tmp;
			v.push_back(tmp);
			system("CLS");
			break;
		default:
			cout << "Invalid option." << endl;
			break;
		}
	}
}

void inputLoop(UserInput &in, MovieList &list) {
	int choice;
	bool isRunning = true;
	
	in.genres.push_back("Action");
	in.countries.push_back("USA");
	in.countries.push_back("UK");
	in.languages.push_back("English");
	in.rating = 7.0;
	
	while (isRunning) {
		//system("CLS");
		cout << "Your current preference:" << endl;
		in.print();
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
			list.Sort(in);
			list.PrintFirst10MoviesTitle();
			break;
		case 2:
			updateInput(in.year);
			system("CLS");
			break;
		case 3:
			updateInput(in.duration);
			system("CLS");
			break;
		case 4:
			updateInput(in.rating);
			system("CLS");
			break;
		case 5:
			updateInput(in.genres);
			break;
		case 6:
			updateInput(in.countries);
			break;
		case 7:
			updateInput(in.languages);
			break;
		case 8:
			updateInput(in.directors);
			break;
		case 9:
			updateInput(in.writers);
			break;
		case 10:
			updateInput(in.actors);
			break;
		default:
			cout << "Invalid option." << endl;
			break;
		}
	}
}
void mainLoop(MovieList& list) {
	int choice;
	bool isRunning = true;
	UserInput in;
	while (isRunning) {
		system("CLS");
		cout << "+-------------------------------------------------+" << endl;
		cout << "|             Movie Recommendation                |" << endl;
		printMenuLine(0, "Exit program");
		printMenuLine(1, "Find a Movie");
		//printMenuLine(2, "See trending/popular movies");
		
		cout << "+-------------------------------------------------+" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
			isRunning = false;
			break;
		case 1:
			cout << "Going to find movie menu..." << endl;
			system("CLS");
			inputLoop(in, list);
			break;
		//case 2:
		//	cout << "You choose 2" << endl;
		//	break;
		
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
	
	mainLoop(list);
	UserInput in;
	{// test user input
		in.genres.push_back("Action");
		in.countries.push_back("USA");
		in.countries.push_back("UK");
		in.languages.push_back("English");
		in.rating = 7.0;

		list.Sort(in);
		list.PrintFirst10Movies();
	}

	{// now test with year 2015
		in.year = 2015;
		list.Sort(in);
		list.PrintFirst10Movies();
	}

	{// now test with duration of 100 minutes (1:40:00)
		in.duration = 100; // 1:40:00
		list.Sort(in);
		list.PrintFirst10Movies();
	}

	list.Sort(in);
	cout << "Finished without error";
	return 0;
}
