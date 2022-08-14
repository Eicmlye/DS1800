#include <iostream>
#include "6_8.h"

BiTree buildComplTree(int* A, size_t n, size_t cur)
{
	BiTree result = new TreeNode; 
	result->data = A[cur];
	result->left = (cur * 2 + 1 < n) ? buildComplTree(A, n, cur * 2 + 1) : nullptr;
	result->right = (cur * 2 + 2 < n) ? buildComplTree(A, n, cur * 2 + 2) : nullptr;

	return result; 
}