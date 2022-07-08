/*
	不妨设m>=n，则定义一个指针mov，初始指向L2的首元结点。mov遍历L2至其尾结点，然后将L1的头结点与L2的首元结点连接，将mov与L1的首元结点连接即可。

	时间复杂度O(min{m,n}), 空间复杂度O(1). 
*/

#include <iostream>
#include "2_16.h"

LinkedList<int> mergeList(LinkedList<int> L1, size_t m, LinkedList<int> L2, size_t n)
{
	LNode<int>* origin = (m >= n) ? L2 : L1;
	LNode<int>* mov = (m >= n) ? L2->next : L1->next;
	LNode<int>* target = (m >= n) ? L1 : L2;
	if (mov == mov->next) { /* for empty list */
		return target; 
	}

	while (mov->next != origin) { /* find tail node */
		mov = mov->next; 
	}

	/* merge list */
	mov->next = target->next; 
	target->next = origin->next; 

	return target; 
}