#ifndef DS_6_93_H_
#define DS_6_93_H_

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

BiTree buildBiTree(size_t level = 1); 

ThreadBTree buildInOrdThread(BiTree src); 

void postOrdTrav(ThreadBTree threadTree); 

#endif