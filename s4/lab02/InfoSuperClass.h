#pragma once
#include "InfoClass.h"

class InfoSuperClass: public InfoClass {
public:
	~InfoSuperClass() override {}
	virtual std::string info() const {
		return "info = " + m_info + ", num = " + std::to_string(m_num);
	};
	InfoSuperClass(std::string info, int num): InfoClass(info) {
		m_num = num;
	}
private:
	int m_num;
};
