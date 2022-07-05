#ifndef DS_2_6_H_
#define DS_2_6_H_

typedef struct LNode {
	int data; 
	LNode* next; 

	LNode() : data(0), next(nullptr) {}; 
	LNode(int val) : data(val), next(nullptr) {}; 
	LNode(int val, LNode* p) : data(val), next(p) {}; 
} LNode, *LinkedList;

LinkedList reverseMerge(LinkedList A, LinkedList B);

#endif