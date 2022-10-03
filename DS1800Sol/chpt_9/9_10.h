#ifndef DS_9_10_H_
#define DS_9_10_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

BiTree buildBiTree(size_t level = 1); 
bool isBST(BiTree tree);

#endif
