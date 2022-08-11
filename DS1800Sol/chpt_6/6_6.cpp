#include <iostream>
#include "6_6.h"

size_t* buildParent(size_t* L, size_t* R, size_t N)
{
	size_t* T = new size_t[N];
	for (size_t index = 0; index < N; ++index) {
		T[index] = N;
	}
	for (size_t index = 0; index < N; ++index) {
		if (L[index] != N) {
			T[L[index]] = index;
		}
		if (R[index] != N) {
			T[R[index]] = index;
		}
	}

	return T; 
}

bool isChild(size_t* T, size_t N, size_t u, size_t v)
{
	size_t cur = u; 
	while (cur != N) {
		if (cur == v) {
			return true; 
		}

		cur = T[cur]; 
	}

	return false; 
}