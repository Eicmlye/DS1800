#include <iostream>
#include "2_65.h"

DList<bool> createBinum(void)
{
	/* cyclic doublelist with header */
	DList<bool> result = new DNode<bool>(false);
	result->next = result; 
	result->pred = result; 
	char ch = '\0'; 

	/* dealing with leading zeros */
	while ((ch = getchar()) == '0') { /* the last '\n' will be loaded */
		continue; 
	}

	/* now loading valid data */
	/* for '000...0\n' case */
	if (ch == '\n') {
		result->next = new DNode<bool>(ch == '1', result->next, result);
		result->next->next->pred = result->next;

		return result; 
	}
	/* use do-while for the first '1' loaded when dealing with leading zeros */
	DNode<bool>* mov = result;
	do {
		mov->next = new DNode<bool>(ch == '1', mov->next, mov);
		mov->next->next->pred = mov->next;

		mov = mov->next;
	} while ((ch = getchar()) == '0' || ch == '1');

	return result; 
}

static void printBinum(DList<bool> num)
{
	for (DNode<bool>* mov = num->next; mov != num; mov = mov->next) {
		std::cout << std::noboolalpha << mov->data; 
	}
	std::cout << std::endl; 

	return; 
}

void incBinum(DList<bool>& num)
{ 
	/* increment*/
	for (DNode<bool>* mov = num->pred; mov != num; mov = mov->pred) {
		mov->data = !mov->data; 

		/* dealing with carrying bit */
		if (mov->data) { // no carrying bit; 
			break; 
		}
		// now carrying bit exists; 
		if (mov->pred == num) { // carrying bit creates a new digit; 
			mov = new DNode<bool>(true, num->next, num); 
			num->next->pred = mov; 
			num->next = mov; 
		}
	}

	/* print result */
	printBinum(num); 

	return; 
}