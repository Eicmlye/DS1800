#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_48.h"

BiTree buildBiTree(size_t& saveNodeNum, size_t level)
{
	++saveNodeNum;

	#define CLRSTDIN \
		do {\
			while (getchar() != '\n') {\
				continue; \
			}\
		} while (0)
	#define INDENT(m_indsize) \
		do {\
			for (size_t index = 0; index < m_indsize; ++index) {\
				std::cout << "    "; \
			}\
		} while (0)

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
		node->lchild = buildBiTree(saveNodeNum, level + 1);
		if (node->lchild == nullptr) {
			std::cout << "\r\033[1A\033[K";
			INDENT(level);
			std::cout << "Lchild: NULL" << std::endl;
		}

		INDENT(level);
		std::cout << "Rchild: ";
		node->rchild = buildBiTree(saveNodeNum, level + 1);
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
		--saveNodeNum; 
		CLRSTDIN;

		// std::cout << "\r\033[1A\033[K";
		// INDENT(level);
		// std::cout << "NULL" << std::endl;

		return nullptr;
	}
}

static size_t recPreOrdTrav(BiTree tree, int* pre, size_t& preListInd)
{
	if (tree != nullptr) {
		/* visit node */
		pre[preListInd] = tree->data;

		++preListInd;
		recPreOrdTrav(tree->lchild, pre, preListInd);
		++preListInd;
		recPreOrdTrav(tree->rchild, pre, preListInd);
	}
	else {
		--preListInd; 
	}

	return preListInd;
}

// API; 
void preOrdTrav(BiTree tree, int* pre) 
{
	size_t preListInd = 0; 
	recPreOrdTrav(tree, pre, preListInd);

	return; 
}

static size_t recInOrdTrav(BiTree tree, int* in, size_t& inListInd)
{
	if (tree != nullptr) {
		recInOrdTrav(tree->lchild, in, inListInd);
		/* visit node */
		++inListInd;
		in[inListInd] = tree->data;

		++inListInd;
		recInOrdTrav(tree->rchild, in, inListInd);
	}
	else {
		--inListInd;
	}

	return inListInd;
}

// API; 
void inOrdTrav(BiTree tree, int* in)
{
	size_t inListInd = 0; 
	recInOrdTrav(tree, in, inListInd); 

	return; 
}

BiTree buildPreInBiTree(int* preList, int* inList, size_t n)
{
	if (n == 0) {
		return nullptr; 
	}

	size_t preInd = 0;
	size_t inInd = 0; 
	BiTree result = new TreeNode; // header of tree; in case that the root has no lchild; 

	typedef struct stackNode {
		TreeNode* tnode = nullptr; 
		stackNode* next = nullptr; 
	} stackNode, * stack;

	#define STKPUSH(m_elem) \
		do {\
			mov = new stackNode; \
			mov->tnode = m_elem; \
			mov->next = stk->next; \
			stk->next = mov; \
			++preInd; \
		} while (0)

	#define STKPOP \
		do {\
			stk->next = mov->next; \
			delete mov; \
			mov = stk->next; \
			++inInd; \
		} while (0)

	#define LBUILDPUSH(m_elem) \
		do {\
			m_elem = new TreeNode; \
			m_elem->data = preList[preInd]; \
			stk->next->tnode->lchild = m_elem; \
			STKPUSH(m_elem); \
		} while (0)

	#define RBUILDPUSH(m_elem) \
		do {\
			m_elem = new TreeNode; \
			m_elem->data = preList[preInd]; \
			stk->next->tnode->rchild = m_elem; \
			STKPOP; \
			STKPUSH(m_elem); \
		} while (0)

	stack stk = new stackNode; // header of stk; 
	stackNode* mov = nullptr;
	STKPUSH(result); 
	--preInd; 

	// build root; 
	TreeNode* cache = nullptr;
	LBUILDPUSH(cache); // now preInd is the index of the preListNext of the node just having been built; we will keep this definition for preInd during the process; 

	// preInd will always reach n before inInd does; 
	while (preInd < n) {
		while (preInd < n && preList[preInd] != inList[inInd]) {
			LBUILDPUSH(cache); 
		}
		// build leaf; 
		LBUILDPUSH(cache);
		if (preInd == n) {
			break; 
		}

		// trace back to a node with rchild; 
		while (mov->next->tnode->data == inList[inInd + 1]) { // rchild does not exist; 
			STKPOP; 
		}

		// build rchild; 
		RBUILDPUSH(cache);
		if (preInd == n) {
			break;
		}

		// check if lchild exists; 
		if (mov->next->tnode->data == inList[inInd + 1]) { // in inList mov->tnode is followed by an ancester root; 
			STKPOP;
			// build rchild; 
			RBUILDPUSH(cache);
		}
		if (preInd == n) {
			break;
		}
	}

	return result->lchild; 
}