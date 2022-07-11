#include <iostream>
#include "3_9.h"

unsigned int recAck(unsigned int m, unsigned int n)
{
	if (m == 0) {
		return n + 1; 
	}
	// now m != 0; 
	if (n == 0) {
		return recAck(m - 1, 1); 
	}

	return recAck(m - 1, recAck(m, n - 1)); 
}

int Ack(int m, int n)
{
	/* stack node definition */
	struct {
		int mval = -1; 
		int nval = -1; 
		int ack = -1; 
	} stk[1000];

	/* target ack initialization */
	size_t top = 0; 
	stk[top].mval = m; 
	stk[top].nval = n; 

	while (stk[0].ack == -1) {
		if (stk[top].ack == -1) { // not yet computed; 
			if (stk[top].mval == 0) {
				stk[top].ack = stk[top].nval + 1; 
			}
			else if (stk[top].nval == 0) {
				++top; 
				stk[top].mval = stk[top - 1].mval - 1; 
				stk[top].nval = 1; 
				stk[top].ack = -1; 
			}
			else {
				++top;
				stk[top].mval = stk[top - 1].mval - 1;
				stk[top].nval = -1;
				stk[top].ack = -1;

				++top; 
				stk[top].mval = stk[top - 2].mval; 
				stk[top].nval = stk[top - 2].nval - 1; 
				stk[top].ack = -1; 
			}
		}
		else { // computation done; 
			if (stk[top - 1].nval == -1) {
				stk[top - 1].nval = stk[top].ack; 
			}
			else {
				stk[top - 1].ack = stk[top].ack; 
			}

			--top; 
		}
	}

	return stk[0].ack; 
}