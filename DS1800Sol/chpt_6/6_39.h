#ifndef DS_6_39_H_
#define DS_6_39_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	int data = 0;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
} TreeNode, * BiTree;

BiTree buildBiTree(size_t level = 1);

BiTree buildNormalBiTree(int* preList, int* postList, size_t preHead, size_t preTail, size_t postHead, size_t postTail); 

#endif