/*
	(1) 将数组R记为ab，其中a表示前p个元素，b表示后n-p个元素。算法需将ab化为ba，考虑用一个函数将任意序列x化为其逆序列x^{-1}，则ba=(a^{-1}b^{-1})^{-1}。

	(3) 由于reverse函数的时间复杂度为O(len/2) = O(len)，故moveBack函数的时间复杂度为O(p) + O(n - p) + O(n) = O(n)。 
		算法的空间复杂度为O(1)。
*/

#include <iostream>
#include "2_2.h"

static void reverse(int* arr, size_t len)
{
	size_t index = 0; // set probe; 

	/* reverse */
	while (index < len / 2) { 
		arr[index] += arr[len - index - 1]; 
		arr[len - index - 1] = arr[index] - arr[len - index - 1]; 
		arr[index] -= arr[len - index - 1]; 

		++index; 
	}

	return; 
}

void moveBack(int* arr, size_t n, size_t p)
{
	reverse(arr, p); 
	reverse(arr + p, n - p); 
	reverse(arr, n); 

	return; 
}