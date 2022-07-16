#ifndef DS_3_1_H_
#define DS_3_1_H_

#include "chpt_tag.h"

struct SeqStk {
	int* head;
	size_t maxsize;
	size_t topHead;
	size_t topTail;

	SeqStk(size_t size) : maxsize(size), topHead(0), topTail(size) { head = (int*)malloc(size * sizeof(int)); };
};

bool pushStk(SeqStk& stk, bool mode, int val); 
bool popStk(SeqStk& stk, bool mode, int& cache); 

#endif 