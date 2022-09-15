#ifndef DS_10_6_H_
#define DS_10_6_H_

#include "chpt_tag.h"
#include "LinkedList.hpp"

LNode<int>** buildPList(LinkedList<int> list); 

void mergeSort_2part(LNode<int>** pList, size_t head, size_t tail);

#endif