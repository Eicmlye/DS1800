#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "9_15.h"

BiTree buildBST(void)
{
	std::cout << "A binary search tree (BST) is being built. " << std::endl;
	std::cout << "Enter data in the node after prompting, " << std::endl;
	std::cout << "or enter any non-digit character except whitespaces to exit. " << std::endl << std::endl;

	BiTree result = nullptr;
	TreeNode* mov = nullptr;
	TreeNode* newNode = nullptr;
	TreeNode* tempLink = nullptr;
	int cache = 0;

	// fill in root;
	if (scanf("%d", &cache) == 1) {
		result = new TreeNode;
		result->data = cache;
	}
	else {
		return nullptr;
	}

	while (scanf("%d", &cache) == 1) {
		newNode = new TreeNode;
		newNode->data = cache;

		mov = result;
		while (mov->data != cache) {
			if (cache < mov->data) {
				if (mov->lchild == nullptr) {
					mov->lchild = newNode;
				}
				mov = mov->lchild;
			}
			else if (cache > mov->data) {
				if (mov->rchild == nullptr) {
					mov->rchild = newNode;
				}
				mov = mov->rchild;
			}
		}

		// Notice that mov->data == cache is not an appropriate condition here, 
		// because this will be satified in the end no matter cache is a new value or not; 
		// Better solution is to compare the address of leaf and newNode; 
		if (mov != newNode) {
			delete newNode;
		}
	}

	return result;
}

bool delBSTNode(BiTree tree, int value)
{
	if (tree == nullptr) {
		return false;
	}
	if (tree->data == value) {
		printf("This function cannot deal with root deleting. \n");
		return false;
	}

	// Now tree != nullptr;
	TreeNode* mov = tree;
	TreeNode* cache = tree; // temporary cache for parent; 
	// Find node with data value;
	while (mov != nullptr && mov->data != value) {
		cache = mov;
		mov = (mov->data > value ? mov->lchild : mov->rchild);
	}
	if (mov == nullptr) { // Target node not found;
		return false;
	}

	// Now mov->data == value;
	// Check children of mov and operate accordingly;
	if (mov->lchild == nullptr && mov->rchild == nullptr) {// leaf;
		// delete directly and done;
		if (cache->lchild == mov) {
			cache->lchild = nullptr;
		}
		else {
			cache->rchild = nullptr; 
		}

		delete mov;
	}
	// Now not both children are nullptr;
	else if (mov->lchild == nullptr) {// i.e. rchild != nullptr;
		if (cache->lchild == mov) {
			cache->lchild = mov->rchild;
		}
		else {
			cache->rchild = mov->rchild;
		}

		delete mov;
	}
	else if (mov->rchild == nullptr) {// i.e. lchild != nullptr;
		if (cache->lchild == mov) {
			cache->lchild = mov->lchild;
		}
		else {
			cache->rchild = mov->lchild;
		}

		delete mov;
	}
	// Now neither of its children is nullptr;
	// Copy the value of inorder-successor of mov to mov's place;
	// Then delete this inorder-successor; 
	else {
		// Find inorder-successor;
		cache = mov->rchild; 
		while (cache->lchild != nullptr) {
			cache = cache->lchild;
		}
		// Do not update mov->data here,
		// since delBSTNode(mov, cache->data) have to find the successor by value;
		int temp = cache->data;
		delBSTNode(mov, cache->data);

		// Now update mov->data;
		mov->data = temp; 
	}

	return true; 
}
