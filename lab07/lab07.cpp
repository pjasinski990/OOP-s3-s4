// Zadanie wykonane w zespole:
// 1) Marta Grzesiak
// 2) Emilia Rutkowska
// 3) Piotr Jasinski

// Celem zadania jest  przećwiczenie klas, używania referencji i wskaźników oraz static.
 
// Proszę napisać klasę MyString będącą opakowaniem na łańcuch znaków i 
// umożliwiającą jego modyfikacje:
// - append - dopisuje tekst na koniec 
// - replace - podmienia tekst na inny 
// - swap - zamienia dwa teksty
// - "głośny" desktruktor
// i inne wynikające z treści.

// UWAGA: W zadaniu nie można użyć klasy std::string. Tj. musi być to zrobione na char*.
// UWAGA: W klasie MyString moze miec wiecej metod niz te, ktore sa widoczne w main.
// Proszę zadbać o dobre zarządzanie pamięcią.

#include <iostream>
#include "MyString.h"
#include "MyString.h"

int main() {
  
  MyString s1("to kanapa pana");
  std::cout << s1.str() << std::endl;
  
  MyString s2("kota");
  s1.append(s2); // uwaga, zmieniamy wnetrze s1
  std::cout << s1.str() << std::endl;

  const MyString s3("Filemona");
  
  s2.replace(s3);
 
  std::cout << "przed zamiana: " << s1.str()  << " " << s2.str() << std::endl;
  MyString::swap(s1, s2);
  std::cout << "po zamianie: " << s1.str()  << " " << s2.str() << std::endl;

}
/* wyniki

to kanapa pana
to kanapa panakota
przed zamiana: to kanapa panakota Filemona
po zamianie: Filemona to kanapa panakota
- deleting Filemona
- deleting to kanapa panakota
- deleting Filemona

*/
