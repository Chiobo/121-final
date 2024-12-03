#include <iostream>
#include "LibraryUser.hpp" // class declaration
#include <string>

// Parent Class LibraryUser

// defining constructors
LibraryUser::LibraryUser() : name(), user_id(), borrowed_count(0) {} // default constructor
LibraryUser::LibraryUser(const std::string &name, const std::string &user_id) : LibraryUser()
{
	this->name = name;
	this->user_id = user_id;
}

// getter functions for private class variables
std::string LibraryUser::get_name()
{
	return name;
};

std::string LibraryUser::get_user_id()
{
	return user_id;
};

int LibraryUser::get_borrowed_count()
{
	return borrowed_count;
};

// functions
void LibraryUser::borrow_book()
{
	borrowed_count++;
};

void LibraryUser::return_book()
{
	if (borrowed_count == 0)
	{
		std::cout << "No books to return" << std::endl;
		return;
	}
	borrowed_count--;
};

void LibraryUser::print_user()
{
	std::cout << "🏷️ Name: " << name << std::endl;
	std::cout << "👤 User ID: " << user_id << std::endl;
	std::cout << "🔢 Borrowed Count: " << borrowed_count << std::endl;
};

int LibraryUser::get_borrow_limit()
{
	return 0;
}

bool LibraryUser::check_genre(std::string genre)
{
	return true;
};
