#include "MyString.h"

MyString::MyString(const char* string) {
	_string = new char[strlen(string) + 1];
	strcpy(_string, string);
}

MyString::~MyString() {
	std::cout << " - deleting " << _string << std::endl;
	delete[] _string;
}

void MyString::swap(MyString& s1, MyString& s2) {
	char* temp = s1.str(); 
	s1.set(s2.str());
	s2.set(temp);
}

void MyString::append(const MyString& string2) {
	int size = strlen(_string) + strlen(string2.str()) + 1;

	char* temp = new char[size];
	strcpy(temp, _string);
	strcpy(temp+strlen(_string), string2.str());

	delete[] _string;
	_string = temp;
}

void MyString::replace(const MyString& string2) {
	delete[] _string;
	_string = new char[strlen(string2.str()) + 1];
	strcpy(_string, string2.str());
}
