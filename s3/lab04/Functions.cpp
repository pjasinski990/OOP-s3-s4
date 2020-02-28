#include "Functions.h"

DataPtr initializeData(const int size) {
	/* Allocates memory and initializes sample data 
	 * (sequence of numbers starting from 0).
	 *
	 * Takes: size of data (const int).
	 *
	 * Returns: pointer to newly allocated data (DataPtr).
	 */
	DataPtr data = new double[size];
	for (int i = 0; i < size; i++) {
		data[i] = i;
	}
	return data;
}

void printSeries(DataPtr start, DataPtr end) {
	/* Prints formatted data.
	 * 
	 * Takes: start data pointer and end data pointer (DataPtr).
	 *
	 * Returns: void function.
	 */
	for (; start<end; start++) {
		std::cout << *start;
		if (start+1 != end) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

void add_one(DataPtr target) {
	/* Overrides passed value with value incremented by one.
	 *
	 * Takes: pointer to argument to calculate.
	 *
	 * Returns: void function.
	 */
	(*target)++;
}

void tripple(DataPtr target) {
	/* Overrides passed value with triple its value.
	 *
	 * Takes: pointer to argument to calculate.
	 *
	 * Returns: void function.
	 */
	(*target)*=3;
}

void squareroot(DataPtr target) {
	/* Overrides passed value with its square root value.
	 *
	 * Takes: pointer to argument to calculate.
	 *
	 * Returns: void function.
	 */
	*target = sqrt(*target);
}

void executeFunction(functionPtr fun, DataPtr start, DataPtr end) {
	/*
	 * Executes function passed by pointer for all items in array.
	 *
	 * Takes: pointer to function to execute (void (*fun)(DataPtr)),
	 * start of data pointer and end of data pointer (DataPtr).
	 *
	 * Returns: void function.
	 */
	for (; start < end; start++) {
		fun(start);
	}
}

void clearData(DataPtr target) {
	/*
	 * Frees memory allocated for data by "initializeData".
	 * 
	 * Takes: pointer to data to free.
	 *
	 * Returns: void function.
	 */
	delete[] target;
}
