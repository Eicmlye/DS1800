/*
	(1) ��������ָ��mov1��mov2����ʼ�ֱ�ָ��str1��str2����һ���ڵ㡣�ȷֱ����һ��õ��������ʵĳ���len1��len2��������len1 > len2���ٴγ�ʼ��ָ�룬��mov1�������ƶ�len1 - len2��������mov2ͬʱ�������������ߵ�ֵ���ʱ���õ�ַ��ΪĿ����ĵ�ַ��

	(3) �󳤶ȵ�ʱ�临�Ӷ�ΪO(len1 + len2), ��Ŀ��ڵ��ʱ�临�Ӷ�ΪO(max{len1, len2}), ���㷨��ʱ�临�Ӷ�ΪO(len1 + len2); 
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