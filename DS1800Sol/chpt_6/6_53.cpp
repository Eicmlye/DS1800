#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_53.h"

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

BiTree recCopyBiTree(BiTree src)
{
	BiTree result = nullptr; 

	if (src != nullptr) {
		result = new TreeNode; 
		result->data = src->data;
		result->lchild = recCopyBiTree(src->lchild);
		result->rchild = recCopyBiTree(src->rchild);
	}

	return result;
}

BiTree copyBiTree(BiTree src)
{
	if (src == nullptr) {
		return nullptr; 
	}

	BiTree result = new TreeNode; 

	typedef struct stackNode {
		TreeNode* tnode = nullptr; 
		stackNode* next = nullptr; 
	} stackNode, *stack;

	#define STKPUSH(m_stk, m_topcache, m_tnode) \
		do {\
			m_topcache = new stackNode; \
			m_topcache->tnode = m_tnode; \
			m_topcache->next = m_stk->next; \
			m_stk->next = m_topcache; \
		} while (0)
	#define SRCSTKPUSH(m_tnode) STKPUSH(stkSrc, topSrc, m_tnode)
	#define TARSTKPUSH(m_tnode) STKPUSH(stkTar, topTar, m_tnode)

	#define STKPOP(m_stk, m_topcache) \
		do {\
			m_stk->next = m_topcache->next; \
			delete m_topcache; \
			m_topcache = m_stk->next; \
		} while (0)
	#define SRCSTKPOP STKPOP(stkSrc, topSrc)
	#define TARSTKPOP STKPOP(stkTar, topTar)

	stack stkSrc = new stackNode;
	stackNode* topSrc = nullptr;

	stack stkTar = new stackNode;
	stackNode* topTar = nullptr;

	TreeNode* movSrc = src; 
	TreeNode* movTar = result;
	while (stkSrc->next != nullptr || movSrc != nullptr) {
		if (movSrc != nullptr) {
			SRCSTKPUSH(movSrc); 

			/* visit node */
			movTar->data = movSrc->data;
			TARSTKPUSH(movTar); 

			movSrc = movSrc->lchild; 
			if (movSrc != nullptr) {
				movTar->lchild = new TreeNode;
				movTar = movTar->lchild;
			}
		}
		else {
			movSrc = topSrc->tnode->rchild; 
			SRCSTKPOP; 
			movTar = topTar->tnode; 
			if (movSrc != nullptr) {
				movTar->rchild = new TreeNode;
				movTar = movTar->rchild;
			}
			TARSTKPOP; 
		}
	}

	return result; 
}