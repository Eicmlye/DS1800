#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_7.h"

BiTree buildBiTree(size_t level)
{
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

bool isComplete(BiTree tree)
{
	#define QUEPUSH(elem) \
		do { \
			mov = new queNode; \
			mov->tnode = elem; \
			rear->next = mov; \
			rear = rear->next; \
			++size; \
		} while (0)

	typedef struct queNode {
		TreeNode* tnode = nullptr;
		queNode* next = nullptr;
	}queNode, *queue;

	// build que;
	size_t size = 0;
	queue que = new queNode; // header node of que;
	queNode* rear = que; // rear of que;

	// init que;
	queNode* mov = new queNode;
	mov->tnode = tree;
	rear->next = mov;
	rear = rear->next;
	size = 1;

	size_t index = 0;
	bool metNull = false;
	TreeNode* cache = nullptr;
	size_t cacheSize = size;
	while (que->next != nullptr) {
		cacheSize = size;
		size = 0;
		for (index = 0; index < cacheSize; ++index) {
			cache = que->next->tnode;
			if (metNull) {
				if (cache != nullptr) {
					return false;
				}
			}
			else if (cache == nullptr) {
				metNull = true;
			}
			else {
				QUEPUSH(cache->left);
				QUEPUSH(cache->right);
			}

			// pop;
			queNode* temp = que->next;
			que->next = que->next->next;
			delete temp;
		}
	}

	return true;
}
