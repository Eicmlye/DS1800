#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_95.h"

BiTree buildBST(void)
{
	std::cout << "A binary search tree (BST) is being built. " << std::endl;
	std::cout << "Enter data in the node after prompting, " << std::endl;
	std::cout << "or enter any non-digit character except \'\\n\' to exit. " << std::endl << std::endl; 

	BiTree result = new TreeNode;
	TreeNode* mov = nullptr;
	TreeNode* newNode = nullptr;
	TreeNode* tempLink = nullptr; 
	int cache = 0; 

	// fill in root; 
	if (scanf("%d", &cache) == 1) {
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
	}

	return result; 
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
