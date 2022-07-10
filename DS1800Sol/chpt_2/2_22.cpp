/*
	考虑折半插入排序. 由于原表有序, 先利用二分查找, 搜索x插入表中后的位置; 然后利用顺序插入将x插入表中. 

	二分查找的时间复杂度为O(lognum), 插入的时间复杂度为O(num), 故总时间复杂度为O(num); 空间复杂度为O(1); 
*/

#include <iostream>
#include "2_22.h"

void insert(int* arr, size_t num, int x)
{
	// binary search for x's position; 
	size_t low = 0; 
	size_t high = num - 1; 

	while (high > low) {
		if (arr[(low + (high - low) / 2)] == x) {
			low += (high - low) / 2; 
			break; 
		}
		else if (arr[(low + (high - low) / 2)] > x) {
			high -= (high - low) / 2 + 1;
		}
		else {
			low += (high - low) / 2 + 1;
		}
	}

	size_t index = 0; 
	for (index = 0; index < num - low; ++index) {
		arr[num - index] = arr[num - index - 1]; 
	}
	arr[low] = x; 

	return; 
}