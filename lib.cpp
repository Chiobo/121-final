#include <iostream>
#include <sstream>
#include "book.hpp"
#include "lib.hpp"
#include "LibraryUser.hpp"
#include <vector>
#include "util.hpp"

Library::Library() : is_borrowed(), books() {}

Library::Library(std::vector<Book *> booklist) : books(booklist)
{
	is_borrowed.resize(books.size(), false); // setting all boolean values in is_borrowed vector to false
}

// book insert functions
bool Library::insert(Book *book)
{

	// check: existing book with same details
	for (int i = 0; i < books.size(); i++)
	{
		if (*book == *books[i])
		{
			return false;
		}
	}

	// inserts book into library
	books.push_back(book);
	is_borrowed.push_back(false);

	return true;
}

bool Library::insert(Book book)
{
	Book *new_book = new Book(book.get_title(), book.get_author(), book.get_year_published(), book.get_genre());
	return insert(new_book);
}

bool Library::insert(const string title, const string author, const string year_published, const string genre)
{
	Book *new_book = new Book(title, author, year_published, genre);
	return insert(new_book);
};

// book remove function
bool Library::remove(Book *book)
{
	// check: existing book with same details
	for (int i = 0; i < books.size(); i++)
	{

		// searches for book in library
		if (*book == *books[i])
		{
			// removes book from library
			books.erase(books.begin() + i);
			is_borrowed.erase(is_borrowed.begin() + i);

			return true;
		}
	}
	return false;
}
bool Library::remove(Book book)
{
	return remove(&book);
}
bool Library::remove(string title, string author, string year_published, string genre)
{
	Book constructed = Book(title, author, year_published, genre);
	// Doesn't matter that we're constructing a new book here; we're only using it to compare with the existing books
	return remove(&constructed);
};

/*

IMPORTANT NOTE FOR TA:
- The borrow_book function is impossible to implement exactly according to the assignment's spec; it must take in a reference to a LibraryUser (as does the return function)
- The LibraryUser class doesn't have valid_genres or borrow_limit, but Student & Teacher do; for the overridden virtual functions to take precedence, the objects must be passed by reference.
- Both borrow_book and return_book also mutate the LibraryUser's borrowed_count, which necessitates passing by reference.

*/
void Library::borrow_book(LibraryUser *user, const string &title)
{

	// Finding based on title
	int found_idx = find_title(title);

	if (found_idx == -1)
	{
		std::cout << "⚠️ Book not found" << std::endl;
		return;
	}

	if (is_borrowed[found_idx] == true)
	{
		std::cout << "❌ Book is already borrowed" << std::endl;
		return;
	}

	if (user->get_borrowed_count() >= user->get_borrow_limit())
	{
		std::cout << "❌ User has reached borrow limit" << std::endl;
		return;
	}

	if (user->check_genre(books[found_idx]->get_genre()) == false)
	{
		std::cout << "❌ User cannot borrow genre: " << books[found_idx]->get_genre() << std::endl;
		return;
	}

	is_borrowed[found_idx] = true;
	user->borrow_book();
	std::cout << "✅ Book borrowed by" << user->get_name() << " - " << books[found_idx]->get_title() << endl;
}
void Library::borrow_book(Student user, const string &title)
{
	borrow_book(&user, title);
}
void Library::borrow_book(Teacher user, const string &title)
{
	borrow_book(&user, title);
};

// see above note
void Library::return_book(LibraryUser *user, const string &title)
{
	int found_idx = find_title(title);

	if (found_idx == -1)
	{
		std::cout << "❌ Book not found" << std::endl;
		return;
	}

	if (is_borrowed[found_idx] == false)
	{
		std::cout << "❌ Book is not borrowed" << std::endl;
		return;
	}

	if (user->get_borrowed_count() == 0)
	{
		std::cout << "❌ User has not borrowed any books" << std::endl;
		return;
	}

	is_borrowed[found_idx] = false;
	user->return_book();
	cout << "✅ Book returned by " << user->get_name() << " - " << books[found_idx]->get_title() << endl;
};

// We extract a generic log_books function to avoid code duplication; used in the Library::print function as well as the searching func
void log_books(std::vector<Book *> books)
{
	for (int i = 0; i < books.size(); i++)
	{
		std::cout << "ℹ️ Book Index: " << i << std::endl;

		std::cout << indent_output("\t", [&]()
								   { books[i]->print(); });
	}
}

void Library::print() const
{
	log_books(books);
}

int Library::find_title(const string &title)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i]->get_title() == title)
		{
			return i;
		}
	}
	return -1;
};

void print_search_results(const std::vector<Book *> &books, size_t offset, const std::string &criteria_type, const std::string &search_term)
{

	auto results = std::vector<Book *>(books.begin() + offset, books.end());
	if (books.size() != offset)
	{

		cout << "🔍 " << results.size() << " Books found with " << criteria_type << ": \"" << search_term << "\"" << endl;
		cout << indent_output("\t", [&]()
							  { log_books(results); });
	}
	else
	{

		cout << "🔍 " << results.size() << " Books found with " << criteria_type << ": \"" << search_term << "\"" << endl;
	}
}

std::vector<Book *> search_by_criteria(const std::vector<Book *> &books, const std::string &search_term,
									   const std::function<std::string(Book *)> &get_field)
{
	std::vector<Book *> results;
	if (search_term.empty())
		return results;

	for (auto &book : books)
	{
		std::string lower_book_field = to_lower(get_field(book));
		std::string lower_search_term = to_lower(search_term);
		if (lower_book_field.find(lower_search_term) != std::string::npos)
		{
			results.push_back(book);
		}
	}
	return results;
}

void Library::advanced_search(const string &title, const string &author, const string &genre)
{
	std::vector<Book *> found_books;
	size_t offset = 0;

	if (title.empty() && author.empty() && genre.empty())
	{
		cout << "🔍 No search criteria provided" << endl;
		return;
	}

	// Search by title
	if (!title.empty())
	{
		auto title_results = search_by_criteria(books, title, [](Book *b)
												{ return b->get_title(); });
		found_books.insert(found_books.end(), title_results.begin(), title_results.end());
		print_search_results(found_books, offset, "title", title);
		offset = found_books.size();
	}

	// Search by author
	if (!author.empty())
	{
		auto author_results = search_by_criteria(books, author, [](Book *b)
												 { return b->get_author(); });
		found_books.insert(found_books.end(), author_results.begin(), author_results.end());
		print_search_results(found_books, offset, "author", author);
		offset = found_books.size();
	}

	// Search by genre
	if (!genre.empty())
	{
		auto genre_results = search_by_criteria(books, genre, [](Book *b)
												{ return b->get_genre(); });
		found_books.insert(found_books.end(), genre_results.begin(), genre_results.end());
		print_search_results(found_books, offset, "genre", genre);
		offset = found_books.size();
	}

	if (found_books.empty())
	{
		cout << "⚠️ No books found" << endl;
	}
}

void Library::advanced_search(const string &title, const string &author)
{
	return advanced_search(title, author, "");
}

void Library::advanced_search(const string &title)
{
	return advanced_search(title, "", "");
}
