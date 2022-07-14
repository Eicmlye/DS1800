#include <iostream>
#include "3_14.h"

void recPermu(int* rem, bool* flag, size_t size, int* arr, size_t len)
{
	if (len == size) { // current permutation ended; 
		for (size_t index = 0; index < len; ++index) {
			std::cout << arr[index] << ' '; 
		}
		std::cout << std::endl; 
	}
	else {
		for (size_t index = 0; index < size; ++index) {
			if (!flag[index]) {
				continue; 
			}
			arr[len] = rem[index]; 
			++len; 
			flag[index] = false; 

			recPermu(rem, flag, size, arr, len); 

			// refresh;
			--len; 
			flag[index] = true; 
		}
	}

	return; 
}