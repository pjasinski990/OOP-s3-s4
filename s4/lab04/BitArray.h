#pragma once
#include <iostream>
#include <cstring>
#include "bit.h"

class BitArray {
public:
	BitArray(size_t size, bool states = false): m_bitCount{size} {
		m_byteCount = m_bitCount/8;
		if (m_bitCount%8 != 0) { ++m_byteCount; }
		m_bitArray = new unsigned char[m_byteCount];

		if (states == true) { 
			std::memset(m_bitArray, 0xff, m_byteCount); 
		} else { 
			std::memset(m_bitArray, 0x00, m_byteCount); 
		}
	}

	~BitArray() { delete[] m_bitArray; }

	BitArray(const BitArray& o): m_byteCount{o.m_byteCount}, m_bitCount{o.m_bitCount} {
		m_bitArray = new unsigned char[m_byteCount];
		std::memcpy(m_bitArray, o.m_bitArray, m_byteCount);
	}

	BitArray& operator=(const BitArray& o) {
		if (this != &o) {
			if (m_byteCount != o.m_byteCount) {
				m_byteCount = o.m_byteCount;
				delete[] m_bitArray;
				m_bitArray = nullptr;
				m_bitArray = new unsigned char[m_byteCount];
			}
			m_bitCount = o.m_bitCount;
			std::memcpy(m_bitArray, o.m_bitArray, m_byteCount);
		}
		return *this;
	}

	bit operator[](int index) { return bit(m_bitArray+index/8, index%8); }
	const bit operator[](int index) const { return bit(m_bitArray+index/8, index%8); } 

	void print() const {
		int currentByte = m_byteCount-1;
		if (m_bitCount%8 != 0) {
			for (int i = m_bitCount%8-1; i >= 0; i--) {
				std::cout << static_cast<bool>(m_bitArray[currentByte] & (0b1 << i));
			}
			std::cout << " <- " << currentByte*8 << " ";
			--currentByte;
		}
		for (; currentByte >= 0; --currentByte) {
			for (int i = 7; i >= 0; i--) {
				std::cout << static_cast<bool>(m_bitArray[currentByte] & (0b1 << i));
			}
			std::cout << " <- " << currentByte*8 << " ";
		}
	}

private:
	unsigned char* m_bitArray;
	size_t m_byteCount;
	size_t m_bitCount;
};
