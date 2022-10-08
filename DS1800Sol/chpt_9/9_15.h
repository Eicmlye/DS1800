#ifndef DS_9_15_H_
#define DS_9_15_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

BiTree buildBST(void);
bool delBSTNode(BiTree tree, int value);

#endif
