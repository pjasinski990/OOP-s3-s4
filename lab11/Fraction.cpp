#include "Fraction.h"

std::ostream& operator << (std::ostream& out, const Fraction& o) {
	out << o._l << "/" << o._m;
	return out;
}

Fraction operator * (int i, const Fraction& o) {
	return Fraction(o._l*i, o._m);
}

void Fraction::simplify() {
	int gcd = Maths::gcd(_l, _m);
	_l /= gcd;
	_m /= gcd;
}

const Fraction Fraction::operator + (const Fraction& o) const {
	if (_m == o._m) {
		return Fraction(_l+o._l, _m);
	} else {
		return Fraction(_l*o._m + o._l*_m, _m*o._m);
	}
}

Fraction Fraction::operator - (const Fraction& o) const {
	if (_m == o._m) {
		return Fraction(_l-o._l, _m);
	} else {
		return Fraction(_l*o._m - o._l*_m, _m*o._m);
	}
}

Fraction Fraction::operator * (const Fraction& o) const {
	return Fraction(_l*o._l, _m*o._m);
}
