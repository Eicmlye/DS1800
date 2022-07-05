/*
	�����۰��������. ����ԭ������, �����ö��ֲ���, ����x������к��λ��; Ȼ������˳����뽫x�������. 

	���ֲ��ҵ�ʱ�临�Ӷ�ΪO(lognum), �����ʱ�临�Ӷ�ΪO(num), ����ʱ�临�Ӷ�ΪO(num); �ռ临�Ӷ�ΪO(1); 
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