/*
	本质是快速排序中的一次划分。

	时间复杂度O(n), 空间复杂度O(1); 
*/

#include <iostream>
#include "2_20.h"

void partition(int* arr, size_t n)
{
	int cache = arr[0]; 
	size_t high = n - 1; 
	size_t low = 0; 

	while (low < high) {
		while (low < high && arr[high] > 0) {
			--high; 
		}
		arr[low] = arr[high];
		while (low < high && arr[low] < 0) {
			++low; 
		}
		arr[high] = arr[low];
	}

	arr[low] = cache; 

	return; 
}