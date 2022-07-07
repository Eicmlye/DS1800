#include <iostream>
#include "2_53.h"

void printInv(const LinkedList list)
{
	if (list->next != nullptr) {
		printInv(list->next);
	}
	std::cout << list->data << ' ';

	return; 
}