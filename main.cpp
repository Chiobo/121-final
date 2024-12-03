#include <iostream>
#include <string>
#include <vector>
#include "book.hpp"
#include "lib.hpp"
#include "LibraryUser.hpp"
#include "Teacher.hpp"
#include "Student.hpp"

using namespace std;

void print_section(const string& title) {
    cout << "\n=== " << title << " ===" << endl;
}

int main() {
    // Initialize library
    Library library;
    
    print_section("Testing Book Creation and Library Insert");
    
    // Create at least 5 books as required
    Book* book1 = new Book("The Great Gatsby", "F. Scott Fitzgerald", "1925", "Fiction");
    Book* book2 = new Book("To Kill a Mockingbird", "Harper Lee", "1960", "Fiction");
    Book* book3 = new Book("Introduction to Algorithms", "Thomas H. Cormen", "1990", "Computer Science");
    Book* book4 = new Book("Physics for Scientists", "Raymond A. Serway", "2000", "Science");
    Book* book5 = new Book("Pride and Prejudice", "Jane Austen", "1813", "Fiction");
    
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
    
    Teacher teacher("John Smith", "T001", 5, teacher_genres);
    Student student("Alice Johnson", "S001", false, 2, student_genres);
    
    print_section("Testing Borrowing System");
    
    // Test borrowing books
    string book_title = "The Great Gatsby";
    cout << "Student attempting to borrow '" << book_title << "'..." << endl;
    library.borrow_book(student, book_title);
    
    book_title = "Introduction to Algorithms";
    cout << "\nStudent attempting to borrow '" << book_title << "'..." << endl;
    library.borrow_book(student, book_title);
    
    // Try to borrow beyond limit
    book_title = "Pride and Prejudice";
    cout << "\nStudent attempting to borrow beyond limit '" << book_title << "'..." << endl;
    library.borrow_book(student, book_title);
    
    print_section("Testing Book Return");
    
    // Test returning a book
    book_title = "The Great Gatsby";
    cout << "Student returning '" << book_title << "'..." << endl;
    library.return_book(student, book_title);
    
    print_section("Testing Advanced Search");
    
    // Test advanced search functionality
    cout << "Searching for books with 'the' in title:" << endl;
    library.advanced_search("the");
    
    cout << "\nSearching for books by 'Fitzgerald':" << endl;
    library.advanced_search("", "Fitzgerald");
    
    print_section("Testing Teacher Special Functions");
    
    // Test teacher adding a book
    Book* new_book = new Book("Advanced Mathematics", "Jane Doe", "2020", "Mathematics");
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