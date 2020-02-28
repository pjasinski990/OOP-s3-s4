#include "check_number.h"
#include <stdio.h>

char find_ctrl(char const* card) {
	/*
	 * Liczy sume kontrolna w celu weryfikacji numeru 
	 * karty kredytowej. Uzywa algorytmu Luhna.
	 *
	 * Argumenty: numer karty kredytowej jako lancuch znakow
	 * Zwraca: ostatnia cyfre sumy kontrolnej przedstawiona jako char
	 */

	int n = strlen(card);
	char control = 0, counter = 0, temp;
	for (int i = n-1; i >= 0; i--) {
		temp = (card[i]-'0') * (counter++ %2 + 1);
		control += temp/10;
		control += temp%10;
	}
	return control%10+'0';
}

bool number_correct(char const* card) {
	/*
	 * Weryfikuje poprawnosc numeru karty kredytowej.
	 *
	 * Argumenty: numer karty kredytowej jako lancuch znakow
	 * Zwraca: prawde w przypadku poprawnego numeru, falsz w przeciwnej sytuacji.
	 */

	char ctrl = find_ctrl(card);
	if (ctrl - '0') {
		return false;
	}
	else {
		return true;
	}
}
