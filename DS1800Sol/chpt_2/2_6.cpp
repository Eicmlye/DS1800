/*
	定义两个指针movA和movB，初始分别指向两个链表的首元结点，同时遍历两个链表，且遍历时仅有所指结点数据值更大的那个指针沿链表移动。移动指针前，将其所指结点插入到新链表的表头（即头插法）。当一个链表已遍历完，直接移动另一指针并插入其所指结点即可; 

	时间复杂度O(len1 + len2), 空间复杂度O(1); 
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