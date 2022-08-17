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
	if (tree == nullptr) {
		return nullptr; 
	}

	#define PUSHSTK \
		do { \
			top = new stackNode; \
			top->tnode = mov; \
			top->next = stk->next; \
			stk->next = top; \
		} while (0)

	typedef struct stackNode {
		TreeNode* tnode = nullptr; 
		stackNode* next = nullptr; 
	} stackNode, *stack;

	stack stk = new stackNode; // header of stk; 
	TreeNode* rtag = nullptr; 
	TreeNode* mov = tree; 

	stackNode* top = nullptr; 
	
	stack pstk = new stackNode;
	stack qstk = new stackNode;
	stackNode* cachemov = nullptr; 
	stackNode* cache = nullptr; 

	while (stk->next != nullptr || mov != nullptr) {
		if (mov != nullptr) {
			PUSHSTK; 
			mov = mov->left; 
		}
		else {
			mov = top->tnode;
			if (mov->right != nullptr && mov->right != rtag) {
				mov = mov->right; 
			}
			else {
				/* visit node */
				// inverse the original stack for faster comparison later; 
				if (pstk->next != nullptr && qstk->next != nullptr) {
					break;
				}

				if (mov == p) {
					cachemov = top; 
					while (cachemov != nullptr) {
						cache = new stackNode; 
						cache->tnode = cachemov->tnode; 
						cache->next = pstk->next; 
						pstk->next = cache;

						cachemov = cachemov->next;
					}
				}
				// caution that this should not be elseif, 
				// as p == q is possible; 
				if (mov == q) {
					cachemov = top;
					while (cachemov != nullptr) {
						cache = new stackNode;
						cache->tnode = cachemov->tnode;
						cache->next = qstk->next;
						qstk->next = cache;

						cachemov = cachemov->next; 
					}
				}

				// update rtag; 
				rtag = mov; 
				
				// pop stk; 
				stk->next = top->next; 
				delete top; 
				top = stk->next; 
				// enforcing next check to top of stack; 
				mov = nullptr; 
			}
		}
	}

	// if p or q does not exist; 
	if (pstk->next == nullptr || qstk->next == nullptr) {
		return nullptr;
	}

	// use top, cache and cachemov as probes; 
	top = pstk; 
	cache = pstk->next; 
	cachemov = qstk->next; 
	while (cache != nullptr && cachemov != nullptr && (cache->tnode == cachemov->tnode)) {
		top = top->next; 
		cache = cache->next; 
		cachemov = cachemov->next; 
	}

	return top->tnode; 
}