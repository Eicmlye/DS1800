#include <iostream>
#include "5_12.h"


size_t recPowerSet(char* A, size_t n, char* cur, size_t len, size_t ind, char** P, size_t size)
{
	// create copy of cur;
	char* newElem = new char[len + 1];
	for (size_t index = 0; index < len; ++index) {
		newElem[index] = cur[index];
	}
	newElem[len] = '\0';
	// push into P;
	P[size] = newElem;
	++size;

	// the initial index condition is to deal with the first char of A, since size_t cannot be negative; 
	for (size_t index = ((cur[0] == '\0') ? 0 : (ind + 1)); index < n; ++index) {
		// push a new element into cur;
		cur[len] = A[index];
		// size must be global, get the return value to update size;
		size = recPowerSet(A, n, cur, len + 1, index, P, size);
	}

	return size;
}