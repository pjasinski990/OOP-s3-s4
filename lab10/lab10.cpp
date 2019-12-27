// Celem zadania jest przećwiczenie konwersji jawnych i 
// niejawnych oraz jak im zapobiegać.

// Proszę napisać klasę Vector, reprezentującą wektor n-wymiarowy.
// ma on metody wyliczające:
// - sum: sumę dwóch wektorów (lub wektora i liczby)
// - dot: iloczyn skalarny dwóch wektorów 
//		v * w = v1*w1 + v2*w2 + ... + vn*wn

// - norm: normę wektora
//		|v| = sqrt( v1*v1 + v2*v2 + ... + vn*vn )
// - operator konwersji na double: zwraca normę
// - print do wypisania wektora

// UWAGA
// Proszę unikać kopiowania tego samego kodu
// - Proszę kompilować z flagą -std=c++11

#include <iostream>
#include "Vector.h"

// UWAGA! 
// Odkomentowanie poniższej linii MUSI powodować błąd kompilacji (w przeciwnym razie -1 pkt)
// #define ERROR
// 
// Wymagane utworzenie konstruktora przenoszącego (za brak -1 pkt)

int main() {
	Vector v1(3);		
	const Vector v2(4);	

	v1.at(0) = 4;
	v1.at(1) = 1;
	const Vector v3 = v1;
	v1.at(1) = 2;

	v1.print("v1: ");
	v2.print("v2: ");
	v3.print("v3: ");

	double prod = Vector::dot(v1, v3); 
	std::cout << "Dot product = " << prod << std::endl;

	double norm = static_cast<double>(v3); // == v3.norm();
	std::cout << "Norm = " << norm << ", " << v3.norm() << std::endl;
	
	Vector v4 = Vector::sum(v1, v3); 
	v4.print("v1 + v3: ");

	Vector v5 = std::move(Vector::sum(v1, v3));
	v5.print("v1 + v3: ");

	Vector::sum(v1, 3).print("v1 + 3 : ");
	
	#ifdef ERROR
	Vector strange = 5;
	strange.print();
	#endif
}
/* wyniki

v1: (4, 2, 0)
v2: (0, 0, 0, 0)
v3: (4, 1, 0)
Dot product = 18
Norm = 4.12311, 4.12311
v1 + v3: (8, 3, 0)
v1 + v3: (8, 3, 0)
v1 + 3 : (7, 5, 3)

*/
