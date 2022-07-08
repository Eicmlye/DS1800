#include <iostream>
#include "2_52.h"

void doubleRev(LinkedList<int>& list, LNode<int>* p)
{
	LNode<int>* mov = list->next;
	LNode<int>* newNode = nullptr;

	while (mov != p) {
		newNode = new LNode<int>(mov->data, p->next);
		p->next = newNode; 
		mov = mov->next; 
	}

	return; 
}