#include <iostream>
#include "2_45.h"

using std::cout; 
using std::endl; 

int main(void)
{
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
	#define APPEND_NUM(num) \
	do {\
		temp = new LNode; \
		temp->data = num; \
		rear->link = temp; \
		rear = temp; \
	} while (0)

	LinkedList head = new LNode;
	LNode* rear = head; 
	LNode* temp;

	APPEND_NUM(10);
	APPEND_NUM(19);
	APPEND_NUM(-15);
	APPEND_NUM(1);
	APPEND_NUM(15);
	APPEND_NUM(19);
	APPEND_NUM(-10);
	APPEND_NUM(2);
	APPEND_NUM(5);
	APPEND_NUM(15);

	delDup(head, 20); 

	LNode* mov = head->link; 
	while (mov != nullptr) {
		cout << mov->data << ' '; 
		mov = mov->link; 
	}
	cout << endl; 
#endif
#ifdef DS_2_6_H_
#define APPEND_NUM(num) \
	do {\
		temp = new LNode(num); \
		rear->next = temp; \
		rear = temp; \
	} while (0)

	LinkedList A = new LNode;
	LNode* rear = A;
	LNode* temp;

	APPEND_NUM(1);
	APPEND_NUM(3);
	APPEND_NUM(5);
	APPEND_NUM(6);
	APPEND_NUM(8);
	APPEND_NUM(10);

	LinkedList B = new LNode;
	rear = B;

	APPEND_NUM(2);
	APPEND_NUM(4);
	APPEND_NUM(7);
	APPEND_NUM(9);

	LinkedList C = reverseMerge(A, B);
	LNode* mov = C->next;
	while (mov != nullptr) {
		cout << mov->data << ' ';
		mov = mov->next;
	}
	cout << endl;
#endif
#ifdef DS_2_10_H_
#define APPEND_NUM(num) \
	do {\
		temp = new LNode(num); \
		rear->next = temp; \
		rear = temp; \
	} while (0)

	LinkedList A = new LNode;
	LNode* rear = A;
	LNode* temp;

	APPEND_NUM(1);
	APPEND_NUM(3);
	APPEND_NUM(5);
	APPEND_NUM(6);
	APPEND_NUM(8);
	APPEND_NUM(10);
	APPEND_NUM(11);

	LinkedList B = new LNode;
	rear = B;

	APPEND_NUM(2);
	APPEND_NUM(5);
	APPEND_NUM(7);
	APPEND_NUM(10);

	LinkedList C = unionSet(A, B);
	LNode* mov = C->next;
	while (mov != nullptr) {
		cout << mov->data << ' ';
		mov = mov->next;
	}
	cout << endl;
#endif
#ifdef DS_2_16_H_
	#define APPEND_NUM(num) \
	do {\
		temp = new LNode(num); \
		rear->next = temp; \
		rear = temp; \
	} while (0)

	LinkedList A = new LNode;
	LNode* rear = A;
	LNode* temp;

	APPEND_NUM(1);
	APPEND_NUM(3);
	APPEND_NUM(5);
	APPEND_NUM(6);
	APPEND_NUM(8);
	APPEND_NUM(10);
	APPEND_NUM(11);
	rear->next = A; 

	LinkedList B = new LNode;
	rear = B;

	APPEND_NUM(2);
	APPEND_NUM(5);
	APPEND_NUM(7);
	APPEND_NUM(10);
	rear->next = B; 

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
	#define APPEND_CHAR(ch) \
	do {\
		temp = new LNode(ch); \
		rear->next = temp; \
		rear = temp; \
	} while (0)

	LinkedList A = new LNode;
	LNode* rear = A;
	LNode* temp;

	APPEND_CHAR('a');
	APPEND_CHAR('b');
	APPEND_CHAR('c');
	APPEND_CHAR('a');
	APPEND_CHAR('b');
	APPEND_CHAR('a');
	APPEND_CHAR('b');
	APPEND_CHAR('c');
	APPEND_CHAR('b');
	APPEND_CHAR('c');

	LinkedList B = new LNode;
	rear = B;

	APPEND_CHAR('a');
	APPEND_CHAR('b');
	APPEND_CHAR('c');

	revSub(A, B); 

	LNode* mov = A->next; 
	while (mov != nullptr) {
		cout << mov->data << ' '; 
		mov = mov->next; 
	}
	cout << endl; 
#endif
	
	return 0; 
}