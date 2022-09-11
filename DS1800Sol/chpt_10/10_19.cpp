#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_19.h"

static void partition(int* list, size_t& head, size_t& tail)
{
	#define TESTPRINTPIVOT printf("Pivot = % 2.1f, List: ", pivot / (float)(tail - head + 1)); 

	// get pivot; 
	int pivot = 0; 
	for (size_t index = head; index <= tail; ++index) {
		pivot += list[index]; 
	}
	TESTPRINTPIVOT;

	// partitioning; 
	int num = (int)(tail - head + 1); 
	while (head < tail) {
		while (head <= tail && list[tail] * num > pivot) {
			--tail;
		}

		while (head <= tail && list[head] * num < pivot) {
			++head;
		}
		
		if (head < tail) {
			int cache = list[tail]; 
			list[tail] = list[head]; 
			list[head] = cache; 
			++head; 
			--tail; 
		}
	}

	return; 
}

void quickSortAvg(int* list, size_t head, size_t tail)
{
	#define TESTPRINTLIST \
		do {\
			for (size_t index = 0; index < 10; ++index) {\
				printf("% 2d ", list[index]); \
			}\
			std::cout << std::endl; \
		} while (0)

	if (head < tail) {
		size_t backHead = head; 
		size_t frontTail = tail; 
		partition(list, backHead, frontTail);
		TESTPRINTLIST;

		if (head < frontTail) {
			quickSortAvg(list, head, frontTail);
		}
		if (backHead < tail) {
			quickSortAvg(list, backHead, tail);
		}
	}

	return; 
}