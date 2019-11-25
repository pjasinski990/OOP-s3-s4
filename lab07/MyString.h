#pragma once
#include <cstring>
#include <iostream>

/*
 * Class allowing modification (appending, replacing and swapping) 
 * of character arrays.
 */
class MyString {
public:
	/*
	 * Constructor for class. 
	 * \param string String to be allocated at character array.
	 */
	MyString(const char* string);
	/*
	 * "Loud" destructor. (we totally know what were doing)
	 */
	~MyString();
	
	/*
	 * Static method for swapping two character arrays in separate instances of MyString.
	 * \param s1 First string
	 * \param s2 Second string
	 * \return void
	 */
	static void swap(MyString& s1, MyString& s2);

	/*
	 * Getter for _string
	 */
	char* str() const {return _string;}

	/*
	 * Setter for _string
	 */
	void set(char* newString) {_string = newString;};

	/*
	 * Method for appending character array from another MyString object
	 * to the one we're calling on.
	 * \param string2 object to be appended
	 * \return void
	 */
	void append(const MyString& string2);
	/*
	 * Method for replacing character array from another MyString object
	 * to the one we're calling on.
	 * \param string2 object we're swapping strings with
	 * \return void
	 */
	void replace(const MyString& string2);

private:
	/* Our little secret...
	 * Highlight of the program.
	 */
	char* _string;
};
