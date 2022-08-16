#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_16.h"

BiTree buildBiTree(size_t level)
{
	if (level == 1) {
		std::cout << "A binary tree is being built. " << std::endl;
		std::cout << "Enter data in the node after prompting, " << std::endl;
		std::cout << "or enter any non-digit character for empty node. " << std::endl;
		std::cout << "Root of tree: ";
	}

	TreeNode* node = new TreeNode;
	if (scanf("%d", &(node->data)) == 1) {
		for (size_t index = 0; index < level; ++index) {
			std::cout << "    ";
		}
		std::cout << "Lchild of " << node->data << ": ";
		node->left = buildBiTree(level + 1);
		for (size_t index = 0; index < level; ++index) {
			std::cout << "    ";
		}
		std::cout << "Rchild of " << node->data << ": ";
		node->right = buildBiTree(level + 1);
		return node;
	}
	else {
		while (getchar() != '\n') {
			continue;
		}
		std::cout << "\r\033[1A\033[K";
		return nullptr;
	}
}

TreeNode* ancestor(BiTree tree, TreeNode* p, TreeNode* q)
{
	typedef struct stackNode {
		TreeNode* tnode = nullptr; 
		stackNode* next; 
	} stackNode, *stack;

	stack stk = new stackNode; // header of stk; 
	TreeNode* rtag = nullptr; 
	TreeNode* mov = tree; 

	while (stk->next != nullptr || mov != nullptr) {

	}

	return nullptr; 
}