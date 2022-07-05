#ifndef DS_2_5_H_
#define DS_2_5_H_

typedef struct LNode {
	int data = 0; 
	LNode* link = nullptr; 
} LNode, *LinkedList;

void delDup(LinkedList head, size_t n); 

#endif