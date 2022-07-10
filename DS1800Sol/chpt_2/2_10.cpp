/*
	定义两个指针movA和movB，初始分别指向A和B的首元结点。将ha的下一结点设为空，用以记录所求链表。同时分别沿A、B链表移动movA和movB，且每次只移动所指结点数据值更小的那个指针，移动前将该节点接至ha的末端；若两指针所指结点数据值相同，则将movA接至ha的末端，并同时沿相应链表移动两个指针。若一个链表已遍历完而另一链表仍有剩余，则直接将剩余结点按原次序接至ha末端。最后所得ha即为目标链表头指针。

	时间复杂度O(m+n), 空间复杂度O(1). 
*/

#include <iostream>
#include "2_10.h"

LinkedList<int> unionSet(LinkedList<int> ha, LinkedList<int> hb)
{
	LNode<int>* movA = ha->next;
	LNode<int>* movB = hb->next;
	ha->next = nullptr; 
	LNode<int>* cache = ha;

	while (movA != nullptr && movB != nullptr) {
		if (movA->data > movB->data) {
			cache->next = movB; 
			movB = movB->next; 
			cache = cache->next; 
		}
		else if (movA->data < movB->data) {
			cache->next = movA;
			movA = movA->next;
			cache = cache->next;
		}
		else {
			cache->next = movA;
			movA = movA->next;
			movB = movB->next;
			cache = cache->next;
		}
	}

	while (movA != nullptr) {
		cache->next = movA;
		movA = movA->next;
		cache = cache->next;
	}
	while (movB != nullptr) {
		cache->next = movB;
		movB = movB->next;
		cache = cache->next;
	}

	return ha; 
}