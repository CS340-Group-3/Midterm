#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

struct Movie {

	friend ostream& operator<<(ostream& os, const Movie& movie) {
		os << movie.title << endl;
		os << movie.year << endl;
		os << movie.genre << endl;
		os << movie.duration << endl;
		os << movie.country << endl;
		os << movie.language << endl;
		os << movie.director << endl;
		os << movie.writer << endl;
		os << movie.description << endl;
		os << movie.actors << endl;
		os << movie.rating << endl;
		return os;
	}

//public:
//	void SetTitle(const string& title);
//	void SetYear(unsigned int year);
//	void SetGenre(const string& genre);
//	void SetDuration(unsigned int duration);
//	void SetCountry(const string& country);
//	void SetLanguage(const string& language);
//	void SetDirector(const string& director);
//	void SetWriter(const string& writer);
//	void SetDescription(const string& description);
//	void SetActors(const string& actors);
//	void SetRating(double rating);
//
//	const string& GetTitle() const;
//	unsigned int GetYear() const;
//	const string& GetGenre() const;
//	unsigned int GetDuration() const;
//	const string& GetCountry() const;
//	const string& GetLanguage() const;
//	const string& GetDirector() const;
//	const string& GetWriter() const;
//	const string& GetDescription() const;
//	const string& GetActors() const;
//	double GetRating() const;
	string title;
	unsigned int year;
	string genre;
	unsigned int duration;
	string country;
	string language;
	string director;
	string writer;
	string description;
	string actors;
	double rating;

};

#endif
