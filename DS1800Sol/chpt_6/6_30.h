#ifndef DS_6_30_H_
#define DS_6_30_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	TreeNode* parent = nullptr; 
	TreeNode* lchild = nullptr; 
	TreeNode* rchild = nullptr; 
	int data = 0; 
} TreeNode, *BiTree;

BiTree buildBiTree(size_t level = 1); 

void preOrdTrav(BiTree tree); 

#endif