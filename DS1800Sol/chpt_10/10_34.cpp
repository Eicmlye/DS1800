#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_34.h"
static void heapify(int* list, size_t listLen)
{
    if (listLen == 0) {
        return;
    }

    // for maxheap, parent > anotherChild; 
    // so list[listLen] > parent is sufficient for exchanging; 
    size_t ind = listLen - 1;
    while (ind != 0 && list[(ind - 1) / 2] < list[ind]) {
        list[(ind - 1) / 2] += list[ind];
        list[ind] = list[(ind - 1) / 2] - list[ind];
        list[(ind - 1) / 2] -= list[ind];

        ind = (ind - 1) / 2;
    }

    return;
}

static void buildMaxHeap(int* list, size_t listLen)
{
    for (size_t len = 1; len <= listLen; ++len) {
        heapify(list, len);
    }

    return;
}

// maxheap is spoiled by replacing heap top; 
static void rebuildMaxHeap(int* list, size_t listLen)
{
    // current pos of the top element; 
    size_t ind = 0;

    while (2 * ind + 1 < listLen) {
        size_t lchildInd = 2 * ind + 1;
        size_t rchildInd = lchildInd + 1;
        size_t maxChildInd = (list[lchildInd] < list[(rchildInd < listLen) ? rchildInd : lchildInd]) ? rchildInd : lchildInd;

        if (list[ind] >= list[maxChildInd]) {
            break;
        }

        int cache = list[ind];
        list[ind] = list[maxChildInd];
        list[maxChildInd] = cache;

        ind = maxChildInd;
    }

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

        rebuildMaxHeap(list, listLen - index - 1);
    }

    return;
}