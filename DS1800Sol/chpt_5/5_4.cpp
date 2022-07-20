#include <iostream>
#include "5_4.h"

static size_t Partition(int* arr, size_t* ind, size_t head, size_t tail)
{
	size_t pivotInd = head + (size_t)((tail - head) * rand() / (double)(RAND_MAX)); 
	int pivot = arr[pivotInd]; 

	arr[pivotInd] = arr[head]; 
	arr[head] = pivot; 
	ind[pivotInd] = ind[head]; 
	ind[head] = pivotInd; 

	while (head < tail) {
		while (head < tail && arr[tail] >= pivot) {
			--tail; 
		}
		arr[head] = arr[tail];
		ind[head] = ind[tail];

		while (head < tail && arr[head] <= pivot) {
			++head; 
		}
		arr[tail] = arr[head]; 
		ind[tail] = ind[head];
	}
	arr[head] = pivot; 
	ind[head] = pivotInd;

	return head; 
}

static void quickSort(int* arr, size_t* ind, size_t head, size_t tail)
{
	if (head < tail) {
		size_t pivot = Partition(arr, ind, head, tail); 
		if (head + 1 < pivot) {
			quickSort(arr, ind, head, pivot - 1); 
		}
		if (pivot + 1 < tail) {
			quickSort(arr, ind, pivot + 1, tail); 
		}
	}

	return; 
}

void sortRowAvg(int** mat, size_t n)
{
	// To avoid comparing floating-point numbers, 
	// use sum to indicate average; 
	int* sum = new int[n]; 
	if (sum == nullptr) { // alloc success; 
		throw std::bad_alloc(); 
	}
	for (size_t index = 0; index < n; ++index) { // init; 
		sum[index] = 0; 
	}

	// collect sum for each row; 
	for (size_t index = 0; index < n; ++index) {
		for (size_t jndex = 0; jndex < n; ++jndex) {
			sum[index] += mat[index][jndex];
		}
	}

	size_t* ind = new size_t[n]; 
	if (ind == nullptr) {
		throw std::bad_alloc(); 
	}
	for (size_t index = 0; index < n; ++index) {
		ind[index] = index; 
	}
	quickSort(sum, ind, 0, n - 1); 

	/* create sample matrix */
	int** temp = new int* [n];
	if (temp == nullptr) {
		throw std::bad_alloc();
	}
	int* cache = nullptr;

	for (size_t index = 0; index < n; ++index) {
		cache = new int[n];
		for (size_t jndex = 0; jndex < n; ++jndex) {
			cache[jndex] = mat[ind[index]][jndex];
		}
		temp[index] = cache;
	}

	/* copy matrix */
	for (size_t index = 0; index < n; ++index) {
		cache = new int[n];
		for (size_t jndex = 0; jndex < n; ++jndex) {
			mat[index][jndex] = temp[index][jndex];
		}
	}

	/* delete aux pointers */
	for (size_t index = 0; index < n; ++index) {
		delete[] temp[index];
	}
	delete[] temp;

	return;
}