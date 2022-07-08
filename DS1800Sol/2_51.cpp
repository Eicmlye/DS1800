/*
	mode 0:
	定义指针pivot和cache, 初始分别指向list指向的结点的后继及其后继的后继. 重复将cache指向的结点利用头插法插入list指向的结点之后, 直至pivot的后继为自身. 最后修改pivot的后继指针为list的后继. 

	时间复杂度O(n), 空间复杂度O(1); 
*/

#include <iostream>
#include "2_51.h"

void revCyc(LinkedList<int>& list, unsigned int mode)
{
	LNode<int>* pivot = list->next; // rear of the reversed list; 
	LNode<int>* cache = pivot->next;

	/*
		mode 0: 
		list -> elem1 -> elem2 -> ... -> elem n
				  ^							|
				  |							|
				  ---------------------------
		mode 1: 
		list -> elem1 -> elem2 -> ... -> elem n
		  ^									|
		  |									|
		  -----------------------------------
		mode 2: 
		elem1 -> elem2 -> elem3 -> ... -> elem n
		  ^									|
		  |									|
		  -----------------------------------
	*/

	if (mode == 0) {
		while (pivot->next != pivot) {
			cache = pivot->next;
			pivot->next = cache->next;
			cache->next = list->next;
			list->next = cache;
		}
		pivot->next = list->next;
	}

	return; 
}