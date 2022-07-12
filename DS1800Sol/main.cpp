#include <iostream>
#include "chpt_3/chpt_tag.h"
#include "chpt_3/3_10.h"

using std::cout;
using std::endl;

#ifdef DS_LINKEDLIST_H_

#include <vector>
using std::vector;

template <typename DataType, typename ListNodeType>
static ListNodeType* createSingleList(vector<DataType> initData, bool hasHead = true, bool isCyclic = false);

template <typename DataType, typename ListNodeType>
static ListNodeType* createDoubleList(vector<DataType> initData, bool hasHead = true, bool isCyclic = false);
#endif

int main(void)
{
	#ifdef DS_2_H_
		#ifdef DS_2_1_H_
			LNode<int> end = { 3, nullptr };
			LNode<int> node = { 2, &end };
			LNode<int> list = { 0, &node };
			if (findInvK(&list, 2) == 0) {
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
			LinkedList<int> head = createSingleList<int, LNode<int>>({ 10, 19, -15, 1, 15, 19, -10, 2, 5, 15 });

			delDup(head, 20);

			LNode<int>* mov = head->next;
			while (mov != nullptr) {
				cout << mov->data << ' ';
				mov = mov->next;
			}
			cout << endl;
		#endif
		#ifdef DS_2_6_H_
			LinkedList<int> A = createSingleList<int, LNode<int>>({ 1, 3, 5, 6, 8, 10 });

			LinkedList<int> B = createSingleList<int, LNode<int>>({ 2, 4, 7, 9 });

			LinkedList<int> C = reverseMerge(A, B);
			LNode<int>* mov = C->next;
			while (mov != nullptr) {
				cout << mov->data << ' ';
				mov = mov->next;
			}
			cout << endl;
		#endif
		#ifdef DS_2_10_H_
			LinkedList<int> A = createSingleList<int, LNode<int>>({ 1, 3, 5, 6, 8, 10, 11 });

			LinkedList<int> B = createSingleList<int, LNode<int>>({ 2, 5, 7, 10 });

			LinkedList<int> C = unionSet(A, B);
			LNode<int>* mov = C->next;
			while (mov != nullptr) {
				cout << mov->data << ' ';
				mov = mov->next;
			}
			cout << endl;
		#endif
		#ifdef DS_2_16_H_
			LinkedList<int> A = createSingleList<int, LNode<int>>({ 1, 3, 5, 6, 8, 10, 11 }, true, true);

			LinkedList<int> B = createSingleList<int, LNode<int>>({ 2, 5, 7, 10 }, true, true);

			LinkedList<int> list = mergeList(A, 7, B, 4);
			LNode<int>* mov = list->next;
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
			LinkedList<char> A = createSingleList<char, LNode<char>>({ 'a', 'b', 'c', 'a', 'b', 'a', 'b', 'c', 'b', 'c' });

			LinkedList<char> B = createSingleList<char, LNode<char>>({ 'a', 'b', 'c' });

			revSub(A, B);

			LNode<char>* mov = A->next;
			while (mov != nullptr) {
				cout << mov->data << ' ';
				mov = mov->next;
			}
			cout << endl;
		#endif
		#ifdef DS_2_51_H_
			#define APPEND(elem) \
				do {\
					temp = new LNode<int>(elem); \
					rear->next = temp; \
					rear = temp; \
				} while (0)

			LinkedList<int> A = new LNode<int>;
			LNode<int>* rear = A;
			LNode<int>* temp;

			APPEND(1);
			APPEND(3);
			APPEND(5);
			APPEND(6);
			APPEND(8);
			APPEND(10);
			APPEND(11);
			rear->next = A->next;

			revCyc(A, 0);

			LNode<int>* mov = A->next;
			while (mov->next != A->next) {
				cout << mov->data << ' ';
				mov = mov->next;
			}
			cout << mov->data << endl;
		#endif
		#ifdef DS_2_52_H_
			LinkedList<int> A = createSingleList<int, LNode<int>>({ 1, 3, 5, 6, 8, 10, 11 }, true, true);

			LNode<int>* rear = A->next;
			while (rear->next != A) {
				rear = rear->next;
			}

			doubleRev(A, rear);

			LNode<int>* mov = A->next;
			while (mov != A) {
				cout << mov->data << ' ';
				mov = mov->next;
			}
			cout << endl;
		#endif 
		#ifdef DS_2_53_H_
			LinkedList<int> A = createSingleList<int, LNode<int>>({ 1, 3, 5, 6, 8, 10, 11 }, false);

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

			DFList<int> L = createDoubleList<int, DFNode<int>>({ 1, 3, 5, 6, 8, 10, 11 }, true, false);
			DFNode<int>* mov = nullptr;
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
		#ifdef DS_2_65_H_
			DList<bool> binum = createBinum();
			incBinum(binum);
		#endif
	#endif

	#ifdef DS_3_H_
		#ifdef DS_3_1_H_
			#define PRINTSTK(stk) \
				do {\
					cout << "--------" << endl << "Front stack: "; \
					for (size_t index = 0; index < stk.topHead; ++index) {\
						cout << stk.head[index]; \
					}\
					cout << endl << "Back Stack: "; \
					\
					for (size_t index = stk.maxsize; index > stk.topTail; --index) {\
						cout << stk.head[index - 1]; \
					}\
					cout << endl << "cache = " << cache << endl; \
					cout << "--------" << endl; \
				} while (0)

			SeqStk stk(8); 
			int cache = -1;
			PRINTSTK(stk); 

			pushStk(stk, 0, 0);
			pushStk(stk, 0, 1);
			pushStk(stk, 0, 2);
			pushStk(stk, 0, 3);

			pushStk(stk, 1, 8);
			pushStk(stk, 1, 7);
			pushStk(stk, 1, 6);

			PRINTSTK(stk); 

			popStk(stk, 0, cache);
			popStk(stk, 0, cache);
			popStk(stk, 0, cache);

			PRINTSTK(stk);

			popStk(stk, 1, cache);
			popStk(stk, 2, cache);

			PRINTSTK(stk);
		#endif
		#ifdef DS_3_3_H_
			cout << (int)EXYX("(nafor(-d65231)d.v;[eo() )am;e'g(24)#") << endl;
			cout << (int)EXYX("(nafor(-d65231)d.v;[eo() )am;e'g(241#") << endl;
			cout << (int)EXYX("nafor-d65231)d.v;[eo() )am;e'g(2411)#") << endl;
		#endif
		#ifdef DS_3_6_H_
			size_t n = 7; 
			int* arr = (int*)malloc(n * sizeof(int)); 
			int sample[] = {0, 5, 62, -29, 159, 30, 7};
			if (arr != nullptr) {
				for (size_t index = 0; index < n; ++index) {
					arr[index] = sample[index];
				}
			}

			cout << findMax(arr, n) << endl; 
		#endif
		#ifdef DS_3_8_H_
			cout << Euclid(24, 30) << endl;
			cout << recEuclid(24, 30) << endl;
		#endif
		#ifdef DS_3_9_H_
			cout << Ack(3, 3) << ", "; 
			cout << recAck(3, 3) << endl;
		#endif
		#ifdef DS_3_10_H_
			size_t k = 3; 
			size_t* arr = new size_t[k];
			recPrintCombination(1, 5, k, arr, 0);
			cout << "--------" << endl; 
			printCombination(5, 3); 
		#endif
	#endif

	return 0;
}

#if defined DS_LINKEDLIST_H_
	template <typename DataType, typename ListNodeType>
	static ListNodeType* createSingleList(vector<DataType> initData, bool hasHead, bool isCyclic)
{
	ListNodeType* list = new ListNodeType;
	ListNodeType* newNode = nullptr;

	if (!hasHead) {
		list->data = initData.at(0);
	}
	if (isCyclic) {
		list->next = list;
	}

	for (size_t index = 0; index < ((hasHead) ? initData.size() : initData.size() - 1); ++index) {
		newNode = new ListNodeType(initData.at(initData.size() - 1 - index), list->next);
		list->next = newNode;
	}

	return list;
}

	template <typename DataType, typename ListNodeType>
	static ListNodeType* createDoubleList(vector<DataType> initData, bool hasHead, bool isCyclic)
{
	ListNodeType* list = new ListNodeType;
	ListNodeType* newNode = nullptr;

	if (!hasHead) {
		list->data = initData.at(0);
	}
	if (isCyclic) {
		list->next = list;
		list->pred = list;
	}

	for (size_t index = 0; index < ((hasHead) ? initData.size() : initData.size() - 1); ++index) {
		newNode = new ListNodeType(initData.at(initData.size() - 1 - index), list->next);
		list->next = newNode;
		newNode->pred = list;
		if (newNode->next != nullptr) {
			newNode->next->pred = newNode;
		}
	}

	return list;
}
#endif