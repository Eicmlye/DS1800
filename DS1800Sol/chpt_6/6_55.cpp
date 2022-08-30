#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_55.h"

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

		return nullptr;
	}
}

void connectLeaves(BiTree tree)
{
	typedef struct stackNode {
		TreeNode* tnode = nullptr; 
		stackNode* next = nullptr; 
	} stackNode, *stack;

	#define STKPUSH(m_elem) do { top = new stackNode; top->tnode = m_elem; top->next = stk->next; stk->next = top; } while (0)
	#define STKPOP do { stk->next = top->next; delete top; top = stk->next; } while (0)

	stack stk = new stackNode; 
	stackNode* top = nullptr; 

	TreeNode* mov = tree; 
	TreeNode* preLeaf = nullptr; 

	while (top != nullptr || mov != nullptr) {
		if (mov != nullptr) {
			STKPUSH(mov); 

			/* visit node */
			if (mov->lchild == nullptr && mov->rchild == nullptr) {
				if (preLeaf != nullptr) {
					preLeaf->rchild = mov; 
				}
				preLeaf = mov; 
			}

			mov = mov->lchild; 
		}
		else {
			mov = top->tnode; 
			STKPOP; 

			mov = mov->rchild; 
		}
	}

	return; 
}
