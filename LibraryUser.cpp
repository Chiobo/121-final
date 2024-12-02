#include <iostream>
#include "LibraryUser.hpp" // class declaration


// Parent Class LibraryUser 
    LibraryUser(); // default constructor
    LibraryUser(const string& name, const string& user_id);
    
    
    // getter functions for private class variables
    std::string get_name();

    std::string User_ID();

    int LibraryUser::get_borrowed_count();

    // class functions
    void LibraryUser::borrow_book();

    void LibraryUser::return_book();

    void LibraryUser::print_user();




