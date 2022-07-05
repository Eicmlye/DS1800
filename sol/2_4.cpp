/*
	(1) 定义两个指针mov1和mov2，初始分别指向str1和str2的下一个节点。先分别遍历一遍得到两个单词的长度len1和len2，不妨设len1 > len2。再次初始化指针，将mov1沿链表移动len1 - len2个结点后，与mov2同时遍历链表，当二者的值相等时，该地址即为目标结点的地址。

	(3) 求长度的时间复杂度为O(len1 + len2), 求目标节点的时间复杂度为O(max{len1, len2}), 故算法的时间复杂度为O(len1 + len2); 
*/

#include <iostream> 
#include "2_4.h"

Letter* getIntersect(Word str1, Word str2)
{
	Letter* mov1 = str1->next; 
	Letter* mov2 = str2->next; 
	int diff = 0; 

	/* get the lengths of the words */
	while (mov1 != nullptr) {
		++diff; 
		mov1 = mov1->next; 
	}
	while (mov2 != nullptr) {
		--diff; 
		mov2 = mov2->next; 
	}

	/* aligning the words */
	mov1 = str1->next;
	mov2 = str2->next;
	if (diff >= 0) {
		while (diff != 0) {
			mov1 = mov1->next; 
			--diff; 
		}
	}
	else {
		while (diff != 0) {
			mov2 = mov2->next; 
			++diff; 
		}
	}

	/* find target letter */
	while (mov1 != mov2) {
		mov1 = mov1->next; 
		mov2 = mov2->next; 
	}

	return mov1; 
}