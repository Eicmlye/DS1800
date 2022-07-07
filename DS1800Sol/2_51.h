#ifndef DS_2_51_H_
#define DS_2_51_H_

typedef struct LNode {
	int data;
	LNode* next;

	LNode() : data(0), next(nullptr) {};
	LNode(int val) : data(val), next(nullptr) {};
	LNode(int val, LNode* p) : data(val), next(p) {};
} LNode, * LinkedList;

void revCyc(LinkedList& list, unsigned int mode = 0);

#endif