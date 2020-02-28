#pragma once
#include <iostream>

class Ksztalt {
public:
	inline virtual ~Ksztalt() {}
	inline static void wypisz(const Ksztalt& o) {
		o.wypisz(std::cout); }
	inline virtual void wypisz(std::ostream& out) const {}
	inline virtual double polePow() const {return 0;}
};
