/*
	ֻ�������Ҷ�ڵ�Ĵ�Ȩ·��������Ӽ���. ���������������, ������Ҷ�ڵ�ʱ, �������Ȩ·������, �������� WPL ��. 
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