#include "Teacher.hpp"
#include "lib.hpp"

#include <iostream>
#include <string>
#include "util.hpp"

// Teacher Class

// defining constructors
Teacher::Teacher() : borrow_limit() {}
Teacher::Teacher(const std::string &name, const std::string &user_id, const int borrow_limit, const std ::vector<std::string> valid_genres)
{
	LibraryUser(name, user_id);
	this->borrow_limit = borrow_limit;
	this->valid_genres = valid_genres;
}

// defining getter function
int Teacher::get_borrow_limit()
{
	return borrow_limit;
};

void Teacher::add_book_to_library(Library books_list, Book *book)
{
	books_list.insert(book);
}
void Teacher::update_book_details(Library lib, const std::string &title, const std::string &author, const std::string &year_published, const std::string &genre)
{
	// find index of book
	int found_idx = -1;
	for (int i = 0; i < lib.books.size(); i++)
	{
		if (lib.books[i]->get_title() == title)
		{
			found_idx = i;
			break;
		}
	}

	if (found_idx == -1)
	{
		std::cout << "Book not found" << std::endl;
		return;
	}

	lib.books[found_idx]->update_book(title, author, year_published, genre);
};

bool Teacher::check_genre(std::string genre)
{
	for (int i = 0; i < valid_genres.size(); i++)
	{
		if (valid_genres[i] == genre)
		{
			return true;
		}
	}
	return false;
};

// defining print

void Teacher::print()
{
	std::cout << "Teacher: ";
	LibraryUser::print_user();
	std::cout << "Borrow Limit: " << borrow_limit << std::endl;
};