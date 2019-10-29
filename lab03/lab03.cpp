/*

 Prosze napisać funkcje wykonujące operacje na tablicach
 reprezentujących listę studentów.

 W tablicy "namesList" przechowywane są imię i nazwisko
 studenta oddzielone jedną spacją.

 W tablicy "yearsList" przechowywane są lata, na których studiuje
 student.

 UWAGA
 - Jeśli dodanie studenta spowodowałoby przekroczenie pojemności 
 tablicy (zmienna capacity), tablice powinny zostać odpowiednio 
 powiększone.
 - Tablica namesList powinna mieć rozmiar zaalokowany odpowiednio do długości 
  imienia i nazwiska.
 - Proszę zadbać o dobre zarządzanie pamięcią.

 Uwagi:
 - Pliku lab03.cpp nie wolno modyfikować.
 - Przy wykonaniu zadania nie wolno korzystać z pomocy kolegów, internetu, notatek, ani 
   innych materiałów (w tym własnych wcześniej przygotowanych plikow oprócz makefile)
 - Kody źrodłowe muszą znajdować się w katalogu ~/preoop, do którego nikt oprócz
   właściciela nie ma praw dostępu (prawa 700)
 - zadanie wysylamy na UPEL, w formie archiwum:
    tar -czvf arch_name.tar.gz dir_name

 */

#include <iostream>
#include "StudentList.h"

int main (){
  int numberOfStudents = 0;
  char** namesList = NULL;
  int* yearsList = NULL;
  int capacity = 2;

  prepareList(&namesList, &yearsList, capacity);

  addStudent(&numberOfStudents, &capacity, &namesList, &yearsList, "Chuck", "Norris", 7);
  addStudent(&numberOfStudents, &capacity, &namesList, &yearsList, "John", "Rambo", 3);
  addStudent(&numberOfStudents, &capacity, &namesList, &yearsList, "Johny", "Bravo", 1);

  std::cout << "Only names:" << std::endl;
  printListContent (numberOfStudents, namesList);

  std::cout << "Everything full:" << std::endl;
  printAllListContent (numberOfStudents, namesList, yearsList);
    
  clearStudents (&capacity, &numberOfStudents, &namesList, &yearsList);
  
  std::cout << "capacity = " << capacity << ", numberOfStudents = " << numberOfStudents << std::endl;
  
  return 0;
}
/* wynik

Only names:
Chuck Norris
John Rambo
Johny Bravo

Everything full:
Chuck Norris - 7
John Rambo - 3
Johny Bravo - 1

capacity = 0, numberOfStudents = 0

 */
