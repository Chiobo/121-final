#ifndef LIB_HPP
#define LIB_HPP  

#include "book.hpp"
#include <vector>
#include <string>

class Library {
    private:
        std::vector<Book*> books; 
        std::vector<bool> is_borrowed;

    public:
        Library();
        Library(std::vector<Book*> booklist);
        
        bool insert(Book* book);

        bool remove(Book* book);

        void borrow(LibraryUser user, string& title);
        
        void print() const{};                          
};

#endif