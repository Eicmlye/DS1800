#ifndef DS_6_55_H_
#define DS_6_55_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

BiTree buildBiTree(size_t level = 1);

void connectLeaves(BiTree tree); 

#endif