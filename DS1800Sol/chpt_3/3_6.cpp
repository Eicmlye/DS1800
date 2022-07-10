#include <iostream>
#include "3_6.h"

int findMax(const int* arr, size_t n)
{
	if (n > 0) {
		int max = findMax(arr + 1, n - 1);
		return (max > arr[0]) ? max : arr[0]; 
	}
	else {
		return INT_MIN;
	}
}