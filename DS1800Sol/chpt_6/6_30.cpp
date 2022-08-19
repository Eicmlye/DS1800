#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_30.h"

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
		node->lchild = buildBiTree(level + 1);
		for (size_t index = 0; index < level; ++index) {
			std::cout << "    ";
		}
		std::cout << "Rchild of " << node->data << ": ";
		node->rchild = buildBiTree(level + 1);
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

void preOrdTrav(BiTree tree)
{
	if (tree == nullptr) {
		return; 
	}

	TreeNode* mov = tree; 
	TreeNode* pred = new TreeNode; // header indicating empty stack; 
	while (mov != tree->parent) {
		while (mov != nullptr) {
			/* visit node */
			std::cout << mov->data << ' ';

			mov->parent = pred; 
			pred = mov; 
			mov = mov->lchild; 
		}
		
		// now mov == nullptr; 
		mov = pred; 
		pred = pred->parent; 
		while (mov != tree->parent && (mov->rchild == nullptr || mov->rchild->parent != nullptr)) { // non-null parent indicates that the node has been visited; 
			mov = mov->parent; 
			pred = pred->parent; 
		}
		if (mov == tree->parent) {
			break; 
		}
		pred = mov; 
		mov = mov->rchild; 
	}

	delete tree->parent; 
	tree->parent = nullptr; 

	return; 
}