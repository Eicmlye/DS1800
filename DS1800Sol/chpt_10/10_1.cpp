#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_1.h"

void altBubble(int* list, size_t size)
{
	size_t index = 0; 
	size_t jndex = size - 1;
	size_t kndex = 0; 

	while (index < jndex)
	{
		for (kndex = index; kndex < jndex; ++kndex) {
			if (list[kndex] < list[kndex + 1]) {
				list[kndex] += list[kndex + 1]; 
				list[kndex + 1] = list[kndex] - list[kndex + 1]; 
				list[kndex] -= list[kndex + 1]; 
			}
		}
		--jndex; 

		for (kndex = jndex; kndex > index; --kndex) {
			if (list[kndex] > list[kndex - 1]) {
				list[kndex] += list[kndex - 1];
				list[kndex - 1] = list[kndex] - list[kndex - 1];
				list[kndex] -= list[kndex - 1];
			}
		}
		++index; 
	}

	return; 
}

void bubbleSort(int* list, size_t size)
{
	for (size_t index = size - 1; index > 0; --index) {
		for (size_t jndex = 0; jndex < index; ++jndex) {
			if (list[jndex] < list[jndex + 1]) {
				list[jndex] += list[jndex + 1];
				list[jndex + 1] = list[jndex] - list[jndex + 1];
				list[jndex] -= list[jndex + 1];
			}
		}
	}

	return;
}