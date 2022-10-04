#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "9_14.h"

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

static bool isBST_buildin(BiTree tree, int& maxElem)
{
	// For empty tree, return true; 
	if (tree == nullptr) {
		maxElem = INT_MIN;
		return true;
	}

	// Now tree != nullptr; 
	bool result = true;
	// If lchild tree exists; 
	if (tree->lchild != nullptr) {
		// If lchild tree is not BST, return false; 
		if (!(result = isBST_buildin(tree->lchild, maxElem))) {
			return result;
		}
		// Now lchild tree is BST; 
		// Now maxElem is the max element of lchild tree; 
		// If cur node data is not greater than max data of lchild tree, return false; 
		if (!(result = tree->data > maxElem)) {
			return result;
		}
	}
	else {
		maxElem = tree->data;
	}
	// If rchild tree exists; 
	if (tree->rchild != nullptr) {
		// If rchild tree is not BST, return false; 
		if (!(result = isBST_buildin(tree->rchild, maxElem))) {
			return result;
		}
		// Now rchild tree is BST; 
		// Now maxElem is the max element of rchild tree, 
		// which is also the max element of cur node tree; 
		// If cur node data is not less than max data of rchild tree, return false; 
		if (!(result = tree->data < maxElem)) {
			return result;
		}
	}
	else {
		maxElem = tree->data;
	}

	// Now pass the examination, return true; 
	// Now maxElem is the max element of cur node tree; 
	return result;
}

bool isBST(BiTree tree)
{
	int maxElem = INT_MIN;

	return isBST_buildin(tree, maxElem);
}

static void fwriteBitreeRXL(BiTree tree, FILE* fp)
{
	if (tree != nullptr) {
		fwriteBitreeRXL(tree->rchild, fp); 
		fprintf(fp, "%d ", tree->data);
		fwriteBitreeRXL(tree->lchild, fp); 
	}

	return; 
}

void fwriteDescend(BiTree tree, const char filename[])
{
	FILE* fp; 

	fp = fopen(filename, "a+"); 

	fwriteBitreeRXL(tree, fp); 

	fclose(fp); 

	return; 
}