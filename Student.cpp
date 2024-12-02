#include "Student.hpp"
#include <iostream>
#include <string>
#include <vector>

// Student Class
Student::Student() : graduated(), borrow_limit() {}
Student::Student(const std::string &name, const std::string &user_id, const bool graduated, const int borrow_limit, const std::vector<std::string> valid_genres)
{
	LibraryUser(name, user_id);
	this->graduated = graduated;
	this->borrow_limit = borrow_limit;
}

int Student::get_borrow_limit()
{
	return borrow_limit;
};

void Student::print()
{
	std::cout << "Student: ";
	LibraryUser::print_user();
	std::cout << "Graduated: " << graduated << "Borrow Limit: " << borrow_limit << std::endl;
};

bool Student::check_genre(std::string genre)
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