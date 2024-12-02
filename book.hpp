#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book
{

private:
	std::string title;
	std::string authors;
	std::string year_published;
	std::string genre;

public:
	// constructors
	Book();
	Book(const std::string &ntitle, const std::string &nauthors, const std::string nyear_published, const std::string &ngenre);
	Book(const std::string &ntitle, const std::string &nauthors, const std::string nyear_published);
	Book(const std::string &ntitle, const std::string &nauthors);
	Book(const std::string &ntitle);

	// getting functions
	std::string get_title();
	std::string get_author();
	std::string get_genre();
	std::string get_year_published();

	// equality operator overloading
	bool operator==(const Book &other) const;

	// print function
	void print() const;

	void update_book(const std::string &ntitle, const std::string &nauthors, const std::string nyear_published, const std::string &ngenre);
};

#endif