#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_21.h"

void partition(int* list, size_t n)
{
    int pivot = list[n - 1]; 

    size_t head = 0; 
    size_t tail = n - 1; 

    while (head < tail) {
        while (head < tail && list[head] <= pivot) {
            ++head; 
        }
        list[tail] = list[head]; 

        while (head < tail && list[tail] >= pivot) {
            --tail; 
        }
        list[head] = list[tail]; 
    }
    list[tail] = pivot; 

    return; 
}
