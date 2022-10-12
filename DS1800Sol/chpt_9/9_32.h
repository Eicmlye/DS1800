#ifndef DS_9_32_H_
#define DS_9_32_H_

#include "chpt_tag.h"

typedef struct AVLNode {
	int bf_ = 0;
	size_t lsize_ = 0;
	int data_ = 0;
	AVLNode* lchild_ = nullptr;
	AVLNode* rchild_ = nullptr;
} AVLNode, * AVLTree;

AVLTree buildAVL(void);
size_t buildLSize(AVLTree tree);
int getKthNode(AVLTree tree, size_t k);

#endif
