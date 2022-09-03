#ifndef DS_6_97_H_
#define DS_6_97_H_

#include "chpt_tag.h"

typedef struct TreeNode {
	struct {
		char name[21] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
		int size = 0;
	} data;
	TreeNode* lchild = nullptr;
	TreeNode* rchild = nullptr;
} TreeNode, * BiTree;

BiTree buildBiTree(size_t level = 1);

size_t printCatalog(BiTree catalog);

#endif