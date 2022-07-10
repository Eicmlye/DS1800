/*
	(1) 由于链表的数据有界，可以定义一个n元数组flag，标记各数绝对值是否出现过。再定义两个指针mov和pred，初始分别指向head的下一个节点和head本身。让mov和pred同时遍历链表，若mov所指结点数据绝对值未出现，则修改flag的标记；若已出现过，则删除该节点并利用pred连接剩余的链表。

	(2) typedef struct LNode {
			int data = 0;
			LNode* link = nullptr;
		} LNode;

	(4) 算法仅遍历一次链表，时间复杂度为O(m); 算法需要n元辅助标记数组，空间复杂度为O(n); 
*/

#include <iostream>
#include "2_5.h"

void delDup(LinkedList<int> head, size_t n)
{
	bool* flag = new bool[n]; // set existence flags; 
	memset(flag, 0, sizeof(bool) * n); // initialize flags to false; 

	LNode<int>* mov = head->next;
	LNode<int>* pred = head;
	while (mov != nullptr) { // traverse list; 
		size_t index = abs(mov->data); 

		if (!flag[index]) { // if first met; 
			flag[index] = true; 
			pred = pred->next;
		}
		else { // if have met before; 
			pred->next = mov->next;
			delete mov; 
		}

		mov = pred->next;
	}

	delete[] flag;

	return; 
}