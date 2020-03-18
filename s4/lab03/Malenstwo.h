#pragma once
#include "Alokator.h"
#include <iostream>
#include <string>
#include <cstring>

class Malenstwo {
public:
	Malenstwo(): m_data{0} {}
	Malenstwo(int data): m_data{data} {
		std::cout << "Konstrukcja Malenstwa: wart = " << m_data << std::endl;
	}

	void* operator new(size_t size) {
		std::cout << "Alokuje jeden obiekt: " << memInfo(size) << std::endl;
		return m_alokator.alloc(size, size/sizeof(Malenstwo));
	}
	void* operator new[](size_t size) {
		std::cout << "Alokuje tablice [] o rozmiarze: " << memInfo(size) << std::endl;
		return m_alokator.alloc(size, size/sizeof(Malenstwo));
	}
	void operator delete(void* ptr, size_t size) {
		std::cout << "Zwalniam jeden obiekt: " << memInfo(size) << std::endl;
		m_alokator.dealloc(ptr, size/sizeof(Malenstwo));
	}
	void operator delete[](void* ptr, size_t size) {
		std::cout << "Zwalniam tablice [] o rozmiarze " << memInfo(size) << std::endl;
		m_alokator.dealloc(ptr, size/sizeof(Malenstwo));
	}

	int& wartosc() {return m_data;}
private:
	static std::string memInfo(size_t size) { return std::to_string(size/sizeof(Malenstwo)) 
		+ " (" + std::to_string(size) + " bajtow)";}
	int m_data;
	static Alokator m_alokator;
};

Alokator Malenstwo::m_alokator;

class MalenstwoSamoSprzatacz {
public:
	MalenstwoSamoSprzatacz(Malenstwo* ptr): m_ptr{ptr} {}
	~MalenstwoSamoSprzatacz() {delete m_ptr;}
	Malenstwo* operator->() {return m_ptr;}
private:
	Malenstwo* m_ptr;
};
