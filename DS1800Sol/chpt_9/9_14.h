#ifndef DS_9_14_H_
#define DS_9_14_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

BiTree buildBST(void);
bool isBST(BiTree tree); 
void fwriteDescend(BiTree tree, const char filename[] = "tree.txt");

#endif
