#ifndef DS_6_8_H_
#define DS_6_8_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
} TreeNode, * BiTree;

BiTree buildComplTree(int* A, size_t n, size_t cur = 0); 

#endif