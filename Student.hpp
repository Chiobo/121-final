#pragma once
#include "LibraryUser.hpp"

class Student : public LibraryUser
{
private:
	bool graduated;
	int borrow_limit;
	std::vector<std::string> valid_genres;

public:
	Student();
	Student(const std::string &name, const std::string &user_id, const bool graduated, const int borrow_limit, const std::vector<std::string> valid_genres);

	int get_borrow_limit() override;
	void print();
	bool check_genre(std::string genre) override;
};
