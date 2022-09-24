#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_31.h"

// suppose list[0] to list[n - 2] is already heapified; 
// now add new element list[n - 1] and heapify list; 
void heapify(int* list, size_t listLen)
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

void buildMaxHeap(int* list, size_t listLen)
{
    for (size_t len = 1; len <= listLen; ++len) {
        heapify(list, len); 
    }

    return; 
}

void heapSort(int* list, size_t listLen)
{
    for (size_t index = 0; index < listLen; ++index) {
        // (re)build maxheap; 
        buildMaxHeap(list, listLen - index);

        // output local max element to the end of the heap; 
        int cache = list[0];
        list[0] = list[listLen - index - 1];
        list[listLen - index - 1] = cache;
    }

    return;
}