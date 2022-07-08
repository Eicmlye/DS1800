/*
	(1) ��������ָ�����head��tail����ʼʱ��ָ��list��ָ������һ����㡣head���������ƶ����� k ����㣬�˺�head��tailͬʱ�������ƶ���ֱ��head��ָ����linkΪ��ָ�롣��ʱtail��ָ��㼴Ϊ������ k ����㡣
		��head�ڵ����ƶ������о�Ϊ��ָ�룬�����ʧ�ܡ�
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