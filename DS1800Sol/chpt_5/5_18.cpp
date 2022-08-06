#include <iostream>
#include "5_18.h"

void reorder(int* A, size_t* B, size_t n)
{
	for (size_t index = 0; index < n; ++index) {
		if (B[index] - 1 != index) { // if need move; 
			if (B[B[index] - 1] - 1 != index || index > B[index] - 1) { // if the cycle is longer than 2 or the current element is the first of a 2-cycle; 
				if (A[index] != A[B[index] - 1]) { // if elements are not identical; 
					A[index] += A[B[index] - 1]; 
					A[B[index] - 1] = A[index] - A[B[index] - 1]; 
					A[index] -= A[B[index] - 1]; 

					size_t ind = B[index]; 
					B[index] += B[ind - 1]; 
					B[ind - 1] = B[index] - B[ind - 1];
					B[index] -= B[ind - 1];
				}
			}
		}
	}

	return; 
}