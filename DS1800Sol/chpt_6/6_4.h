#ifndef DS_6_4_H_
#define DS_6_4_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	unsigned int data = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
} TreeNode, * BiTree;

size_t* countNodeDeg(BiTree tree); 

#endif