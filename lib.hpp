#ifndef LIB_HPP
#define LIB_HPP

#include "book.hpp"
#include "LibraryUser.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include <vector>
#include <string>

using namespace std;

class Teacher;
class Student;

class Library
{
private:
	std::vector<bool> is_borrowed;

public:
	std::vector<Book *> books;
	Library();
	Library(std::vector<Book *> booklist);

	bool insert(Book *book);
	bool insert(Book book);
	bool insert(string title, string author, string year_published, string genre);

	bool remove(Book *book);
	bool remove(Book book);
	bool remove(string title, string author, string year_published, string genre);

	void borrow_book(LibraryUser *user, const string &title);
	void borrow_book(Student user, const string &title);
	void borrow_book(Teacher user, const string &title);
	void return_book(LibraryUser user, const string &title);

	void advanced_search(const string &title, const string &author, const string &genre);
	void advanced_search(const string &title, const string &author);
	void advanced_search(const string &title);

	void print() const;

	int find_title(const string &title);
};

#endif