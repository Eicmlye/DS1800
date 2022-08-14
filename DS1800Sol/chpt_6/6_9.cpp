#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include "6_9.h"

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

char** btree2Arr(BiTree tree)
{
	#define QUEPUSH(elem) \
		do {\
			mov = new queNode; \
			mov->tnode = elem; \
			rear->next = mov; \
			rear = rear->next; \
		} while (0)

	typedef struct queNode {
		TreeNode* tnode = nullptr;
		queNode* next = nullptr; 
	} queNode, *queue;

	// init que; 
	queue que = new queNode; // header node of queue; 
	queNode* rear = que; // rear of queue; 
	queNode* front = que; // front of queue; 
	size_t queSize = 0; 

	// set que; 
	queNode* mov = new queNode; 
	mov->tnode = tree; 
	rear->next = mov; 
	rear = rear->next; 

	size_t cacheSize = 0; 
	front = que->next; 
	size_t level = 0;
	++queSize; 
	bool allNull = false; 

	while (!allNull) {
		++level;
		cacheSize = queSize; 
		queSize = 0; 
		allNull = true; 
		for (size_t index = 0; index < cacheSize; ++index) {
			if (front->tnode != nullptr) {
				if (front->tnode->left != nullptr) {
					QUEPUSH(front->tnode->left);
					allNull = false; 
				}
				else {
					QUEPUSH(nullptr);
				}
				++queSize; 

				if (front->tnode->right != nullptr) {
					QUEPUSH(front->tnode->right);
					allNull = false;
				}
				else {
					QUEPUSH(nullptr);
				}
				++queSize;
			}
			else {
				QUEPUSH(nullptr);
				++queSize;
				QUEPUSH(nullptr);
				++queSize;
			}

			front = front->next; 
		}
	}

	size_t arrSize = (size_t)pow(2, level) - 1;
	char** result = new char*[arrSize];
	size_t dataSize = (size_t)log((size_t)pow(2, sizeof(int) * 8)) + 1; 
	for (size_t index = 0; index < arrSize; ++index) {
		if (que->next->tnode != nullptr) {
			result[index] = new char[dataSize]; 
			for (size_t jndex = 0; jndex < dataSize; ++jndex) {
				result[index][jndex] = '\0'; 
			}
			sprintf(result[index], "%d", que->next->tnode->data);
		}
		else {
			result[index] = nullptr;
		}

		// pop que; use rear as cache; 
		rear = que->next;
		que->next = rear->next;
		delete rear;
	}

	return result; 
}