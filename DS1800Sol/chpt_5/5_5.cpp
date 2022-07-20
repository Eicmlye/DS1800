#include <iostream>
#include "5_5.h"

void findSaddlePoint(int** A, size_t m, size_t n)
{
	for (size_t index = 0; index < m; ++index) {
		/* find row min */
		int rowMin = INT_MAX; 
		size_t colInd = 0; 
		for (size_t jndex = 0; jndex < n; ++jndex) {
			if (A[index][jndex] < rowMin) {
				rowMin = A[index][jndex]; 
				colInd = jndex; 
			}
		}

		/* check if col max */
		size_t kndex = 0; 
		for (kndex = 0; kndex < m; ++kndex) {
			if (A[kndex][colInd] > rowMin) {
				break; 
			}
		}
		if (kndex == m) {
			std::cout << rowMin << ' '; 
		}
	}
	std::cout << std::endl; 

	return; 
}