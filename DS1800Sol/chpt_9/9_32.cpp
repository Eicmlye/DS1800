#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <vector>
#include "9_32.h"

using std::stack;
using std::pair;
using AVLpair = pair<AVLNode*, bool>;

static int buildBalanceFactor(AVLTree tree)
{
	// Deal with empty tree;
	if (tree == nullptr) {
		return 0;
	}

	// Now non-empty tree;
	// If leaf;
	if (tree->lchild_ == nullptr && tree->rchild_ == nullptr) {
		tree->bf_ = 0;
		return 1;
	}
	// Now non-leaf node;
	int hL = buildBalanceFactor(tree->lchild_);
	int hR = buildBalanceFactor(tree->rchild_);
	tree->bf_ = hL - hR;
	return (hL > hR) ? hL + 1 : hR + 1;
}
static void setChild(AVLpair& pr, AVLTree node)
{
	if (!pr.second) {
		pr.first->lchild_ = node;
	}
	else {
		pr.first->rchild_ = node;
	}

	return;
}
static void singleLRot(AVLTree root)
{
	AVLNode* list[2] = { root->rchild_, root };

	list[1]->rchild_ = list[0]->lchild_;
	list[0]->lchild_ = list[1];

	return;
}
static void singleRRot(AVLTree root)
{
	AVLNode* list[2] = { root->lchild_, root };

	list[1]->lchild_ = list[0]->rchild_;
	list[0]->rchild_ = list[1];

	return;
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
	stack<AVLpair> stk = {};

	while (scanf("%d", &cache) == 1) {
		// init newNode;
		newNode = new AVLNode;
		newNode->data_ = cache;

		// insert newNode;
		stk = {};
		mov = tree;
		while (mov != nullptr && mov->data_ != cache) {
			stk.push({ mov, (mov->data_ > cache) ? false : true });
			mov = (mov->data_ > cache) ? mov->lchild_ : mov->rchild_;
		}
		if (mov != nullptr) { // i.e. mov->data == cache;
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
		buildBalanceFactor(tree);

		// Find the minimal unbalanced tree;
		// init;
		AVLpair* ubList = new AVLpair[3];
		for (size_t index = 0; index < 3; ++index) {
			ubList[index] = AVLpair(nullptr, false);
		}
		// search;
		AVLpair movTop = stk.top();
		stk.pop();
		AVLpair curTop = stk.top();
		while (!stk.empty()) {
			if (curTop.first->bf_ < -1 || curTop.first->bf_ > 1) {
				ubList[0] = movTop;
				ubList[1] = curTop;

				stk.pop();
				ubList[2] = stk.empty() ? AVLpair(nullptr, false) : stk.top();

				break;
			}

			movTop = curTop;
			stk.pop();
			curTop = stk.empty() ? AVLpair(nullptr, false) : stk.top();
		}

		// In case that root.first is the root of tree;
		bool headNull = false;
		if (ubList[2].first == nullptr) {
			headNull = true;
			ubList[2].first = new AVLNode;
			ubList[2].first->lchild_ = ubList[1].first;
		} // if headNull is true, the pointer `tree` needs to be redirected;

		// node adjustment;
		if (ubList[1].first != nullptr) {
			// LL rotation (right single rot.)
			if (!ubList[1].second && !ubList[0].second) {
				singleRRot(ubList[1].first);

				if (headNull) {
					tree = ubList[1].first;
				}
				else {
					setChild(ubList[2], ubList[0].first);
				}
			}
			// RR rotation (left single rot.)
			else if (ubList[1].second && ubList[0].second) {
				singleLRot(ubList[1].first);

				if (headNull) {
					tree = ubList[1].first;
				}
				else {
					setChild(ubList[2], ubList[0].first);
				}
			}
			// LR rotation (left-right rot.)
			else if (!ubList[1].second && ubList[0].second) {
				AVLNode* newRoot = ubList[0].first->rchild_;
				setChild(ubList[1], ubList[0].first->rchild_);
				singleLRot(ubList[0].first);
				singleRRot(ubList[1].first);

				if (headNull) {
					tree = newRoot;
				}
				else {
					setChild(ubList[2], newRoot);
				}
			}
			// RL rotation (right-left rot.)
			else if (ubList[1].second && !ubList[0].second) {
				AVLNode* newRoot = ubList[0].first->lchild_;
				setChild(ubList[1], ubList[0].first->lchild_);
				singleRRot(ubList[0].first);
				singleLRot(ubList[1].first);

				if (headNull) {
					tree = newRoot;
				}
				else {
					setChild(ubList[2], newRoot);
				}
			}
		}

		// recompute balance factor;
		buildBalanceFactor(tree);
	}

	return tree;
}

size_t buildLSize(AVLTree tree)
{
	if (tree != nullptr) {
		tree->lsize_ = buildLSize(tree->lchild_) + 1;
		return tree->lsize_ + buildLSize(tree->rchild_);
	}

	return 0;
}

int getKthNode(AVLTree tree, size_t k)
{
	AVLNode* mov = tree;
	size_t countInd = mov->lsize_;

	while (countInd != k) {
		if (countInd > k) {
			countInd -= mov->lsize_;
			mov = mov->lchild_;
			countInd += mov->lsize_;
		}
		else {
			mov = mov->rchild_;
			countInd += mov->lsize_;
		}
	}

	return mov->data_;
}
