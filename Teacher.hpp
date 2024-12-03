#pragma once

#include <iostream>
#include "LibraryUser.hpp"
#include "lib.hpp"

class Library;

class Teacher : public LibraryUser
{
private:
	int borrow_limit;
	std::vector<std::string> valid_genres;

public:
	Teacher();
	Teacher(const std::string &name, const std::string &user_id, const int borrow_limit, const std::vector<std::string> valid_genres);

	int get_borrow_limit() override;
	void add_book_to_library(Library book_list, Book *book);
	void update_book_details(Library lib, const std::string &title, const std::string &author, const std::string &year_published, const std::string &genre);
	bool check_genre(std::string genre) override;

	void print();
};