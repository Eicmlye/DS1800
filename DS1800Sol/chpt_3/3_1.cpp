#include <iostream>
#include "3_1.h"

bool pushStk(SeqStk& stk, bool mode, int val)
{
	if (stk.topHead == stk.topTail) { // stack is full; 
		return false; 
	}

	if (!mode) {
		stk.head[stk.topHead] = val; 
		++stk.topHead; 
	}
	else {
		stk.head[stk.topTail - 1] = val; 
		--stk.topTail; 
	}

	return true; 
}

bool popStk(SeqStk& stk, bool mode, int& cache)
{
	if (!mode) {
		if (stk.topHead == 0) {
			return false; 
		}

		cache = stk.head[stk.topHead - 1]; 
		--stk.topHead; 
	}
	else {
		if (stk.topTail == stk.maxsize) {
			return false; 
		}

		cache = stk.head[stk.topTail]; 
		++stk.topTail; 
	}

	return true; 
}