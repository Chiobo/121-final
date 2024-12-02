#include <iostream>
#include "book.hpp"
#include "lib.hpp"
#include "LibraryUser.hpp"
#include <vector>

Library::Library() : books(), is_borrowed() {}

Library::Library(std::vector<Book*> booklist) : books(booklist) {
    is_borrowed.resize(books.size(), false); // setting all boolean values in is_borrowed vector to false
}

// book insert functions
    bool Library::insert(Book* book){

    // check: existing book with same details
    for (int i = 0; i < books.size(); i++){
        if (*book == *books[i]){
            return false;
        }
    }
    
    // inserts book into library
    books.push_back(book);
    is_borrowed.reserve(books.size());
    

    return true;
};

// book remove function
bool Library::remove(Book* book){

    // check: existing book with same details
    for (int i = 0; i < books.size(); i++){

        // searches for book in library
        if (*book == *books[i]){

            // removes book from library
            books.erase(books.begin() + i);
            is_borrowed.erase(is_borrowed.begin() + i);

            return true;
        }
    }
    return false;
};


// borrowing book function
void Library::borrow(LibraryUser user, string& title){
    for (int i = 0; i < books.size(); i++) {
        //if (*books[i].title == title && is_borrowed[i] == false && user.get_borrowed_count() < user.borrow_limit
    }

// returning book function
};

void Library::print() const{
    for (int i = 0; i < books.size(); i++){
        std::cout << "Book Index: " << i << std::endl;
        books[i]->print();
    }
};


// Define utility function
std::string to_lower(const std::string& str){
	// Copy string
	std::string lower_str = str;
	std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
	return lower_str;
}


Book* Library::advanced_search(string& title, string& author, string& genre){
	// Find title
	for (int i = 0; i < books.size(); i++){
        std::string lower_book_title = to_lower(books[i]->get_title());
		std::string lower_title = to_lower(title);

		if (lower_book_title.find(lower_title) != std::string::npos){
			return books[i];
		}
	}

	// find author
	for (int i = 0; i < books.size(); i++){
		std::string lower_book_author = to_lower(books[i]->get_author());
		std::string lower_author = to_lower(author);

		if (lower_book_author.find(lower_author) != std::string::npos){
			return books[i];
		}
	}

	// Find genre
	for (int i = 0; i < books.size(); i++){
		std::string lower_book_genre = to_lower(books[i]->get_genre());
		std::string lower_genre = to_lower(genre);

		if (lower_book_genre.find(lower_genre) != std::string::npos){
			return books[i];
		}
	}

	// if nothing, return nullptr
	return nullptr;
}