#include <iostream>
#include <vector>
#include "2_63.h"

using std::cout; 
using std::endl; 
using std::vector; 

#ifndef DS_2_
#define DS_2_

#if 0
	#define LLIST
	template <typename DataType>
	static LinkedList createList(vector<DataType> initData, bool hasHead = true, bool isCyclic = false); 
#endif
#if 1
	#define DLIST
	template <typename DataType>
	static DList createList(vector<DataType> initData); 
#endif

#endif

int main(void)
{
#ifdef DS_2_
	#define APPEND(elem) \
		do {\
			temp = new LNode(elem); \
			rear->next = temp; \
			rear = temp; \
		} while (0)

	#ifdef DS_2_1_H_
		LNode end = { 3, nullptr }; 
		LNode node = { 2, &end }; 
		LNode list = { 0, &node };
		if (findInvK(&list, 3) == 0) {
			cout << "Target not found. " << endl; 
		}
	#endif
	#ifdef DS_2_2_H_
		int arr[10] = { 0,1,2,3,4,5,6,7,8,9 }; 
		moveBack(arr, 10, 3); 

		size_t index = 0; 
		while (index < 10) {
			cout << arr[index] << ' '; 
			++index; 
		}
		cout << endl; 
	#endif
	#ifdef DS_2_3_H_
		int A[5] = { 0,2,5,6,7 }; 
		int B[5] = { 1,3,4,8,9 }; 
		cout << findMid(A, B, 5) << endl; 
	#endif
	#ifdef DS_2_4_H_
		#define APPEND_LETTER(ch) \
		do {\
			temp = new Letter; \
			temp->data = ch; \
			rear->next = temp; \
			rear = temp; \
		} while (0)

		Word str1 = new Letter; 
		Letter* rear = str1; 
		Letter* target; 
		Letter* temp; 

		APPEND_LETTER('b'); 
		APPEND_LETTER('e'); 
		APPEND_LETTER('i'); 
		target = rear; 
		APPEND_LETTER('n'); 
		APPEND_LETTER('g'); 

		Word str2 = new Letter; 
		rear = str2;

		APPEND_LETTER('c');
		APPEND_LETTER('o');
		APPEND_LETTER('m');

		rear->next = target; 

		cout << getIntersect(str1, str2)->data << endl; 

	#endif
	#ifdef DS_2_5_H_
		LinkedList head = new LNode;
		LNode* rear = head; 
		LNode* temp;

		APPEND(10);
		APPEND(19);
		APPEND(-15);
		APPEND(1);
		APPEND(15);
		APPEND(19);
		APPEND(-10);
		APPEND(2);
		APPEND(5);
		APPEND(15);

		delDup(head, 20); 

		LNode* mov = head->link; 
		while (mov != nullptr) {
			cout << mov->data << ' '; 
			mov = mov->link; 
		}
		cout << endl; 
	#endif
	#ifdef DS_2_6_H_
		LinkedList A = new LNode;
		LNode* rear = A;
		LNode* temp;

		APPEND(1);
		APPEND(3);
		APPEND(5);
		APPEND(6);
		APPEND(8);
		APPEND(10);

		LinkedList B = new LNode;
		rear = B;

		APPEND(2);
		APPEND(4);
		APPEND(7);
		APPEND(9);

		LinkedList C = reverseMerge(A, B);
		LNode* mov = C->next;
		while (mov != nullptr) {
			cout << mov->data << ' ';
			mov = mov->next;
		}
		cout << endl;
	#endif
	#ifdef DS_2_10_H_
		LinkedList A = new LNode;
		LNode* rear = A;
		LNode* temp;

		APPEND(1);
		APPEND(3);
		APPEND(5);
		APPEND(6);
		APPEND(8);
		APPEND(10);
		APPEND(11);

		LinkedList B = new LNode;
		rear = B;

		APPEND(2);
		APPEND(5);
		APPEND(7);
		APPEND(10);

		LinkedList C = unionSet(A, B);
		LNode* mov = C->next;
		while (mov != nullptr) {
			cout << mov->data << ' ';
			mov = mov->next;
		}
		cout << endl;
	#endif
	#ifdef DS_2_16_H_
		LinkedList A = createList<int>({ 1, 3, 5, 6, 8, 10, 11 }, true, true); 

		LinkedList B = createList<int>({ 2, 5, 7, 10 }, true, true); 

		LinkedList list = mergeList(A, 7, B, 4); 
		LNode* mov = list->next; 
		while (mov != list) {
			cout << mov->data << ' '; 
			mov = mov->next; 
		}
		cout << endl; 
	#endif
	#ifdef DS_2_20_H_
		int arr[5] = { -1, 5, 9, -10, 3 }; 
		partition(arr, 5); 
		for (size_t index = 0; index < 5; ++index) {
			cout << arr[index] << ' '; 
		}
		cout << endl; 
	#endif
	#ifdef DS_2_22_H_
		int* arr = (int*)malloc(10 * sizeof(int));
		arr[0] = -5; 
		arr[1] = 0; 
		arr[2] = 2; 
		arr[3] = 7; 
		arr[4] = 19; 
		insert(arr, 5, 4); 
		for (size_t index = 0; index < 6; ++index) {
			cout << arr[index] << ' '; 
		}
		cout << endl; 
	#endif
	#ifdef DS_2_24_H_
		size_t size = 12; 
		int arr[12] = { -2, 0, 3, 5, 11, 9, 3, 20, 3, 6, -5, -8 }; 
		delItem(arr, size, 3); 
		for (size_t index = 0; index < size; ++index) {
			cout << arr[index] << ' '; 
		}
		cout << endl; 
	#endif
	#ifdef DS_2_45_H_
		LinkedList A = createList<char>({ 'a', 'b', 'c', 'a', 'b', 'a', 'b', 'c', 'b', 'c' }); 

		LinkedList B = createList<char>({ 'a', 'b', 'c' }); 

		revSub(A, B); 

		LNode* mov = A->next; 
		while (mov != nullptr) {
			cout << mov->data << ' '; 
			mov = mov->next; 
		}
		cout << endl; 
	#endif
	#ifdef DS_2_51_H_
		LinkedList A = new LNode;
		LNode* rear = A;
		LNode* temp;

		APPEND(1);
		APPEND(3);
		APPEND(5);
		APPEND(6);
		APPEND(8);
		APPEND(10);
		APPEND(11);
		rear->next = A->next; 

		revCyc(A, 0); 

		LNode* mov = A->next; 
		while (mov->next != A->next) {
			cout << mov->data << ' '; 
			mov = mov->next; 
		}
		cout << mov->data << endl; 
	#endif
	#ifdef DS_2_52_H_
		LinkedList A = createList<int>({ 1, 3, 5, 6, 8, 10, 11 }, true, true);

		LNode* rear = A->next; 
		while (rear->next != A) {
			rear = rear->next; 
		}

		doubleRev(A, rear); 

		LNode* mov = A->next;
		while (mov != A) {
			cout << mov->data << ' ';
			mov = mov->next;
		}
		cout << endl;
	#endif 
	#ifdef DS_2_53_H_
		LinkedList A = createList<int>({ 1, 3, 5, 6, 8, 10, 11 }, false);

		printInv(A); 
	#endif
	#ifdef DS_2_63_H_
		#define PRINT(L) \
			do {\
				mov = L->next; \
				while (mov != nullptr) {\
					cout << mov->data << ", freq = " << mov->freq << endl; \
					mov = mov->next; \
				}\
				\
				cout << endl; \
			} while (0)
		#define FIND(L, x) \
			do {\
				cout << x << " is at " << find(L, x) << endl;\
				PRINT(L); \
			} while (0)

		DList L = createList<int>({ 1,3,5,6,8,10,11 }); 
		DNode* mov = nullptr; 
		PRINT(L); 

		FIND(L, 8);
		FIND(L, 8);
		FIND(L, 11);
		FIND(L, 11);
		FIND(L, 11);
		FIND(L, 10);
		FIND(L, 6);
		FIND(L, 5);
		FIND(L, 3);
		FIND(L, 1);
		FIND(L, 11);
		FIND(L, 1);
	#endif
#endif

	return 0; 
}

#if defined DS_2_ 
	#if defined LLIST
	template <typename DataType>
	static LinkedList createList(vector<DataType> initData, bool hasHead, bool isCyclic)
	{
		LinkedList list = new LNode; 
		LNode* newNode = nullptr; 

		if (!hasHead) {
			list->data = initData.at(0); 
		}
		if (isCyclic) {
			list->next = list; 
		}

		for (size_t index = 0; index < ((hasHead) ? initData.size() : initData.size() - 1); ++index) {
			newNode = new LNode(initData.at(initData.size() - 1 - index), list->next);
			list->next = newNode; 
		}

		return list; 
	}
	#endif
	#if defined DLIST
	template <typename DataType>
	static DList createList(vector<DataType> initData)
	{
		DList list = new DNode;
		DNode* newNode = nullptr;

		for (size_t index = 0; index < initData.size(); ++index) {
			newNode = new DNode(initData.at(initData.size() - 1 - index), list->next, list);
			if (list->next != nullptr) {
				list->next->pred = newNode;
			}
			list->next = newNode; 
		}

		return list;
	}
	#endif
#endif