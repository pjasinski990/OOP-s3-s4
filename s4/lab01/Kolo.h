#pragma once
#include "Ksztalt.h"

class Kolo: public Ksztalt {
public:
	inline ~Kolo() {}
	inline Kolo(double radius): m_radius{radius} {}
	inline void wypisz(std::ostream& out) const override {
		out << "Kolo o promieniu " << m_radius << std::endl;}
	inline double polePow() const override {
		return 3.1415*(m_radius*m_radius);}
private:
	double m_radius;
};
