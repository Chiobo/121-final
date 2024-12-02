#include <iostream>
#include "book.hpp"
#include "lib.hpp"
#include "LibraryUser.hpp"
#include <vector>

        Library::Library() : books(), is_borrowed() {};

        Library::Library(std::vector<Book*> booklist) : books(booklist) {}

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

            // removes the book from the is_borrowed() vector
            for (int j = 0; j < is_borrowed.size(); j++){
                
            }

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

                    // checking if the book is already borrowed
                    for (int j = 0; j < is_borrowed.size(); j++){
                        if (*book == *is_borrowed[j]){
                            std::cout << "That book is already being borrowed";
                        }
                        // insert book into is_borrowed vector
                        else {
                            is_borrowed.push_back(book);
                        }
                    }
                    return true;
                }
            }
            return false;
        };
        

        // MAKE ADVANCED_SEARCH

        // borrowing book function
        void Library::borrow(LibraryUser user, string& title){

        // returning book function
        };

        void Library::print() const{
            for (int i = 0; i < books.size(); i++){
                std::cout << "Book Index: " << i << std::endl;
                books[i]->print();
            }
        };
