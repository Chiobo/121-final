#include <iostream>
#include "book.hpp"
#include "lib.hpp"
#include "LibraryUser.hpp"
#include <vector>

Library::Library() : books(), is_borrowed() {}

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
	// is_borrowed[books.size() - 1] = false;
	// is_borrowed.reserve(books.size());

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
	return remove(&constructed);
};

// borrowing book function
void Library::borrow_book(LibraryUser user, string &title)
{

	// Book* found_book = nullptr;
	int found_idx = -1;

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i]->get_title() == title)
		{
			found_idx = i;
			break;
		}
	}

	if (found_idx == -1)
	{
		std::cout << "Book not found" << std::endl;
		return;
	}

	if (is_borrowed[found_idx] == true)
	{
		std::cout << "Book is already borrowed" << std::endl;
		return;
	}

	if (user.get_borrowed_count() >= user.get_borrow_limit())
	{
		std::cout << "User has reached borrow limit" << std::endl;
		return;
	}

	if (user.check_genre(books[found_idx]->get_genre()) == false)
	{
		std::cout << "User cannot borrow genre: " << books[found_idx]->get_genre() << std::endl;
		return;
	}

	is_borrowed[found_idx] = true;
	user.borrow_book();
	cout << "Book borrowed by" << user.get_name() << " - " << books[found_idx]->get_title() << endl;
};

// borrowing book function
void Library::return_book(LibraryUser user, string &title)
{

	// Book* found_book = nullptr;
	int found_idx = -1;

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i]->get_title() == title)
		{
			found_idx = i;
			break;
		}
	}

	if (found_idx == -1)
	{
		std::cout << "Book not found" << std::endl;
		return;
	}

	if (is_borrowed[found_idx] == false)
	{
		std::cout << "Book is not borrowed" << std::endl;
		return;
	}

	if (user.get_borrowed_count() == 0)
	{
		std::cout << "User has not borrowed any books" << std::endl;
		return;
	}

	is_borrowed[found_idx] = false;
	user.return_book();
	cout << "Book returned by" << user.get_name() << " - " << books[found_idx]->get_title() << endl;
};

void Library::print() const
{
	for (int i = 0; i < books.size(); i++)
	{
		std::cout << "Book Index: " << i << std::endl;
		books[i]->print();
	}
};

// Define utility function
std::string to_lower(const std::string &str)
{
	// Copy string
	std::string lower_str = str;
	std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
	return lower_str;
}

Book *Library::advanced_search(const string &title, const string &author, const string &genre)
{
	if (title != "")
	{
		// Find title
		for (int i = 0; i < books.size(); i++)
		{
			std::string lower_book_title = to_lower(books[i]->get_title());
			std::string lower_title = to_lower(title);

			if (lower_book_title.find(lower_title) != std::string::npos)
			{
				return books[i];
			}
		}
	}

	if (author != "")
	{

		// find author
		for (int i = 0; i < books.size(); i++)
		{
			std::string lower_book_author = to_lower(books[i]->get_author());
			std::string lower_author = to_lower(author);

			if (lower_book_author.find(lower_author) != std::string::npos)
			{
				return books[i];
			}
		}
	}

	if (genre != "")
	{

		// Find genre
		for (int i = 0; i < books.size(); i++)
		{
			std::string lower_book_genre = to_lower(books[i]->get_genre());
			std::string lower_genre = to_lower(genre);

			if (lower_book_genre.find(lower_genre) != std::string::npos)
			{
				return books[i];
			}
		}
	}
	// if nothing, return nullptr
	return nullptr;
}

Book *Library::advanced_search(const string &title, const string &author)
{
	return advanced_search(title, author, "");
}

Book *Library::advanced_search(const string &title)
{
	return advanced_search(title, "", "");
}
