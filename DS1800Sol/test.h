#ifndef DS_TEST_H_
#define DS_TEST_H_

template <typename DataType>
class BTNode
{
	DataType val_;
	BTNode<DataType>* lchild_;
	BTNode<DataType>* rchild_;
};

template <typename DataType>
using BTree = BTNode<DataType>*;

#include "test.hpp"

#endif