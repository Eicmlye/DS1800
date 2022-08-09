#ifndef DS_6_2_H_
#define DS_6_2_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	char data = '\0';
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
} TreeNode, * BiTree;

int calculate(BiTree expr); 

#endif