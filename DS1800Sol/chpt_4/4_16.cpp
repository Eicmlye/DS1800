#include <iostream>
#include "4_16.h"

bool isPattern(void)
{
	char* stk = (char*)malloc(100 * sizeof(char)); 
	if (stk == nullptr) {
		throw std::bad_alloc(); 
	}
	for (size_t index = 0; index < 100; ++index) {
		stk[index] = '\0'; 
	}
	size_t top = 0; 

	char cache = '\0'; 
	while ((cache = getchar()) != '&') {
		stk[top] = cache; 
		++top; 
	}

	while ((cache = getchar()) != '@' && top != 0) {
		if (cache != stk[top - 1]) {
			free(stk); 

			return false; 
		}
		--top; 
	}

	free(stk); 
	fflush(nullptr); 
	if (cache == '@' && top == 0) {
		return true; 
	}
	return false; 
}