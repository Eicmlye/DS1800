/*
	������m>=n������һ��ָ��mov����ʼָ��L2����Ԫ��㡣mov����L2����β��㣬Ȼ��L1��ͷ�����L2����Ԫ������ӣ���mov��L1����Ԫ������Ӽ��ɡ�

	ʱ�临�Ӷ�O(min{m,n}), �ռ临�Ӷ�O(1). 
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