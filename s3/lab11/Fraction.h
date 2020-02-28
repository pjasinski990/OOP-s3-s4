#pragma once
#include <iostream>
#include "Maths.h"

class Fraction {
	friend std::ostream& operator << (std::ostream& out, const Fraction& o);
	friend Fraction operator * (int i, const Fraction& o);
public:
	Fraction(int l = 0, int m = 1): _l(l), _m(m) {}
	operator double() const {return static_cast<double>(_l)/static_cast<double>(_m);}
	const Fraction operator + (const Fraction& o) const;
	Fraction operator - (const Fraction& o) const;
	Fraction operator * (const Fraction& o) const;

	void simplify();
private:
	int _l;
	int _m;
};
