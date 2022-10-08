#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <vector>
#include "9_31.h"

using std::stack;
using std::pair; 

// root = { rootOfMinimalUBTree, ubFlag }, result = ubFlagOfUBChildOfRoot;
//         R		->head
//        /
//       A			->rootOfMinimalUBTree
//      / \
//     B   ...		->UBChildOfRoot
//    /				->C is on the l(r)childtree of B,
//   ...			//so result == false(true);
//   ...
//  /
// C				->newNode
static bool updateBF(stack<pair<AVLNode*, bool>> stk, pair<AVLNode*, bool>& root,
	pair<AVLNode*, bool> head)
{
	pair<AVLNode*, bool> mov = stk.top();
	stk.pop();
	pair<AVLNode*, bool> curTop = stk.top();
	bool minUBTreeFound = false;
	bool result = false;

	while (!stk.empty()) {
		curTop.first->bf_ += (curTop.second ? 1 : -1);

		if ((curTop.first->bf_ < -1 || curTop.first->bf_ > 1) && !minUBTreeFound) {
			root = { curTop.first, curTop.first->bf_ > 1 };
			result = mov.second;
		}

		mov = curTop;
		stk.pop();
		curTop = stk.empty() ? pair<AVLNode*, bool>(nullptr, false) : stk.top();

		if (root.first != nullptr && !minUBTreeFound) {
			minUBTreeFound = true;
			head = curTop; 
		}
	}

	return result;
}

AVLTree buildAVL(void)
{
	std::cout << "An AVL tree is being built. " << std::endl;
	std::cout << "Enter the data in the node after prompting, " << std::endl;
	std::cout << "or enter any non-digit-or-whitespace character to exit. " << std::endl;

	int cache = 0;
	AVLTree tree = nullptr;
	if (scanf("%d", &cache) != 1) {
		return tree;
	}
	// Now root available;
	tree = new AVLNode;
	tree->data_ = cache;

	AVLNode* newNode = nullptr;
	AVLNode* mov = nullptr; 
	stack<pair<AVLNode*, bool>> stk = {};

	while (scanf("%d", &cache) == 1) {
		// init newNode;
		newNode = new AVLNode; 
		newNode->data_ = cache;

		// insert newNode and compute balance factor;
		stk = {}; 
		mov = tree;
		while (mov != nullptr && mov->data_ != cache) {
			stk.push({ mov, (mov->data_ > cache) ? false : true });
			mov = (mov->data_ > cache) ? mov->lchild_ : mov->rchild_;
		}
		if (mov->data_ == cache) {
			printf("There is an existing node with data %d. \n", cache);
			continue;
		}
		// Now mov == nullptr and cache is a new value for tree;
		// Now stk has recorded the path of insertation;
		mov = stk.top().first;
		if (mov->data_ > cache) {
			mov->lchild_ = newNode;
		}
		else {
			mov->rchild_ = newNode;
		}
		stk.push({ newNode, false });

		// recompute balance factor;
		// Find the minimal unbalanced tree;
		pair<AVLNode*, bool> root = { nullptr, false };
		pair<AVLNode*, bool> head = { nullptr, false };
		bool ubFlag = updateBF(stk, root, head); // After this line, stk remains unchanged;

		// node adjustment;
		if (root.first == nullptr) {
			return tree;
		}
		// RR rotation (left single rot.)
		else if (root.second && ubFlag) {

		}
	}
}