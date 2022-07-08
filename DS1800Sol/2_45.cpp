/*
	定义指针subhead、pred、mov、nextmov, 分别用于记录子串的头结点、遍历指针的前驱、遍历指针、逆置子串后继续要遍历的结点, 初始除mov为list->next外均为list. 定义指针submov, 初始为sub->next. 让pred和mov同时遍历主串搜索子串, 同时submov遍历子串, mov与submov匹配. 若失配, 则将subhead后移一个元素, 从subhead->next开始重新搜索子串; 若匹配子串成功, 则用头插法原地逆置子串, 然后从子串后的第一个元素开始继续搜索子串. 

	时间复杂度O(mn), 空间复杂度O(1); 
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