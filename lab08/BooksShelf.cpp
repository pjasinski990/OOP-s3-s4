#include "BooksShelf.h"

BooksShelf::BooksShelf(int initial_size) : _size(initial_size) {
	_books = new Book[initial_size];
}

BooksShelf::~BooksShelf() {
	delete[] _books;
}

BooksShelf::BooksShelf(const BooksShelf& o) {
	_size = o._size;
	_top = o._top;
	_max_title_len = o._max_title_len;
	_books = new Book[_size];

	for (int i = 0; i < _size; i++) {
		_books[i] = o._books[i];
	}
}

void BooksShelf::add(Book b) {
	if (_top < _size) {
		_books[_top] = b;
		if (b.get_title().length() > _max_title_len) {
			_max_title_len = b.get_title().length();
		}
		_top++;
	}
	else {
		std::cout << "Bookshelf is full." << b.get_title() << std::endl;
	}
}

void BooksShelf::remove(int index) {
	if (index >= _top || index < 0) {
		std::cout << "There is no book at specified index. Returning." << std::endl;
		return;
	}
	// Moving all following items to maintain array with no holes
	for (int i = index; i < _size-1; i++) {
		_books[i] = _books[i+1];
	}
	// Finding new max title length
	unsigned int new_max_title = 0;
	for (int i = 0; i < _top; i++) {
		if (_books[i].get_title().length() > new_max_title) {
			new_max_title = _books[i].get_title().length();
		}
	}
	_max_title_len = new_max_title;
	_top--;
}

void BooksShelf::print() const {
	for (int i = 0; i < _top; i++) {
		int spacing = _max_title_len - _books[i].get_title().length();
		for (int i = 0; i < spacing/2; i++) {
			std::cout << " ";
		}
		std::cout << _books[i].get_title() << std::endl;
	}
}
