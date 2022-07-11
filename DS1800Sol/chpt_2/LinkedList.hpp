#ifndef DS_LINKEDLIST_H_
#define DS_LINKEDLIST_H_

template <typename DataType>
struct LNode {
	DataType data;
	LNode<DataType>* next;

	LNode() : next(nullptr) { memset(&data, 0, sizeof(DataType)); };
	LNode(DataType val) : data(val), next(nullptr) {};
	LNode(DataType val, LNode<DataType>* p) : data(val), next(p) {};
};

template <typename DataType>
using LinkedList = LNode<DataType>*;

template <typename DataType>
struct DNode {
	DataType data;
	DNode<DataType>* next;
	DNode<DataType>* pred;

	DNode() : next(nullptr), pred(nullptr) { memset(&data, 0, sizeof(DataType)); };
	DNode(DataType val) : data(val), next(nullptr), pred(nullptr) {};
	DNode(DataType val, DNode<DataType>* p) : data(val), next(p), pred(nullptr) {};
	DNode(DataType val, DNode<DataType>* p, DNode<DataType>* q) : data(val), next(p), pred(q) {};
};

template <typename DataType>
using DList = DNode<DataType>*;

template <typename DataType>
struct DFNode {
	unsigned int freq;
	DataType data;
	DFNode<DataType>* next;
	DFNode<DataType>* pred;

	DFNode() : freq(0), next(nullptr), pred(nullptr) { memset(&data, 0, sizeof(DataType)); };
	DFNode(DataType val) : freq(0), data(val), next(nullptr), pred(nullptr) {};
	DFNode(DataType val, DFNode<DataType>* p) : freq(0), data(val), next(p), pred(nullptr) {};
	DFNode(DataType val, DFNode<DataType>* p, DFNode<DataType>* q) : freq(0), data(val), next(p), pred(q) {};
};

template <typename DataType>
using DFList = DFNode<DataType>*;

#endif