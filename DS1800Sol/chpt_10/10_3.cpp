#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_3.h"

void insertSort(int* list, size_t size)
{
	for (size_t index = 0; index < size; ++index) {
		size_t jndex = 0; 
		int cache = list[index];

		/* find inserting pos */
		while (jndex < index) {
			if (list[index] > list[jndex]) {
				++jndex; 
			}
			else {
				break; 
			}
		}

		/* shift */
		for (size_t kndex = index; kndex > jndex; --kndex) {
			list[kndex] = list[kndex - 1]; 
		}
		/* insert */
		list[jndex] = cache; 
	}

	return; 
}