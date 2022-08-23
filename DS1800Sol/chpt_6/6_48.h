#ifndef DS_6_48_H_
#define DS_6_48_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0; 
	TreeNode* lchild = nullptr; 
	TreeNode* rchild = nullptr; 
} TreeNode, * BiTree;

BiTree buildBiTree(size_t& saveNodeNum, size_t level = 1);

void preOrdTrav(BiTree tree, int* pre);

void inOrdTrav(BiTree tree, int* in);

BiTree buildPreInBiTree(int* preList, int* inList, size_t n); 

#endif