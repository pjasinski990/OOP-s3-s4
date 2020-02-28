#pragma once
#include "Book.h"
#include <iostream>

/*
 * Class of bookshelf for storing fixed number of Book type objects.
 * Uses stack-like array structure for adding new books.
 */
class BooksShelf {
public:
	/*
	 * Constructor for bookshelf. 
	 * Allocates initial_size of Book type objects in _books array.
	 * \param initial_size max number of possibly stored books
	 */
	BooksShelf(int initial_size);
	/*
	 * Destructor, dealocates _books array.
	 */
	~BooksShelf();
	/*
	 * Copy constructor, deep-copies every book.
	 */
	BooksShelf(const BooksShelf& o);

	/*
	 * Adds new book to the top of _books array.
	 * \param b new book object to be added.
	 * \return void
	 */
	void add(Book b);
	/*
	 * Prints every stored book, formats output nicely.
	 * \return void
	 */
	void print() const;
	/* 
	 * Removes book at a given index. Moves all following books
	 * back, in order to maintain consistent stack-type array.
	 * \param index index of removed book.
	 * \return void
	 */
	void remove(int index);

private:
	/* Number of books possible to store. */
	int _size{0};
	/* Top of the "stack" */
	int _top{0};
	/* Maximum length of contained books titles. Used for formatting. */
	unsigned int _max_title_len{0};
	/* Books array */
	Book* _books;
};
