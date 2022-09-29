#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_35.h"

void heapify(int* list, size_t listLen, size_t root)
{
    while (root < listLen) {
        if (2 * root + 1 >= listLen) {
            return;
        }

        size_t lchildInd = 2 * root + 1;
        size_t rchildInd = lchildInd + 1;
        size_t maxChildInd = (list[lchildInd] < list[(rchildInd < listLen) ? rchildInd : lchildInd]) ? rchildInd : lchildInd;

        if (list[root] >= list[maxChildInd]) {
            return;
        }

        list[root] += list[maxChildInd];
        list[maxChildInd] = list[root] - list[maxChildInd];
        list[root] -= list[maxChildInd];

        root = maxChildInd;
    }

    return;
}

void buildMaxHeap(int* list, size_t listLen)
{
    size_t index = listLen / 2; // the first leaf node; 

    do {
        --index;

        heapify(list, listLen, index);

    } while (index != 0);

    return;
}

void heapSort(int* list, size_t listLen)
{
    // build maxheap; 
    buildMaxHeap(list, listLen);

    for (size_t index = 0; index < listLen; ++index) {
        // output local max element to the end of the heap; 
        int cache = list[0];
        list[0] = list[listLen - index - 1];
        list[listLen - index - 1] = cache;

        heapify(list, listLen - index - 1, 0);
    }

    return;
}