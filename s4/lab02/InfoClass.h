#pragma once
#include <iostream>
#include <string>

class InfoClass {
public:
	InfoClass(std::string info): m_counter{0}, m_info{info} {
		std::cout << "++ Tworze obiekt InfoClass: " << this->info() << std::endl;
	}
	virtual ~InfoClass() {
		std::cout << "++ Usuwam obiekt InfoClass: " << this->info() << std::endl;
	}
	virtual std::string info() const {
		return "info = " + m_info;
	};
	std::string info(const std::string& s) {
		m_info = s;
		return "info = " + m_info;
	};

	int* getCounter() {return &m_counter;}
protected:
	int m_counter;
	std::string m_info;
};
