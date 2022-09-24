#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_27.h"

static size_t findMidInd(int* list, size_t head, size_t tail)
{
    int arr[3] = { list[head], list[tail], list[head + (tail - head) / 2] };
    size_t ind[3] = { head, tail, head + (tail - head) / 2 };

    for (size_t index = 3; index > 0; --index) {
        for (size_t jndex = 0; jndex < index - 1; ++jndex) {
            if (arr[jndex] > arr[jndex + 1]) {
                arr[jndex] += arr[jndex + 1];
                arr[jndex + 1] = arr[jndex] - arr[jndex + 1];
                arr[jndex] -= arr[jndex + 1];

                ind[jndex] += ind[jndex + 1];
                ind[jndex + 1] = ind[jndex] - ind[jndex + 1];
                ind[jndex] -= ind[jndex + 1];
            }
        }
    }

    return ind[1];
}

static size_t partition(int* list, size_t head, size_t tail)
{
    // find pivot; 
    size_t pivotInd = findMidInd(list, head, tail);
    // move pivot to the head of list; 
    int pivot = list[pivotInd];
    list[pivotInd] = list[head]; 
    list[head] = pivot; 

    while (head < tail) {
        while (head < tail && list[tail] >= pivot) {
            --tail;
        }
        list[head] = list[tail]; 
        while (head < tail && list[head] <= pivot) {
            ++head; 
        }
        list[tail] = list[head]; 
    }
    list[head] = pivot; 

    return head; 
}

int qsFind(int* list, size_t head, size_t tail, size_t targetOrder)
{
    if (head <= tail) {
        size_t pivotInd = partition(list, head, tail);

        if (pivotInd == targetOrder - 1) {
            return list[pivotInd]; 
        }
        else if (pivotInd > targetOrder - 1 && pivotInd > head) {
            return qsFind(list, head, pivotInd - 1, targetOrder);
        }
        else if (pivotInd < targetOrder - 1 && pivotInd < tail) {
            return qsFind(list, pivotInd + 1, tail, targetOrder);
        }
    }

    return 0;
}