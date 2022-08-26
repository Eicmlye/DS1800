#ifndef DS_6_53_H_
#define DS_6_53_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

BiTree buildBiTree(size_t level = 1);

BiTree recCopyBiTree(BiTree src);

BiTree copyBiTree(BiTree src);

#endif