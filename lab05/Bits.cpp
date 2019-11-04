#include "Bits.h"


void set(Bits* bits, int* data, const int dataSize) {
	int j = dataSize-1;
	for (int i = 31; i >= 32-dataSize; i--) {
		bits->bitsArr[i] = data[j--];
	}
	bits->length = dataSize;
}

void print(const Bits* bits) {
	bool start = false; 
	for (int i = 32-bits->length; i < 32; i++) {
		//for cutting leading zeros
		if (bits->bitsArr[i] != 0) {
			start = true;
		}
		if (start) {
			std::cout << bits->bitsArr[i];
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

Bits add_up(Bits* bits1, Bits* bits2) {
	Bits result;
	int remainder = 0;
	int max = bits1->length>bits2->length ? bits1->length : bits2->length;
	result.length = max;

	for (int i = 31; i >= 32-max; i--) {
		int currentBit = bits1->bitsArr[i] + bits2->bitsArr[i] + remainder; 
		remainder = currentBit/2;
		currentBit = currentBit%2;
		result.bitsArr[i] = currentBit;
	}
	return result;
}

void bit_and(Bits* bits, Bits* mask) {
	for (int i = 0; i < 32; i++) {
		bits->bitsArr[i] = bits->bitsArr[i]&mask->bitsArr[i];
	}
}

void bit_xor(Bits* bits, Bits* mask) {
	for (int i = 0; i < 32; i++) {
		bits->bitsArr[i] = bits->bitsArr[i]^mask->bitsArr[i];
	}
}

int to_decimal(const Bits* bits) {
	int result = 0;
	for (int i = 0; i < 32; i++) {
		result += bits->bitsArr[i]*pow(2, 31-i);
	}
	return result;
}
