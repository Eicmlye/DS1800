/*
	(1) ��������������н磬���Զ���һ��nԪ����flag����Ǹ�������ֵ�Ƿ���ֹ����ٶ�������ָ��mov��pred����ʼ�ֱ�ָ��head����һ���ڵ��head������mov��predͬʱ����������mov��ָ������ݾ���ֵδ���֣����޸�flag�ı�ǣ����ѳ��ֹ�����ɾ���ýڵ㲢����pred����ʣ�������

	(2) typedef struct LNode {
			int data = 0;
			LNode* link = nullptr;
		} LNode;

	(4) �㷨������һ������ʱ�临�Ӷ�ΪO(m); �㷨��ҪnԪ����������飬�ռ临�Ӷ�ΪO(n); 
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