/*
	����ָ��subhead��pred��mov��nextmov, �ֱ����ڼ�¼�Ӵ���ͷ��㡢����ָ���ǰ��������ָ�롢�����Ӵ������Ҫ�����Ľ��, ��ʼ��movΪlist->next���Ϊlist. ����ָ��submov, ��ʼΪsub->next. ��pred��movͬʱ�������������Ӵ�, ͬʱsubmov�����Ӵ�, mov��submovƥ��. ��ʧ��, ��subhead����һ��Ԫ��, ��subhead->next��ʼ���������Ӵ�; ��ƥ���Ӵ��ɹ�, ����ͷ�巨ԭ�������Ӵ�, Ȼ����Ӵ���ĵ�һ��Ԫ�ؿ�ʼ���������Ӵ�. 

	ʱ�临�Ӷ�O(mn), �ռ临�Ӷ�O(1); 
*/

#include <iostream>
#include "2_45.h"

void revSub(LinkedList<char>& list, LinkedList<char>& sub)
{
	if (list->next == nullptr || list->next->next == nullptr) {
		return;
	}
	if (sub->next == nullptr || sub->next->next == nullptr) {
		return;
	}

	LNode<char>* subhead = list; // header of sublist; 
	LNode<char>* pred = list; // pred of mov; 
	LNode<char>* mov = pred->next; // probe on list; 
	LNode<char>* submov = sub->next; // probe on sub; 
	LNode<char>* nextmov = list; // pivot for end of reverse; 

	while (mov != nullptr) {
		/* check sublist */
		submov = sub->next; // initialize submov; 
		while (submov != nullptr && mov->data == submov->data) { // sublist matched; 
			pred = pred->next; 
			mov = mov->next; 
			submov = submov->next; 
		}

		if (submov == nullptr) { // sublist detected; 
			nextmov = mov;
			pred = subhead->next;
			mov = pred->next;
			while (mov != nextmov) { // reverse; 
				pred->next = mov->next;
				mov->next = subhead->next;
				subhead->next = mov;

				mov = pred->next;
			}

			subhead = pred;
		}
		else {
			subhead = subhead->next; 
			pred = subhead; 
			mov = pred->next; 
		}

	}

	return; 
}