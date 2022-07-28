#include <iostream>
#include "5_11.h"

void evenToFront(int* A, size_t n)
{
	size_t even = 0; 
	size_t odd = n - 1; 

	while (even < odd) {
		while (even < odd && A[even] % 2 == 0) {
			++even; 
		}
		while (even < odd && A[odd] % 2 == 1) {
			--odd; 
		}

		if (even != odd) { // swap; 
			A[even] += A[odd]; 
			A[odd] = A[even] - A[odd]; 
			A[even] -= A[odd]; 
			
			++even;
			--odd; 
		}
	}

	return; 
}