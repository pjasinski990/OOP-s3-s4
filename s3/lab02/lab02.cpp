/*
 Tematem zadania jest algorytm weryfikacji numeru karty kredytowej.
 Prawidłowy numer karty może mieć różną liczbę cyfr, np. 
 VISA 13 lub 16
 Master Card 16
 American Express 15

 Weryfikację numeru karty można przeprowadzić algorytmem Luhna:

 jeśli numer karty jest krótszy od 16 cyfr to przed numerem dopisujemy zera,
 kolejne cyfry numeru mnożymy przez współczynniki wagowe,
 kolejno 2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
 sumujemy wszystkie CYFRY otrzymanego wyniku,
 numer karty jest prawidłowy jeśli ostatnia cyfra wyniku sumowania jest równa 0. 

 Przykład:
  2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1   -> wagi
* 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 2   -> nr karty 
---------------------------------
2*1 1*2 2*3 1*4 2*5 1*6 2*7 1*8 2*9 1*0 2*1 1*2 2*3 1*4 2*5 1*2  
 2   2   6   4  10   6  14   8  18   0   2   2   6   4  10   2 
 2 + 2 + 6 + 4+1+0 + 6+1+4 + 8+1+8 + 0 + 2 + 2 + 6 + 4+1+0 + 2=60
                     
           60 mod 10 = 0 ----> cyfra kontrolna prawidłowa


 Proszę napisac dwie funkcje: 
 - do obliczania cyfry kontrolnej (find_ctrl) 
 - sprawdzającą poprawność numeru (number_correct).
 

 Uwagi:
 - Pliku lab02.cpp nie wolno modyfikować.
 - Przy wykonaniu zadania nie wolno korzystać z pomocy kolegów, internetu, notatek, ani 
   innych materiałów (w tym własnych wcześniej przygotowanych plikow oprócz makefile)
 - Kody źrodłowe muszą znajdować się w katalogu, do którego nikt oprócz
   właściciela nie ma praw dostępu (prawa 700)
 - zadanie wysylamy na UPEL, w formie archiwum:
    tar -czvf arch_name.tar.gz dir_name

 */

#include <iostream>
#include "check_number.h"
#include "check_number.h"

int main() {
  const char* visa = "4222222222222";
  char ctrl = find_ctrl(visa);

  std::cout << visa << "\t" << ctrl << std::endl;

  visa = "4111111111111111";
  ctrl = find_ctrl(visa);
  std::cout << visa << "\t" << ctrl << std::endl;

  /// weryfikacja 
  visa = "4012888888881881"; 
  if ( number_correct(visa) ) {
    std::cout << "numer " << visa << " jest poprawny " << std::endl; 
  }

  visa = "4222222723122"; 
  if (not number_correct(visa) ) {
    std::cout << "numer " << visa << " nie jest poprawny " << std::endl; 
  }
  return 0;
}
/* wynik

4222222222222	0
4111111111111111	0
numer 4012888888881881 jest poprawny 
numer 4222222723122 nie jest poprawny 

 */
