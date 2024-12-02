#include <iostream>
#include "LibraryUser.hpp" // class declaration
#include <string>

// Parent Class LibraryUser 

    // defining constructors
    LibraryUser::LibraryUser() : name(), user_id(), borrowed_count(0) {} // default constructor
    LibraryUser::LibraryUser(const std::string& name, const std::string& user_id): name(name), user_id(user_id) {}


    // getter functions for private class variables
    std::string LibraryUser::get_name(){
        return name;
    };

    std::string LibraryUser::User_ID(){
        return user_id;
    };

    int LibraryUser::get_borrowed_count(){
        return borrowed_count;
    };

    // functions
    void LibraryUser::borrow_book(){
        borrowed_count++;
    };

    void LibraryUser::return_book(){
        borrowed_count--;
    };

    void LibraryUser::print_user(){
        std::cout << "Username: " << name << "User_ID: " << user_id << "Borrowed Count: " << borrowed_count << std::endl;
    };

// Teacher Class

    // defining constructors
    Teacher::Teacher() : borrow_limit() {}
    Teacher::Teacher(const int borrow_limit) : borrow_limit(borrow_limit) {}

    // defining getter function
    int Teacher::get_borrow_limit(){
        return borrow_limit;
    };

    void Teacher::add_book_to_library(Library books_list, Book* book){
        books_list.push_back(*book);
    };

    // defining print

    void Teacher::print(){
        LibraryUser::print_user();
        std::cout << "Borrow Limit: " << borrow_limit << std::endl;
    };


