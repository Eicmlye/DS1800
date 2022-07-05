/*
	��������ָ��movA��movB����ʼ�ֱ�ָ��A��B����Ԫ��㡣��ha����һ�����Ϊ�գ����Լ�¼��������ͬʱ�ֱ���A��B�����ƶ�movA��movB����ÿ��ֻ�ƶ���ָ�������ֵ��С���Ǹ�ָ�룬�ƶ�ǰ���ýڵ����ha��ĩ�ˣ�����ָ����ָ�������ֵ��ͬ����movA����ha��ĩ�ˣ���ͬʱ����Ӧ�����ƶ�����ָ�롣��һ�������ѱ��������һ��������ʣ�࣬��ֱ�ӽ�ʣ���㰴ԭ�������haĩ�ˡ��������ha��ΪĿ������ͷָ�롣

	ʱ�临�Ӷ�O(m+n), �ռ临�Ӷ�O(1). 
*/

#include <iostream>
#include "2_10.h"

LinkedList unionSet(LinkedList ha, LinkedList hb)
{
	LNode* movA = ha->next; 
	LNode* movB = hb->next; 
	ha->next = nullptr; 
	LNode* cache = ha; 

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