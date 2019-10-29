#include "StudentList.h"

void prepareList(char*** namesList, int** yearsList, int capacity) {
	/*
	 * Allocates memory for a new list of size "capacity"
	 *
	 * Takes: pointer to list of names (char***), 
	 * pointer to list of years (int*), capacity to be allocated (int)
	 *
	 * Returns: void function
	 */
	*namesList = (char**)realloc(*namesList, sizeof(char*)*capacity);
	*yearsList = (int*)realloc(*yearsList, sizeof(int)*capacity);
}

void addStudent(int* nStudents, int* capacity, char*** namesList, int** yearsList, const char* name, const char* fname, int age) {
	/* Adds a student to passed lists. If capacity is too low,
	 * allocates more memory.
	 *
	 * Takes: current n.o. students (int*), capacity (int*), pointer
	 * to names list (char***), pointer to years list (int**), 
	 * name and family name (const char*), age (int)
	 *
	 * Returns: void function
	 */
	if (*nStudents < *capacity) {
		int nameSize = strlen(name) + strlen(fname) + 2;
		(*namesList)[*nStudents] = new char[nameSize];

		strcpy((*namesList)[*nStudents], name);
		strcpy((*namesList)[*nStudents]+strlen(name), " ");
		strcpy((*namesList)[*nStudents]+strlen(name)+1, fname);

		(*yearsList)[*nStudents] = age;
		(*nStudents)++;
	}
	else {
		(*capacity) += 2;
		prepareList(namesList, yearsList, *capacity);
		addStudent(nStudents, capacity, namesList, yearsList, 
				name, fname, age);
	}
}

void printListContent(int capacity, char** namesList) {
	/* Prints names in namesList
	 *
	 * Takes: capacity of list (int) and list (char**)
	 *
	 * Returns: void fuction 
	 */
	for (int i = 0; i < capacity; i++) {
		std::cout << namesList[i] << std::endl;
	}
	std::cout << std::endl;
}

void printAllListContent(int capacity, char** namesList, int* yearsList) {
	/* Prints students
	 *
	 * Takes: capacity of list (int) and lists of names and years
	 * (char**), (int*)
	 *
	 * Returns: void fuction 
	 */
	for (int i = 0; i < capacity; i++) {
		std::cout << namesList[i] << " - " << yearsList[i] << std::endl;
	}
	std::cout << std::endl;
}

void clearStudents(int* capacity, int* nStudents, char*** namesList, int** yearsList) {
	/* Frees memory used by lists.
	 *
	 * Takes: capacity of lists (int*), number of students (int*), 
	 * lists of students names and years (char***), (int**)
	 *
	 * Returns: void function
	 */
	for (int i = 0; i < *capacity; i++) {
		delete (*namesList)[i];
	}
	free(*namesList);
	free(*yearsList);
	*nStudents = 0;
	*capacity = 0;
}
