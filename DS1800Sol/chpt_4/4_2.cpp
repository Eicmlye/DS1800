#include <iostream>
#include "4_2.h"

size_t getInt(const char* str, size_t* arr)
{
	size_t index = 0; 
	size_t jndex = 0; 
	arr = (size_t*)malloc(100 * sizeof(size_t)); 
	if (arr == nullptr) {
		throw std::bad_alloc(); 
	}
	for (index = 0; index < 100; ++index) {
		arr[index] = 0; 
	}

	index = 0; 
	while (str[index] != '\0') {
		if (str[index] >= '0' && str[index] <= '9') {
			while (str[index] >= '0' && str[index] <= '9') {
				arr[jndex] *= 10;
				arr[jndex] += (size_t)(str[index] - '0');
				++index;
			}

			if (index > 0 && str[index - 1] >= '0' && str[index - 1] <= '9') {
				++jndex;
			}
		}
		else {
			++index; 
		}
	}

	for (index = 0; index < jndex; ++index) {
		std::cout << arr[index] << ' '; 
	}
	std::cout << std::endl; 

	return jndex; 
}