#ifndef DS_6_1_H_
#define DS_6_1_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	unsigned int weight = 0; 
	TreeNode* left = nullptr; 
	TreeNode* right = nullptr; 
} TreeNode, *BiTree;

unsigned int getWPL(BiTree tree, unsigned int WPL = 0, unsigned int level = 0); 

#endif