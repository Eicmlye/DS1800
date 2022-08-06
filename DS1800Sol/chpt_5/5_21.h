#ifndef DS_5_21_H_
#define DS_5_21_H_

#include "chpt_tag.h"

struct MatNode {
	size_t row; 
	size_t col; 
	int data; 
	MatNode* next; 
};

struct Matrix {
	MatNode* head; 
};

void fastTSpMat(Matrix mat); 

#endif