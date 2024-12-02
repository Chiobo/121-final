#ifndef LIBRARYUSER
#define LIBRARYUSER

#include "book.hpp"
#include <string>

class LibraryUser
{
protected:
	std::string name;
	std::string user_id;
	int borrowed_count;

public:
	// constructors

	LibraryUser(); // default constructor
	LibraryUser(const std::string &name, const std::string &user_id);

	// getter functions for private class variables
	std::string get_name();

	std::string User_ID();

	int get_borrowed_count();

	// class functions
	void borrow_book();

	void return_book();

	void print_user();
	virtual int get_borrow_limit();
	virtual bool check_genre(std::string genre);
};

#endif