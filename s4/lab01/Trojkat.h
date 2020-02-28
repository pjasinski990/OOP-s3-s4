#pragma once
#include "Ksztalt.h"
#include <cmath>

class Trojkat: public Ksztalt {
public:
	inline ~Trojkat() {}
	inline Trojkat(double side1, double side2, double side3): m_s1{side1}, m_s2{side2}, m_s3{side3} {}
	inline void wypisz(std::ostream& out) const override {
		out << "Trojkat o bokach " << m_s1 << " " << m_s2 << " " << m_s3 << std::endl;}
	double polePow() const override;
private:
	double m_s1;
	double m_s2;
	double m_s3;
};
