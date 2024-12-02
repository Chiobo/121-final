#include <iostream>
#include "book.hpp"
#include "lib.hpp"
#include <string>
#include <vector>

using namespace std;

int main()
{
	// Book Class Calls
	Book book1("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "1997", "Fantasy");
	Library lib1;
	lib1.insert(book1);
	// lib1.remove(book1);
	lib1.print();

	// lib1.insert("Harry Potter and the Chamber of Secrets", "J.K. Rowling", "1998", "Fantasy2");

	// lib1.print();

	// Book *searched = lib1.advanced_search("", "", "Fantasy2");
	// searched->print();

	// lib1.advanced_search("", "", "Fantasy")->print();
	return 0;
}