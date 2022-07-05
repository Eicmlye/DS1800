#ifndef DS_2_16_H_
#define DS_2_16_H_

typedef struct LNode {
	int data;
	LNode* next;

	LNode() : data(0), next(nullptr) {};
	LNode(int val) : data(val), next(nullptr) {};
	LNode(int val, LNode* p) : data(val), next(p) {};
} LNode, * LinkedList;

LinkedList mergeList(LinkedList L1, size_t m, LinkedList L2, size_t n); 

#endif