#include <iostream>
#include "2_63.h"

DFNode<int>* find(DFList<int>& L, int x)
{
	L->freq = UINT_MAX; 

	/* find node */
	DFNode<int>* result = L->next;
	while (result != nullptr && result->data != x) {
		result = result->next; 
	}

	if (result == nullptr) { // not found; 
		return result; 
	}

	/* search new pos */
	++result->freq; 
	DFNode<int>* mov = result->pred;
	while (mov->freq < result->freq) {
		mov = mov->pred; 
	}

	/* move node */
	result->pred->next = result->next; 
	if (result->next != nullptr) {
		result->next->pred = result->pred;
	}
	result->pred = mov; 
	result->next = mov->next; 
	if (mov->next != nullptr) {
		mov->next->pred = result;
	}
	mov->next = result; 

	return result; 
}