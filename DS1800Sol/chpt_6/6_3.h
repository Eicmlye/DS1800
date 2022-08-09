#ifndef DS_6_3_H_
#define DS_6_3_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	char data = '\0';
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
} TreeNode, * BiTree;

void showExpr(BiTree expr); 

#endif