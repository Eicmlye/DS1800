#ifndef DS_2_1_H_
#define DS_2_1_H_

typedef struct LNode {
	int data = 0; 
	LNode* link = nullptr; 
} LNode, *LinkedList;

int findInvK(LinkedList list, size_t k); 

#endif