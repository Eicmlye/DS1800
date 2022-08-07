#ifndef DS_5_21_H_
#define DS_5_21_H_

#include "chpt_tag.h"

struct MatNode {
	size_t row_ = 0;
	size_t col_ = 0;
	int data_ = 0;
};

using Matrix = MatNode*; // no header node; 

Matrix fastTSpMat(Matrix mat, size_t n, size_t t); 

#endif