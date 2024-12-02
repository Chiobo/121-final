#ifndef LIBRARYUSER
#define LIBRARYUSER

#include <string>

class LibraryUser {
    private:
        std::string name;
        std::string user_id;
        int borrowed_count = 0;

    public:
        // constructors

        LibraryUser(); // default constructor
        LibraryUser(const std::string& name, const std::string& user_id);
        
        
        // getter functions for private class variables
        std::string get_name();

        std::string User_ID();

        int get_borrowed_count();

        // class functions
        void borrow_book();

        void return_book();

        void print_user();




};

class Teacher: public LibraryUser {
    private:
        int borrow_limit;

    public:
        Teacher();
        Teacher(const int borrow_limit);

        int get_borrow_limit();
        void add_book_to_library(Library book_list, Book* book);
        
        void print();
};


class Student: public LibraryUser {
    private:
        bool graduated;
        int borrow_limit;

    public:
        Student();
        Student(const bool graduated, const int borrow_limit);

        int get_borrow_limit();
        void print();        

};
#endif
