#pragma once
#include "Ksztalt.h"

class Kwadrat: public Ksztalt {
public:
	inline ~Kwadrat() {}
	inline Kwadrat(double side): m_side{side} {}
	inline void wypisz(std::ostream& out) const override {
		out << "Kwadrat o boku " << m_side << std::endl;}
	inline double polePow() const override {
		return m_side*m_side;}
private:
	double m_side;
};
