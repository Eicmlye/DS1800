#ifndef DS_9_29_H_
#define DS_9_29_H_

#include "chpt_tag.h"

typedef struct AVLNode {
	int data_ = 0;
	AVLNode* lchild_ = nullptr;
	AVLNode* rchild_ = nullptr;
	int bf_ = 0;
} AVLNode, *AVLTree;

AVLTree buildBST(void); 

// Return number of non-leaf; 
// Update balance factor of all nodes of tree; 
int buildBalanceFactor(AVLTree tree); 

#endif