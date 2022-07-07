#ifndef DS_2_63_H_
#define DS_2_63_H_

typedef struct DNode {
	unsigned int freq; 
	int data;
	DNode* next;
	DNode* pred; 

	DNode() : freq(0), data(0), next(nullptr), pred(nullptr) {};
	DNode(int val) : freq(0), data(val), next(nullptr), pred(nullptr) {};
	DNode(int val, DNode* p, DNode* q) : freq(0), data(val), next(p), pred(q) {};
} DNode, * DList;

DNode* find(DList& L, int x); 

#endif