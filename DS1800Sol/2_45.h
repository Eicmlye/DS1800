#ifndef DS_2_45_H_
#define DS_2_45_H_

typedef struct LNode {
	char data;
	LNode* next;

	LNode() : data('\0'), next(nullptr) {};
	LNode(char val) : data(val), next(nullptr) {};
	LNode(char val, LNode* p) : data(val), next(p) {};
} LNode, * LinkedList;

void revSub(LinkedList& list, LinkedList& sub); 

#endif