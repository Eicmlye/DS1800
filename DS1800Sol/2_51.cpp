/*
	mode 0:
	����ָ��pivot��cache, ��ʼ�ֱ�ָ��listָ��Ľ��ĺ�̼����̵ĺ��. �ظ���cacheָ��Ľ������ͷ�巨����listָ��Ľ��֮��, ֱ��pivot�ĺ��Ϊ����. ����޸�pivot�ĺ��ָ��Ϊlist�ĺ��. 

	ʱ�临�Ӷ�O(n), �ռ临�Ӷ�O(1); 
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