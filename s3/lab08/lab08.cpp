// Celem zadania jest przećwiczenie klas, konstruktorów 
 
// Proszę napisać klasę Book zawierającą tytuł książki i
// klasę BookShelf, przechowującą książki.
// - w Book można użyć std::string (zalecane) 
// - półka (BooksShelf) na ustaloną na początku pojemność
// - do półki można dodawać (metoda add) lub odejmować (metoda remove) książki
// - tytuły wypisywane są w sposób wyśrodkowany

// Uwagi:
// - Wysyłanego pliku lab08.cpp proszę nie modyfikować.
// - Proszę kompilwac z przynajmniej z flagą -Wall 
// - Przy wykonaniu zadania nie wolno korzystać z pomocy kolegów, internetu, notatek, ani 
//   innych materiałów (w tym własnych wcześniej przygotowanych plikow oprócz makefile/cmake)
// - Kody źrodłowe muszą znajdować się w katalogu ~/preoop, do którego nikt oprócz
//   właściciela nie ma praw dostępu (prawa 700)
// - zadanie wysylamy na UPEL, w formie archiwum:
//    tar -czvf arch_name.tar.gz dir_name
 

#include <iostream>
#include "BooksShelf.h"
#include "Book.h"

int main() {
  Book b1("Dlugi Tytul");
  Book b2("Znacznie Znacznie Dluzszy Tytul");
  Book b3("Tytul");

  BooksShelf shelf(3);
  shelf.add(b1);
  shelf.add(b2);
  shelf.add(b3);

  shelf.print();
  const BooksShelf backup = shelf;
  shelf.remove(1);

  std::cout << "================== Original shelf: ==================" << std::endl;
  shelf.print();
  std::cout << "====================== Backup: ======================" << std::endl;
  backup.print();
}
/* wyniki

          Dlugi Tytul
Znacznie Znacznie Dluzszy Tytul
             Tytul
================== Original shelf: ==================
Dlugi Tytul
   Tytul
====================== Backup: ======================
          Dlugi Tytul
Znacznie Znacznie Dluzszy Tytul
             Tytul

*/
