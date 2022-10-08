#ifndef DS_9_31_H_
#define DS_9_31_H_

#include "chpt_tag.h"

typedef struct AVLNode {
	int data_ = 0;
	AVLNode* lchild_ = nullptr;
	AVLNode* rchild_ = nullptr;
	int bf_ = 0;
} AVLNode, * AVLTree;

AVLTree buildAVL(void); 

#endif
