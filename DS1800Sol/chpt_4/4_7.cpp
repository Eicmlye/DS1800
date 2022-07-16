#include <iostream>
#include "4_7.h"

int my_atoi(const char* str)
{
	int result = 0;
	size_t index = 0;
	if (str[0] == '-') {
		++index;
	}

	while (str[index] >= '0' && str[index] <= '9') {
		result *= 10;
		result += str[index] - '0';

		++index; 
	}

	return result * ((str[0] == '-') ? -1 : 1);
}