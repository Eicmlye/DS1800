/*
	(1) 定义两个指针变量head和tail，初始时均指向list所指结点的下一个结点。head先沿链表移动至第 k 个结点，此后head与tail同时沿链表移动，直至head所指结点的link为空指针。此时tail所指结点即为倒数第 k 个结点。
		若head在单独移动过程中就为空指针，则查找失败。
*/

#include <iostream>
#include "2_1.h"

int findInvK(LinkedList<int> list, size_t k)
{
	if (k == 0) {
		return 0; 
	}

	size_t diff = 0; // distance between pointers; 
	/* set probes */
	LNode<int>* head = list->next;
	LNode<int>* tail = list->next;

	/* get length */
	while (diff != k) {
		/* target node not found */
		if (head == nullptr) {
			return 0;
		}

		++diff;
		head = head->next;
	}

	/* find target */
	while (head != nullptr) {
		head = head->next;
		tail = tail->next;
	}
	std::cout << tail->data << std::endl;

	return 1; 
}