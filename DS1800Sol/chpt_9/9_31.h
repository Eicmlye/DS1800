#ifndef DS_9_31_H_
#define DS_9_31_H_

#include "chpt_tag.h"

typedef struct AVLNode {
	int bf_ = 0;
	int data_ = 0;
	AVLNode* lchild_ = nullptr;
	AVLNode* rchild_ = nullptr;
} AVLNode, * AVLTree;

AVLTree buildAVL(void);
int getHeight(AVLTree tree);
#endif
