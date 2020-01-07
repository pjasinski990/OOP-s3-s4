// Zadanie zawiera oprócz pliku lab11.cpp także gotową
// klasę Maths zawierającą przydatne narzędzie do wyliczania
// największego wspólnego dzielnika.
//
// Prosze napisac klasę Fraction reprezentujacą ułamek
// i klasę FractionArray - reprezentującą tablicę ułamków.
// 
// Oprócz tego proszę zaimplementować operatory dodawania +, 
// odejmowania -, mnożenia * i wypisania (ostream& <<),
// konwersję Fraction do double i operator[] dla klasy FractionArray.
// 
// W wybranych miejscach po odkomentowaniu program nie powinien się kompilować.
//
// Pliku Main.cpp nie modyfikujemy (poza odkomentowaniem "błędnych" linii).
// Program proszę kompilować przynajmniej z flaga -Wall.


#include "Fraction.h"
#include "FractionArray.h"
#include <iostream>

int main ()
{
  Fraction f1(6,8);
  const Fraction f2(1,2);

  std::cout << f1 << std::endl; 
  std::cout << f2 << std::endl; 

  double val = f2;
  std::cout << "Ułamek dziesiętny f1: " << val << std::endl; 

  f1.simplify(); 
  std::cout << "Po skroceniu:" << std::endl; 
  std::cout << f1 << std::endl; 
  
  std::cout << "Prosta matematyka:" << std::endl; 
  Fraction f3 = f1*f2;
  std::cout << "Iloczyn: " << f3 << std::endl; 
  std::cout << "Suma: " << f1+f2 << std::endl; 
  std::cout << "Suma: " << f2+f1 << std::endl; 
  std::cout << "Znow iloczyn: " << 3*f2 << std::endl; 

  f1 = f2; 		 // OK
  //f1+f2 = f3; // ma się nie kompilować po odkomentowaniu

  FractionArray tab(2);
  tab[0] = f1; //OK
  tab[1] = f3; //OK
  f1 = tab[0]; //OK

  std::cout << tab << std::endl;

  const FractionArray tab_const(2);
  f1 = tab_const[1]; // OK
  // tab_const[0] = f1; // ma się nie kompilować,
  // ponieważ chcemy zapobiec modyfikowaniu obiektów const


}
/* Oto wynik dzialania programu:
6/8
1/2
Ułamek dziesiętny f1: 0.5
Po skroceniu:
3/4
Prosta matematyka:
Iloczyn: 3/8
Suma: 10/8
Suma: 10/8
Znow iloczyn: 3/2
[ 1/2 3/8 ]

*/
