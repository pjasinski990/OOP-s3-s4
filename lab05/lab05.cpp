
// Proszę napisać funkcje wykonujące na liczbach zapisanych binarnie. 
// operacje:
// 1) sumowania (add_up)	np. 1+0=1, 1+1=10
// 2) koniunkcja (bit_and)	np. 1&1=1, 1&0=0
// 3) alternatywa wykluczająca (bit_xor)	np. 1^1=0, 1^0=1
// 4) zamiana na system dziesiętny

// Uwaga:
// - proszę wykorzystać tablicę o stałym rozmiarze np. 32
//  i przechowywać informację o "długości" liczby (liczbie bitów).
//  Nadmiarowe bity można wypełnić zerami.
// - można też użyć std::vector (jeśli ktoś zna i bardzo chce)
// - nie trzeba sprawdzać czy długości liczby i maski są zgodne 
// - proszę zadbać o nie wychodzenie poza tablicę

// Uwagi:
// - Pliku lab05.cpp proszę nie modyfikować.
// - Przy wykonaniu zadania nie wolno korzystać z pomocy kolegów, internetu, notatek, ani 
//   innych materiałów (w tym własnych wcześniej przygotowanych plikow oprócz makefile)
// - Kody źrodłowe muszą znajdować się w katalogu ~/preoop, do którego nikt oprócz
//   właściciela nie ma praw dostępu (prawa 700)
// - zadanie wysylamy na UPEL, w formie archiwum:
//    tar -czvf arch_name.tar.gz dir_name

#include "Bits.h"
#include <iostream>

int main ()
{
	int data1[] = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1};
	int data2[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 1};

	Bits bits1;
	set(&bits1, data1, sizeof(data1)/sizeof(data1[0]) );
	Bits bits2;
	set(&bits2, data2, sizeof(data2)/sizeof(data2[0]) );
	print(&bits1);
	std::cout << "  ";
	print(&bits2);

	const Bits bits3 = add_up(&bits1, &bits2);

	std::cout << "summed: " << std::endl;
	print(&bits3);
	
	int mask_data[] = {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1};
	Bits mask;
	set(&mask, mask_data, sizeof(mask_data)/sizeof(mask_data[0]) );

	bit_and(&bits1, &mask);
	std::cout << "after and: " << std::endl;
	print(&bits1);

	bit_xor(&bits1, &mask);
	std::cout << "after xor: " << std::endl << "  ";
	print(&bits1);

	const Bits bits4 = add_up(&bits1, &bits2);
	std::cout << "summed again: " << std::endl << " ";
	print(&bits4);

	std::cout << to_decimal(&bits1) << " + " << to_decimal(&bits2) << " = ";
	std::cout << to_decimal(&bits4) << std::endl;
}
/* wynik dzialania programu:

110011101111

  1010101011

summed: 
111110011010

after and: 
110010101101

after xor: 
  1100010000

summed again: 
 10110111011

784 + 683 = 1467


*/
