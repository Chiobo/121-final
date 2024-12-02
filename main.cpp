#include <iostream>
#include "book.hpp"
#include "lib.hpp"
#include <string>
#include <vector>


using namespace std;


int main(){
    // Book Class Calls
    Book bookDefaultConstructor; // testing default
    Book bookThreeParameters("World Of Three Zeroes", "Muhammad Yunus", "1992"); // testing 3 parameters
    Book bookTwoParameters("Homo Sapiens", "Yuval Harrari"); // testing 2 parameters
    Book bookOneParameter("Why We Sleep"); // testing 1 parameter

    // Test Book
    Book test("Harambe");

    bookOneParameter.print(); // testing print funciton

    // Library Class Calls
    Library lib; //default constructor 

    vector<Book> constructortest;
    constructortest.push_back(bookTwoParameters);
    Library lib1(constructortest); // vector attribute constructor 

    lib.insert(bookTwoParameters); // checking for duplicate book
    lib.insert(bookThreeParameters); // sucessfully inserting new book
    lib.insert("World Of Three Zeroes", "Muhammad Yunus", "1992"); // checking for duplicate book 
    lib.insert("Why We Sleep", "Matthew Walker", "2016"); // successfully inserting new book

    
    lib.remove(bookTwoParameters); // testing successful removal
    lib.remove(test); // testing error non-existent library book removal
    lib.remove(bookThreeParameters); // testing successful removal
    lib.remove("Frozen 2", "Disney", "2022"); // testing non-existent library book removal






    return 0;
}