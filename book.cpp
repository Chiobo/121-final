#include <iostream>
#include <string>
#include "book.hpp"
using namespace std;


        // class constructors
        Book::Book(){
            title = "n/a";
            authors = "n/a";
            date_of_publication = "n/a";
        }

        Book::Book(const string& ntitle, const string& nauthors, const string& ndate_of_publication) {
            title = ntitle;
            authors = nauthors;
            date_of_publication = ndate_of_publication;
        }
        
        Book::Book(const string& ntitle, const string& nauthors) {
            title = ntitle;
            authors = nauthors;
            date_of_publication = "n/a";
        }
        
        Book::Book(const string& ntitle) {
            title = ntitle;
            authors = "n/a";
            date_of_publication = "n/a";
        }


        // getter functions
        string Book::get_title() {
            return title;
        }

        string Book::get_author(){
            return authors;
        }

        string Book::get_genre(){
            return genre;
        }

        string Book::get_year_published(){
            return date_of_publication;
        }

        // overloaded boolean operator==
        bool Book::operator==(const Book& other) const {
            return (title == other.title && 
            authors == other.authors && 
            date_of_publication == other.date_of_publication && 
            genre == other.genre);
        }

        // print function
        void Book::print() const{ 
            cout << "Title: " << title << ", Authors: " << authors << ", Genre: "<< genre<< ", Year: " << date_of_publication << endl;
        }

