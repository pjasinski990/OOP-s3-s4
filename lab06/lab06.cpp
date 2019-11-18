// Celem zadania jest zapoznanie się z klasami, referencjami i kwalifikatorem const.

/// Proszę napisać klasę Coordinates opisującą współrzędne punktu na mapie 
// i klasę Distance opisującą odległość na mapie.

//  UWAGI:
// - Mozna uzyc klasy string jak ktos umie. 
// - Wszystkie deklaracje mozna umiescic w jednym naglowku Coordinates.h
// - W treści umieszczone są odpowiadające linijki wyniku

// Uwagi:
// - Pliku lab06.cpp proszę nie modyfikować (z wyjątkiem ewentualnie zagadki).
// - Proszę kompilwac z przynajmniej z flagą -Wall 
// - Przy wykonaniu zadania nie wolno korzystać z pomocy kolegów, internetu, notatek, ani 
//   innych materiałów (w tym własnych wcześniej przygotowanych plikow oprócz makefile)
// - Kody źrodłowe muszą znajdować się w katalogu ~/preoop, do którego nikt oprócz
//   właściciela nie ma praw dostępu (prawa 700)
// - zadanie wysylamy na UPEL, w formie archiwum:
//    tar -czvf arch_name.tar.gz dir_name
 

#include <iostream>
#include "Coordinates.h"
#include "Coordinates.h"

int main() {
  Coordinates nyc("NYC", 40.7127, -74.0059 );
  nyc.print();   // NYC: 40.7127N 74.0059W

  Coordinates lisboa("Lisboa", 38.736946, -9.142685 );
  Coordinates nearLisboa("Near Lisboa", 41.162142, -9.142685 );
  nearLisboa.move(0.1, -0.1);
  nearLisboa.print();   // Near Lisboa: 41.2621N 9.24268W

  const Coordinates& portugalCapital = lisboa;
  portugalCapital.print();  // Lisboa: 38.7369N 9.14269W
  
  const double latKRK = 50.061389;
  const double lonKRK = 19.938333;
  const Coordinates krk("Krakow", latKRK,  lonKRK);
  krk.print();  // Krakow: 50.0614N 19.9383E
  std::cout << krk.latitude() << " " << krk.longitude() << std::endl; // 50.0614 19.9383

  const Distance dist = nyc.distance(lisboa);
  std::cout << dist.get_latitude() << " " << dist.get_longitude() << " " << dist.dist() << std::endl;   // 1.97575 -64.8632 64.8933
  // odległość kątową liczymy ze wzoru Pitagorasa: funkcja hypot() <cmath>

  const Coordinates& cl = krk.closestFrom( nyc, portugalCapital ); // wybieramy ten z dwóch punktów zadanych jako arg 1 i 2, którego odległość jest najmniejsza do krk
  std::cout << cl.name() << std::endl;  // Lisboa

  // jeśli komuś się nudzi, zagadka: co zrobić by to działało?
  nearLisboa.latitude() -= 0.3;
  nearLisboa.print();   // Near Lisboa: 40.9621N 9.24268W

}
/* wynik

NYC: 40.7127N 74.0059W
Near Lisboa: 41.2621N 9.24268W
Lisboa: 38.7369N 9.14269W
Krakow: 50.0614N 19.9383E
50.0614 19.9383
1.97575 -64.8632 64.8933
Lisboa

 */
