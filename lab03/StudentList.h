#pragma once
#include <cstring>
#include <iostream>

void prepareList(char*** namesList, int** yearsList, int capacity);

void addStudent(int* nStudents, int* capacity, char*** namesList, int** yearsList, const char* name, const char* fname, int age);

void printListContent(int capacity, char** namesList);

void printAllListContent(int capacity, char** namesList, int* yearsList);

void clearStudents(int* capacity, int* nStudents, char*** namesList, int** yearsList);
