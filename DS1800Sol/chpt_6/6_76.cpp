#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_76.h"

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

ThreadBTree buildInOrdThread(BiTree src)
{
	if (src == nullptr) {
		return nullptr;
	}

	ThreadBTree result = new ThreadTNode;

	typedef struct stackNode {
		TreeNode* tnode = nullptr;
		stackNode* next = nullptr;
	} stackNode, * stack;

	typedef struct ThreadStackNode {
		ThreadTNode* tnode = nullptr;
		ThreadStackNode* next = nullptr;
	} ThreadStackNode, * ThreadStack;

	#define STKPUSH(m_stk, m_nodeMode, m_topcache, m_tnode) do { m_topcache = new m_nodeMode; m_topcache->tnode = m_tnode; m_topcache->next = m_stk->next; m_stk->next = m_topcache; } while (0)
	#define SRCSTKPUSH(m_tnode) STKPUSH(stkSrc, stackNode, topSrc, m_tnode)
	#define TARSTKPUSH(m_tnode) STKPUSH(stkTar, ThreadStackNode, topTar, m_tnode)

	#define STKPOP(m_stk, m_topcache) do { m_stk->next = m_topcache->next; delete m_topcache; m_topcache = m_stk->next; } while (0)
	#define SRCSTKPOP STKPOP(stkSrc, topSrc)
	#define TARSTKPOP STKPOP(stkTar, topTar)

	stack stkSrc = new stackNode;
	stackNode* topSrc = nullptr;

	ThreadStack stkTar = new ThreadStackNode;
	ThreadStackNode* topTar = nullptr;

	TreeNode* movSrc = src;
	ThreadTNode* movTar = result;
	ThreadTNode* threadPred = nullptr;

	while (stkSrc->next != nullptr || movSrc != nullptr) {
		if (movSrc != nullptr) {
			SRCSTKPUSH(movSrc);

			/* visit node */
			movTar->data = movSrc->data;
			TARSTKPUSH(movTar);
			// init tags; 
			movTar->ltag = (movSrc->lchild == nullptr);
			movTar->rtag = (movSrc->rchild == nullptr);

			movSrc = movSrc->lchild;
			if (movSrc != nullptr) {
				movTar->lchild = new ThreadTNode;
				movTar = movTar->lchild;
			}
		}
		else {
			movSrc = topSrc->tnode; 
			movTar = topTar->tnode; 

			// modify threads;
			if (movTar->ltag) {
				movTar->lchild = threadPred;
			}
			if (threadPred != nullptr && threadPred->rtag) {
				threadPred->rchild = movTar;
			}
			// update threadPred; 
			threadPred = movTar;

			movSrc = movSrc->rchild;
			SRCSTKPOP;
			if (movSrc != nullptr) {
				movTar->rchild = new ThreadTNode;
				movTar = movTar->rchild;
			}
			TARSTKPOP;
		}
	}

	return result;
}