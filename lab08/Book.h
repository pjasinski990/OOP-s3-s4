#pragma once
#include <string>

/* 
 * Book class to use with BooksShelf.
 */
class Book {
public:
	/*
	 * Constructor for placeholder book. 
	 * Needed to alocate initial array in BooksShelf.
	 */
	Book();
	/*
	 * Normally used constructor for creating new Books.
	 */
	Book(std::string title);
	/*
	 * Getter for _title.
	 * \return title of the book.
	 */
	std::string get_title () const {return _title;}

private:
	/* Tilte of the book. */
	std::string _title;
};
