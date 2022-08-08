#ifndef DS_TEST_H_
#define DS_TEST_H_

#include "test.hpp"

template <typename DataType>
class BTNode
{
	DataType val_;
	BTNode<DataType>* lchild_;
	BTNode<DataType>* rchild_;
};

template <typename DataType>
using BTree = BTNode<DataType>*;

#endif