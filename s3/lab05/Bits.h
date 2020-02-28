#pragma once
#include <iostream>
#include <math.h>

/*! \file Bits.h
 * Header for Bits library.
 */

/*! \struct Bits
 * Structure containing array of bits of const size and amount of written bits
 */
struct Bits {
	int bitsArr[32] = {0};
	int length = 0;
};

/*!
 * Sets passed bits structure with values from data array.
 * Bits are padded with zeros on the left to the full length of bitsArr.
 *
 * \param bits address of structure to be written
 * \param data int array with 0-1 values for bits array
 * \param dataSize length of data array
 * \return void
 */
void set(Bits* bits, int* data, const int dataSize);
/*!
 * Prints passed bits structure.
 * \param bits address of bits struct to be printed
 * \return void
 */
void print(const Bits* bits);

/*!
 * Adds passed bits structures to create new sum struct.
 *
 * \param bits1 first argument
 * \param bits2 second argument
 * \return Structure with summed arguments
 */
Bits add_up(Bits* bits1, Bits* bits2);
/*!
 * Masks passed bits struct using bitwise AND operation and provided mask.
 *
 * \param bits address of structure to be operated on
 * \param mask mask for bitwise operation
 * \return void
 */
void bit_and(Bits* bits, Bits* mask);
/*!
 * Masks passed bits struct using bitwise XOR operation and provided mask.
 *
 * \param bits address of structure to be operated on
 * \param mask mask for bitwise operation
 * \return void
 */
void bit_xor(Bits* bits1, Bits* mask);
/*!
 * Calculates decimal value of bits array in Bits struct.
 *
 * \param bits structure to be calculated
 * \return integer value of bits array
 */
int to_decimal(const Bits* bits);
