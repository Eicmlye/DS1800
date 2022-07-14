#include <iostream>
#include "3_12.h"

unsigned int recF(unsigned int m)
{
	if (m == 0) {
		return 1; 
	}
	else {
		return m * recF(m / 2); 
	}
}

int F(unsigned int m)
{
	struct {
		unsigned int mval = 0; 
		int Fval = -1; 
	} stk[100];

	size_t top = 0; 
	stk[top].mval = m; 
	while (stk[0].Fval == -1) {
		if (stk[top].Fval == -1) {
			if (stk[top].mval == 0) {
				stk[top].Fval = 1;
			}
			else {
				++top;
				stk[top].mval = stk[top - 1].mval / 2; 
			}
		}
		else {
			--top; 
			stk[top].Fval = stk[top].mval * stk[top + 1].Fval; 
		}
	}

	return stk[0].Fval; 
}