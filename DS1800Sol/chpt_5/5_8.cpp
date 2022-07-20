#include <iostream>
#include "5_8.h"

void fillSquare(int** mat, size_t n)
{
	size_t fill = 1; 
	size_t diagSum = 0; 
	bool direction = false; 

	while (fill <= n * n) {
		if (diagSum < n) {
			if (direction) {
				for (size_t index = 0; index <= diagSum; ++index) {
					mat[diagSum - index][index] = (int)fill;
					++fill;
				}
			}
			else {
				for (size_t index = 0; index <= diagSum; ++index) {
					mat[index][diagSum - index] = (int)fill;
					++fill;
				}
			}
		}
		else {
			if (direction) {
				for (size_t index = n - 1; index > diagSum - n; --index) {
					mat[index][diagSum - index] = (int)fill;
					++fill;
				}
			}
			else {
				for (size_t index = n - 1; index > diagSum - n; --index) {
					mat[diagSum - index][index] = (int)fill;
					++fill;
				}
			}
		}

		++diagSum; 
		direction = !direction; 
	}

	return; 
}