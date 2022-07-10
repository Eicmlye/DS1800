#include <iostream>
#include "3_3.h"

RESULT EXYX(const char* expr)
{
	size_t mov = 0; 
	size_t count = 0; 
	while (expr[mov] != '#') {
		if (expr[mov] == '(') {
			++count; 
		}
		else if (expr[mov] == ')') {
			if (count == 0) {
				return RESULT::MISSING_LEFT_PARENTHESIS; 
			}
			--count; 
		}

		++mov; 
	}

	return (count == 0 ? (RESULT::MATCH) : (RESULT::MISSING_RIGHT_PARENTHESIS));
}