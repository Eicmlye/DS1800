#include <iostream>
#include "5_16.h"

void sort(int* front, size_t lenF, int* rear, size_t lenR)
{
	size_t indF = 0; 
	size_t jndR = 0; 
	size_t jndex = 0;
	int cache = 0; 

	while (jndR < lenR) {
		// find where rear[jndR] should be in front; 
		for (indF = 0; indF < lenF && front[indF] <= rear[jndR]; ++indF);
		if (indF == lenF) { // if the first element of rear is greater than front; 
			break; 
		}

		// hold the last element of front; 
		cache = front[lenF - 1]; 
		// shift front; 
		for (size_t index = 0; index < lenF - indF - 1; ++index) {
			front[lenF - index - 1] = front[lenF - index - 2];
		}
		front[indF] = rear[jndR]; 

		rear[jndR] = cache; 
		// find where cache should be in rear; 
		for (size_t index = 1; index < lenR && rear[index] < cache; ++index) {
			// if unordered, swap; 
			rear[index] += rear[index - 1]; 
			rear[index - 1] = rear[index] - rear[index - 1]; 
			rear[index] -= rear[index - 1]; 
		}

		++jndR; 
	}

	return; 
}