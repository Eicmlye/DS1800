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

#include <vector>
using std::vector;

template <typename DataType, typename ListNodeType>
ListNodeType* createSingleList(vector<DataType> initData, bool hasHead = true, bool isCyclic = false)
{
    ListNodeType* list = new ListNodeType;
    ListNodeType* newNode = nullptr;

    if (!hasHead) {
        list->data = initData.at(0);
    }
    if (isCyclic) {
        list->next = list;
    }

    for (size_t index = 0; index < ((hasHead) ? initData.size() : initData.size() - 1); ++index) {
        newNode = new ListNodeType(initData.at(initData.size() - 1 - index), list->next);
        list->next = newNode;
    }

    return list;
}

template <typename DataType, typename ListNodeType>
ListNodeType* createDoubleList(vector<DataType> initData, bool hasHead = true, bool isCyclic = false)
{
    ListNodeType* list = new ListNodeType;
    ListNodeType* newNode = nullptr;

    if (!hasHead) {
        list->data = initData.at(0);
    }
    if (isCyclic) {
        list->next = list;
        list->pred = list;
    }

    for (size_t index = 0; index < ((hasHead) ? initData.size() : initData.size() - 1); ++index) {
        newNode = new ListNodeType(initData.at(initData.size() - 1 - index), list->next);
        list->next = newNode;
        newNode->pred = list;
        if (newNode->next != nullptr) {
            newNode->next->pred = newNode;
        }
    }

    return list;
}
#endif