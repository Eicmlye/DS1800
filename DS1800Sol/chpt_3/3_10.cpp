#include <iostream>
#include "3_10.h"

void recPrintCombination(size_t head, size_t n, size_t k, size_t* arr, size_t len)
{
	if (k <= n - head + 1) {
		if (k == 1) {
			for (size_t index = 0; index < len; ++index) {
				std::cout << arr[index] << ' ';
			}
			std::cout << head << std::endl;
		}
		else {
			arr[len] = head; 
			recPrintCombination(head + 1, n, k - 1, arr, len + 1);
		}

		recPrintCombination(head + 1, n, k, arr, len);
	}

	return; 
}

void printCombination(size_t n, size_t k)
{
	if (n < k) {
		return; 
	}

	bool* flag = new bool[n]; 
	if (flag == nullptr) {
		return; 
	}

	/* initialization */
	for (size_t index = 0; index < k; ++index) {
		flag[index] = true;
		std::cout << index + 1 << ' ';
	}
	std::cout << std::endl;
	for (size_t index = k; index < n; ++index) {
		flag[index] = false;
	}

	/* 10 -> 01 */
	size_t mov = 0; 
	while (mov != n - 1) {
		if (flag[mov] == true && flag[mov + 1] == false) {
			flag[mov] = false; 
			flag[mov + 1] = true; 

			/* count 1's before */
			size_t count = 0; 
			for (size_t index = 0; index < mov; ++index) {
				if (flag[index]) {
					++count;
				}
			}
			/* move all 1's before mov to the front */
			for (size_t index = 0; index < count; ++index) {
				flag[index] = true;
			}
			for (size_t index = count; index < mov; ++index) {
				flag[index] = false;
			}
			/* print combination */
			for (size_t index = 0; index < n; ++index) {
				if (flag[index]) {
					std::cout << index + 1 << ' ';
				}
			}
			std::cout << std::endl; 

			mov = 0; 
		}
		else {
			++mov;
		}
	}

	delete[] flag; 

	return; 
}