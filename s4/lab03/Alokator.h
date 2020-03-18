#pragma once
#include <iostream>
#include "Malenstwo.h"

class Alokator {
public: 
	Alokator(): m_start{nullptr}, m_count{0} {}
	~Alokator() {free(m_start);}

	void* alloc(size_t size, size_t count) {
		if (m_start == nullptr) {
			std::cout << "Pierwszy obiekt na stercie. ";
			std::cout << "Prealokuje skladowisko na 100 elementow." << std::endl;
			m_start = malloc(size/count * 100);
		}
		m_count += count;
		return static_cast<int*>(m_start) + m_count - count;
	}

	void dealloc(void* ptr, size_t count) {
		m_count -= count;
		if (m_count == 0) {
			free(m_start);
			m_start = nullptr;
		}
	}
private:
	void* m_start;
	int m_count;
};
