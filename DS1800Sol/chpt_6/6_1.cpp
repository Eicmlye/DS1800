/*
	只需求出各叶节点的带权路径长度相加即可. 考虑先序遍历该树, 遍历到叶节点时, 计算其带权路径长度, 并加至总 WPL 中. 
*/

#include <iostream>
#include "6_1.h"

unsigned int getWPL(BiTree tree, unsigned int WPL, unsigned int level)
{
	if (tree->left == nullptr && tree->right == nullptr) {
		WPL += level * tree->weight; 
	}
	else {
		if (tree->left != nullptr) {
			WPL = getWPL(tree->left, WPL, level + 1);
		}
		if (tree->right != nullptr) {
			WPL = getWPL(tree->right, WPL, level + 1);
		}
	}

	return WPL; 
}