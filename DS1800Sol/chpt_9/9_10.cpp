#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "9_10.h"
#include <stack>

// The variable level is used for building levels
// and does not require user input.
// So using buildBiTree() is perfectly fine;
BiTree buildBiTree(size_t level)
{
	#define CLRSTDIN do { while (getchar() != '\n') { continue; }} while (0)

	#define INDENT(m_indsize) do { for (size_t index = 0; index < m_indsize; ++index) { std::cout << "    "; }} while (0)

	// Welcome guide;
	if (level == 1) {
		std::cout << "A binary tree is being built. " << std::endl;
		std::cout << "Enter data in the node after prompting, " << std::endl;
		std::cout << "or enter any non-digit character except \'\\n\' for empty node. " << std::endl << std::endl;
		std::cout << "Root: ";
	}

	// test empty input and rewinding;
	char temp = '\0';
	while ((temp = getchar()) == '\n') {
		// move back to the end of the line;
		std::cout << "\033[1A";
		for (size_t index = 0; index < (level - 1) * 4 + 8; ++index) {
			std::cout << "\033[1C";
		}
		if (level == 1) {
			std::cout << "\033[2D";
		}
	}
	ungetc(temp, stdin);

	// load in data;
	TreeNode* node = new TreeNode;
	if (scanf("%d", &(node->data)) == 1) {
		// clear stdin for the next empty-input test;
		CLRSTDIN;

		INDENT(level);
		std::cout << "Lchild: ";
		node->lchild = buildBiTree(level + 1);
		if (node->lchild == nullptr) {
			std::cout << "\r\033[1A\033[K";
			INDENT(level);
			std::cout << "Lchild: NULL" << std::endl;
		}

		INDENT(level);
		std::cout << "Rchild: ";
		node->rchild = buildBiTree(level + 1);
		if (node->rchild == nullptr) {
			std::cout << "\r\033[1A\033[K";
			INDENT(level);
			std::cout << "Rchild: NULL" << std::endl;
		}

		if (node->lchild == nullptr && node->rchild == nullptr) {
			std::cout << "\r\033[1A\033[K";
			std::cout << "\r\033[1A\033[K";
		}

		return node;
	}
	else { // empty child;
		// clear stdin for the next empty-input test;
		CLRSTDIN;
		// reprint output for null root; 
		if (level == 1) {
			std::cout << "\r\033[1A\033[K"; 
			std::cout << "Root: NULL" << std::endl; 
		}

		return nullptr;
	}
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

#if 1
bool isBST(BiTree tree)
{
	int maxElem = INT_MIN; 

	return isBST_buildin(tree, maxElem); 
}
#else
bool isBST(BiTree tree)
{
	if (tree == nullptr) { // empty tree;
		return true;
	}

	std::stack<TreeNode*> stk = {};
	TreeNode* mov = tree;
	TreeNode* pred = nullptr;

	while (!stk.empty() || mov != nullptr) {
		if (mov != nullptr) {
			stk.push(mov);
			mov = mov->lchild;
		}
		else { // the current nullptr node is not in the stack yet;
			mov = stk.top();

			/* visit node */
			if (pred != nullptr) {
				if (pred->data >= mov->data) {
					return false;
				}
			}
			pred = mov;

			mov = mov->rchild;
			stk.pop();
		}
	}

	return true;
}
#endif