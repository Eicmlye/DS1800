#ifndef DS_6_47_H_
#define DS_6_47_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

BiTree buildPreInBiTree(int* preList, int* inList, size_t preHead, size_t preTail, size_t inHead, size_t inTail);



#endif