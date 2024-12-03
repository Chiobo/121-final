#include <iostream>
#include <string>
#include <vector>
#include "book.hpp"
#include "lib.hpp"
#include "LibraryUser.hpp"
#include "Teacher.hpp"
#include "Student.hpp"

using namespace std;

void print_section(const string &title)
{
	cout << "\n=== " << title << " ===" << endl;
}

int main()
{
	print_section("Testing Book Constructors");

	// Test default constructor
	cout << "Testing default constructor:" << endl;
	Book default_book;
	default_book.print();

	// Test single parameter constructor (title only)
	cout << "\nTesting single parameter constructor:" << endl;
	Book single_param("1984");
	single_param.print();

	// Test two parameter constructor (title and author)
	cout << "\nTesting two parameter constructor:" << endl;
	Book two_param("Animal Farm", "George Orwell");
	two_param.print();

	// Test three parameter constructor (title, author, year)
	cout << "\nTesting three parameter constructor:" << endl;
	Book three_param("Brave New World", "Aldous Huxley", "1932");
	three_param.print();

	// Test four parameter constructor (title, author, year, genre)
	cout << "\nTesting four parameter constructor:" << endl;
	Book four_param("Lord of the Rings", "J.R.R. Tolkien", "1954", "Fantasy");
	four_param.print();

	// Initialize library
	Library library;

	print_section("Testing Book Creation and Library Insert");

	// Create at least 5 books as required
	Book *book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "1925", "Fiction");
	Book *book2 = new Book("To Kill a Mockingbird", "Harper Lee", "1960");
	Book *book3 = new Book("Introduction to Algorithms", "Thomas H. Cormen", "1990", "Computer Science");
	Book *book4 = new Book("Physics for Scientists");
	Book *book5 = new Book("Pride and Prejudice", "Jane Austen", "1813", "Fiction");

	// Test insertion
	cout << "Inserting books into library..." << endl;
	library.insert(book1);
	library.insert(book2);
	library.insert(book3);
	library.insert(book4);
	library.insert(book5);

	// Print initial library state
	cout << "\nInitial library contents:" << endl;
	library.print();

	print_section("Testing Book Removal");

	// Test book removal
	cout << "Removing 'Physics for Scientists'..." << endl;
	library.remove(book4);

	cout << "\nLibrary contents after removal:" << endl;
	library.print();

	print_section("Testing Library Users");

	// Create teacher and student with valid genres
	vector<string> teacher_genres = {"Fiction", "Science", "Computer Science"};
	vector<string> student_genres = {"Fiction", "Computer Science"};

	Teacher teacher("John Smith", "T001", 2, teacher_genres);
	Student student("Alice Johnson", "S001", false, 1, student_genres);

	print_section("Testing Borrowing System");

	// Test borrowing books for student
	string book_title = "The Great Gatsby";
	cout << "Student attempting to borrow '" << book_title << "'..." << endl;
	library.borrow_book(&student, book_title);

	// Try to borrow beyond limit for student
	book_title = "Pride and Prejudice";
	cout << "\nStudent attempting to borrow beyond limit '" << book_title << "'..." << endl;
	library.borrow_book(&student, book_title);

	// Test borrowing books for teacher
	book_title = "To Kill a Mockingbird";
	cout << "Teacher attempting to borrow out of genre: '" << book_title << "'..." << endl;
	library.borrow_book(&teacher, book_title);

	// Try to borrow beyond limit for teacher
	book_title = "The Great Gatsby";
	cout << "\nTeacher attempting to borrow an already borrowed book: '" << book_title << "'..." << endl;
	library.borrow_book(&teacher, book_title);

	print_section("Testing Book Return");

	// Test returning a book for student
	book_title = "The Great Gatsby";
	cout << "Student returning '" << book_title << "'..." << endl;
	library.return_book(&student, book_title);

	// Test returning a book for teacher [expecting to fail]
	book_title = "Introduction to Algorithms";
	cout << "Teacher returning '" << book_title << "'..." << endl;
	library.return_book(&teacher, book_title);

	print_section("Testing Advanced Search");

	// Test advanced search functionality
	cout << "Searching for books with 'the' in title:" << endl;
	library.advanced_search("the");

	cout << "\nSearching for books by 'Fitzgerald':" << endl;
	library.advanced_search("", "Fitzgerald");

	print_section("Testing Teacher Special Functions");

	// Test teacher adding a book
	Book *new_book = new Book("Advanced Mathematics", "Jane Doe", "2020", "Mathematics");
	teacher.add_book_to_library(library, new_book);

	// Test teacher updating book details
	cout << "\nTeacher updating book details..." << endl;
	teacher.update_book_details(library, "The Great Gatsby", "F. Scott Fitzgerald", "1925", "Classic Fiction");

	print_section("Final Library State");
	library.print();

	// Cleanup
	delete book1;
	delete book2;
	delete book3;
	delete book4;
	delete book5;
	delete new_book;

	return 0;
}