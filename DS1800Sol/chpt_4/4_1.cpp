#include <iostream>
#include "4_1.h"

char isSubStr(const char* s, const char* t, const size_t m, const size_t n)
{
	if (m < n) {
		return 0; 
	}

	size_t index = 0; 
	size_t jndex = 0; 
	for (index = 0; index < m - n + 1; ++index) {
		for (jndex = 0; jndex < n; ++jndex) {
			if (s[index + jndex] != t[jndex]) {
				break; 
			}
		}

		if (jndex == n) {
			return s[index];
		}
	}

	return 0; 
}