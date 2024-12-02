#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
    std::string title;
    std::string authors;
    std::string date_of_publication;
    std::string genre;

    public:
        // constructors
        Book();
        Book(const std::string& ntitle, const std::string& nauthors, const std::string& ndate_of_publication);
        Book(const std::string& ntitle, const std::string& nauthors);
        Book(const std::string& ntitle);

        // duplicate check function
        bool duplicateCheck(const Book new_book);
        bool duplicatecheck(const std::string ntitle, std::string nauthors, std::string ndate_of_publication);

        // getting functions
        string get_title();
        string get_author();
        string get_genre();
        string get_year_published();

        // equality operator overloading
        bool operator==(const Book& other) const{};



        // print function
        void print() const;
};

#endif