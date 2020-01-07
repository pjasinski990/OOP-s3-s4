#pragma once
#include "Fraction.h"
#include <iostream>

class FractionArray {
	friend std::ostream& operator << (std::ostream& out, const FractionArray& o);
public:
	FractionArray(int size);
	~FractionArray() {delete[] _data;}

	Fraction& operator [] (int i);
	const Fraction& operator [] (int i) const;

private:
	Fraction* _data;
	int _size;
};
