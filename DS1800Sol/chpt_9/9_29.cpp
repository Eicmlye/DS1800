#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "9_29.h"

AVLTree buildBST(void)
{
	std::cout << "A binary search tree (BST) is being built. " << std::endl;
	std::cout << "Enter data_ in the node after prompting, " << std::endl;
	std::cout << "or enter any non-digit character except whitespaces to exit. " << std::endl << std::endl;

	AVLTree result = nullptr;
	AVLNode* mov = nullptr;
	AVLNode* newNode = nullptr;
	AVLNode* tempLink = nullptr;
	int cache = 0;

	// fill in root;
	if (scanf("%d", &cache) == 1) {
		result = new AVLNode;
		result->data_ = cache;
	}
	else {
		return nullptr;
	}

	while (scanf("%d", &cache) == 1) {
		newNode = new AVLNode;
		newNode->data_ = cache;

		mov = result;
		while (mov->data_ != cache) {
			if (cache < mov->data_) {
				if (mov->lchild_ == nullptr) {
					mov->lchild_ = newNode;
				}
				mov = mov->lchild_;
			}
			else if (cache > mov->data_) {
				if (mov->rchild_ == nullptr) {
					mov->rchild_ = newNode;
				}
				mov = mov->rchild_;
			}
		}

		// Notice that mov->data_ == cache is not an appropriate condition here, 
		// because this will be satified in the end no matter cache is a new value or not; 
		// Better solution is to compare the address of leaf and newNode; 
		if (mov != newNode) {
			delete newNode; // omit values that already exist in the BST; 
		}
	}

	return result;
}

static int buildBalanceFactor_inbuild(AVLTree tree, int& heightCache)
{
	// Deal with empty tree;
	if (tree == nullptr) {
		return 0; 
	}

	// Now non-empty tree;
	// If leaf;
	if (tree->lchild_ == nullptr && tree->rchild_ == nullptr) {
		tree->bf_ = 0;
		heightCache = 1;
		return 0;
	}
	// Now non-leaf node;
	int hL = 0; 
	int hR = 0;
	int numL = buildBalanceFactor_inbuild(tree->lchild_, hL);
	int numR = buildBalanceFactor_inbuild(tree->rchild_, hR);
	tree->bf_ = hL - hR; 
	heightCache = (hL > hR) ? hL + 1 : hR + 1; 
	return numL + numR + 1; 
}

int buildBalanceFactor(AVLTree tree)
{
	int height = 0; 
	return buildBalanceFactor_inbuild(tree, height); 
}