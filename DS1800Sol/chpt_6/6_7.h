#ifndef DS_6_7_H_
#define DS_6_7_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
} TreeNode, * BiTree;

BiTree buildBiTree(size_t level = 0); 

bool isComplete(BiTree tree); 

#endif