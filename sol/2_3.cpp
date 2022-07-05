/*
	(1) 定义两个索引index和jndex，初始值均为0，分别同时遍历A和B: 当A[index] >= B[jndex]时，jndex沿B移动一个元素; 反之则index沿A移动一个元素。当两者移动总次数为L时, 移动前的元素即为中位数。
	
	(3) 算法的时间复杂度为O(L/2) = O(L), 空间复杂度为O(1); 
*/

#include <iostream>
#include "2_3.h"

int findMid(int* A, int* B, size_t L)
{
	size_t index = 0; 
	size_t jndex = 0; 
	int result = 0; 

	while (index + jndex < L) {
		if (A[index] >= B[jndex]) {
			result = B[jndex];
			++jndex; 
		}
		else {
			result = A[index];
			++index; 
		}
	}

	return result; 
}