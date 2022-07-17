#include <iostream>
#include "4_12.h"

char* remakeStr(void)
{
	size_t size = 100; 
	char* stk = (char*)malloc(size * sizeof(char));
	char* result = (char*)malloc(2 * size * sizeof(char)); 
	if (stk == nullptr || result == nullptr) {
		throw std::bad_alloc(); 
	}

	size_t top = 0; 
	size_t len = 0; 

	char cache = '\0'; 
	bool flag = false; 
	while ((cache = getchar()) != '\n') {
		if (flag) {
			stk[top] = cache; 
			++top; 
		}
		else {
			result[len] = cache; 
			++len; 
		}

		flag = !flag; 
	}

	while (top != 0) {
		result[len] = stk[top - 1]; 
		++len; 
		--top; 
	}
	result[len] = '\0'; 

	free(stk); 

	return result; 
}