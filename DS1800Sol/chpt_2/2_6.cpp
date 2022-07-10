/*
	��������ָ��movA��movB����ʼ�ֱ�ָ�������������Ԫ��㣬ͬʱ�������������ұ���ʱ������ָ�������ֵ������Ǹ�ָ���������ƶ����ƶ�ָ��ǰ��������ָ�����뵽������ı�ͷ����ͷ�巨������һ�������ѱ����ֱ꣬���ƶ���һָ�벢��������ָ��㼴��; 

	ʱ�临�Ӷ�O(len1 + len2), �ռ临�Ӷ�O(1); 
*/

#include <iostream>
#include "2_6.h"

LinkedList<int> reverseMerge(LinkedList<int> A, LinkedList<int> B)
{
	LNode<int>* movA = A->next;
	LNode<int>* movB = B->next;
	A->next = nullptr; 
	LNode<int>* cache = A->next;

	while (movA != nullptr && movB != nullptr) {
		cache = A->next; 

		if (movA->data < movB->data) {
			A->next = movA;
			movA = movA->next; 
			A->next->next = cache;
		}
		else {
			A->next = movB;
			movB = movB->next;
			A->next->next = cache;
		}
	}

	while (movA != nullptr) {
		cache = A->next;
		A->next = movA;
		movA = movA->next;
		A->next->next = cache;
	}
	while (movB != nullptr) {
		cache = A->next;
		A->next = movB;
		movB = movB->next;
		A->next->next = cache;
	}

	return A;
}