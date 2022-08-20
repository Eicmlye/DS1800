#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "6_47.h"

BiTree buildPreInBiTree(int* preList, int* inList, size_t preHead, size_t preTail, size_t inHead, size_t inTail)
{
	TreeNode* result = new TreeNode; 
	result->data = preList[preHead]; 

	if (preHead != preTail) {
		// find preList[preHead] in inList;  
		size_t indRoot = 0;
		for (indRoot = inHead; indRoot < inTail; ++indRoot) {
			if (preList[preHead] == inList[indRoot]) {
				break; 
			}
		}

		result->lchild = (indRoot != inHead) ? buildPreInBiTree(preList, inList, preHead + 1, preHead + indRoot - inHead, inHead, indRoot - 1) : nullptr;
		result->rchild = (indRoot != inTail) ? buildPreInBiTree(preList, inList, preHead + indRoot - inHead + 1, preTail, indRoot + 1, inTail) : nullptr;
	}

	return result; 
}