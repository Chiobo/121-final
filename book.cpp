#include <iostream>
#include <string>
#include "book.hpp"
using namespace std;

// class constructors
Book::Book()
{
	title = "n/a";
	authors = "n/a";
	year_published = "n/a";
	genre = "n/a";
}

Book::Book(const string &ntitle)
{

	title = ntitle;
	authors = "n/a";
	year_published = "n/a";
	genre = "n/a";
}

Book::Book(const string &ntitle, const string &nauthors)
{
	title = ntitle;
	authors = nauthors;
	year_published = "n/a";
	genre = "n/a";
}

Book::Book(const string &ntitle, const string &nauthors, const std::string nyear_published)
{
	title = ntitle;
	authors = nauthors;
	year_published = "n/a";
	genre = "n/a";
}

Book::Book(const string &ntitle, const string &nauthors, const std::string nyear_published, const string &ngenre)
{
	title = ntitle;
	authors = nauthors;
	year_published = nyear_published;
	genre = ngenre;
}

// getter functions
string Book::get_title()
{
	return title;
}

string Book::get_author()
{
	return authors;
}

string Book::get_genre()
{
	return genre;
}

string Book::get_year_published()
{
	return year_published;
}

// overloaded boolean operator==
bool Book::operator==(const Book &other) const
{
	return (title == other.title &&
			authors == other.authors &&
			year_published == other.year_published &&
			genre == other.genre);
}

// print function
void Book::print() const
{
	cout << "🔖 Title: " << title << endl;
	cout << "👤 Authors: " << authors << endl;
	cout << "📅 Year Published: " << year_published << endl;
	cout << "📚 Genre(s): " << genre << endl;
}

void Book::update_book(const std::string &ntitle, const std::string &nauthors, const std::string nyear_published, const std::string &ngenre)
{

	title = ntitle;
	authors = nauthors;
	year_published = nyear_published;
	genre = ngenre;
}
