#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_5.h"

void insertSort_2part(int* list, size_t size)
{
	if (size == 1) {
		return; 
	}

	// now head and tail will not be identical when sorted; 
	size_t head = 0; 
	size_t tail = 0; 
	int* cache = new int[size]; 

	// init; 
	cache[0] = list[0]; 

	// sorting; 
	for (size_t index = 1; index < size; ++index) {
		if (list[index] <= cache[head]) {
			head = (head + size - 1) % size; // avoid overflow; 
			cache[head] = list[index]; 
		}
		else if (list[index] >= cache[tail]) {
			++tail; // tail will never overflow; 
			cache[tail] = list[index]; 
		}
		else {
			// find insert pos; 
			size_t jndex = 0; 
			for (jndex = head; cache[jndex] < list[index]; jndex = (jndex + 1) % size); 
			// shift; 
			++tail; 
			for (size_t kndex = tail; kndex != jndex; kndex = (kndex + size - 1) % size) {
				cache[kndex] = cache[(kndex + size - 1) % size]; 
			}
			// insert; 
			cache[jndex] = list[index]; 
		}
	}

	// copy; 
	for (size_t index = head; index != tail; index = (index + 1) % size) {
		list[(index + size - head) % size] = cache[index]; 
	}

	return; 
}