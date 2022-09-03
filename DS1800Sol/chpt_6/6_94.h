#ifndef DS_6_94_H_
#define DS_6_94_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

typedef struct ThreadTNode {
	int data = 0;
	bool ltag = false; // true if child is a thread;
	bool rtag = false; // true if child is a thread;
	ThreadTNode* lchild = nullptr;
	ThreadTNode* rchild = nullptr;
} ThreadTNode, * ThreadBTree;

BiTree buildBST(void); 

ThreadBTree buildInOrdThread(BiTree src);

#endif