#include <iostream>
#include "2_52.h"

void doubleRev(LinkedList& list, LNode* p)
{
	LNode* mov = list->next; 
	LNode* newNode = nullptr; 

	while (mov != p) {
		newNode = new LNode(mov->data, p->next); 
		p->next = newNode; 
		mov = mov->next; 
	}

	return; 
}