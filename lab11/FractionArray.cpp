#include "FractionArray.h"

std::ostream& operator << (std::ostream& out, const FractionArray& o) {
	out << "[ ";
	for (int i = 0; i < o._size; i++) {
		out << o._data[i] << " ";
	}
	out << "]";
	return out;
}

FractionArray::FractionArray(int size): _data(new Fraction[size]), _size(size) {
	for (int i = 0; i < _size; i++) {
		_data[i] = Fraction();
	}
}

Fraction& FractionArray::operator [] (int i) {
	return _data[i];
}

const Fraction& FractionArray::operator [] (int i) const {
	return _data[i];
}
