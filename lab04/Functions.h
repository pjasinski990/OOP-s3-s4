#pragma once
#include <iostream>
#include <math.h>

typedef double* DataPtr;
typedef void (*functionPtr)(DataPtr target);

double* initializeData(const int size);
void printSeries(DataPtr start, DataPtr end);
void add_one(DataPtr target);
void tripple(DataPtr target);
void squareroot(DataPtr target);
void executeFunction(functionPtr fun, DataPtr start, DataPtr end);
void clearData(DataPtr target);
