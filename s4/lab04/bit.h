#pragma once
#include <iostream>

struct bit {
	bit(unsigned char* ptr, int position): byte{ptr}, shift{position} {}
	void operator=(bool flag) {
		if (flag) {
			*byte |= 0b1 << shift;
		}
		else {
			*byte &= ~(0b1 << shift);
		}
	}
	operator bool() const {
		return static_cast<bool>(*byte & (0b1<<shift));
	}

	unsigned char* byte;
	int shift;
};
