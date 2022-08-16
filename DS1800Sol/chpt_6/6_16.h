#ifndef DS_6_16_H_
#define DS_6_16_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
} TreeNode, * BiTree;

BiTree buildBiTree(size_t level = 1); 

TreeNode* ancestor(BiTree tree, TreeNode* p, TreeNode* q); 

#endif