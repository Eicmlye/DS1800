#include <iostream>
#include "6_4.h"

static void preOrdTrav(BiTree tree, size_t* result)
{
	size_t countChild = 0; 
	if (tree != nullptr) {
		if (tree->left != nullptr) {
			++countChild;
		}
		if (tree->right != nullptr) {
			++countChild;
		}
		++result[countChild]; 
		preOrdTrav(tree->left, result);
		preOrdTrav(tree->right, result);
	}

	return; 
}

size_t* countNodeDeg(BiTree tree)
{
	size_t* result = new size_t[3]; 
	for (size_t index = 0; index < 3; ++index) {
		result[index] = 0; 
	}

	preOrdTrav(tree, result); 

	return result; 
}