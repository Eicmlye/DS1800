/*
	(1) ������R��Ϊab������a��ʾǰp��Ԫ�أ�b��ʾ��n-p��Ԫ�ء��㷨�轫ab��Ϊba��������һ����������������x��Ϊ��������x^{-1}����ba=(a^{-1}b^{-1})^{-1}��

	(3) ����reverse������ʱ�临�Ӷ�ΪO(len/2) = O(len)����moveBack������ʱ�临�Ӷ�ΪO(p) + O(n - p) + O(n) = O(n)�� 
		�㷨�Ŀռ临�Ӷ�ΪO(1)��
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