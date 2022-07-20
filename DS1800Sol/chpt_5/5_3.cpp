#include <iostream>
#include "5_3.h"

void recCombination(int* A, size_t n, int* cache, size_t len, size_t k)
{
	if (n >= k) { // k-substring available; 
		if (k != 1) { // not at the end of the combination; 
			cache[len] = A[0]; 
			recCombination(A + 1, n - 1, cache, len + 1, k - 1); 
		}
		else { // at the end, print the combination; 
			for (size_t index = 0; index < len; ++index) {
				std::cout << cache[index] << ' '; 
			}
			std::cout << A[0] << std::endl; 
		}

		recCombination(A + 1, n - 1, cache, len, k); 
	}

	return; 
}