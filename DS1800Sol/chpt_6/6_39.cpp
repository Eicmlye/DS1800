#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_39.h"

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

BiTree buildNormalBiTree(int* preList, int* postList, size_t preHead, size_t preTail, size_t postHead, size_t postTail)
{
	BiTree result = new TreeNode; 
	result->data = preList[preHead]; 
	
	if (preHead != preTail) {
		// find preList[preHead + 1] in postList; 
		size_t indL = 0;
		for (indL = postHead; indL <= postTail; ++indL) {
			if (postList[indL] == preList[preHead + 1]) {
				break;
			}
		}
		// find postList[postHead - 1] in preList; 
		size_t indR = 0;
		for (indR = preHead; indR <= preTail; ++indR) {
			if (preList[indR] == postList[postTail - 1]) {
				break;
			}
		}

		result->left = buildNormalBiTree(preList, postList, preHead + 1, indR - 1, postHead, indL);
		result->right = buildNormalBiTree(preList, postList, indR, preTail, indL + 1, postTail - 1);
	}
	else {
		result->left = nullptr; 
		result->right = nullptr; 
	}

	return result;
}