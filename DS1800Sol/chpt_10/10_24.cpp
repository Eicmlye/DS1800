#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_24.h"

static int findMid(int num1, int num2, int num3) 
{
    int arr[3] = { num1, num2, num3 };
    if (arr[0] > arr[1]) {
        arr[0] += arr[1];
        arr[1] = arr[0] - arr[1];
        arr[0] -= arr[1];
    }
    if (arr[1] > arr[2]) {
        arr[1] += arr[2];
        arr[2] = arr[1] - arr[2];
        arr[1] -= arr[2];
    }
    if (arr[0] > arr[1]) {
        arr[0] += arr[1];
        arr[1] = arr[0] - arr[1];
        arr[0] -= arr[1];
    }

    return arr[1]; 
}

static void partition(int* list, size_t& head, size_t& tail)
{
    // 单独处理 head + 1 == tail 的情况; 
    if (head + 1 == tail) {
        if (list[head] > list[tail]) {
            list[head] += list[tail]; 
            list[tail] = list[head] - list[tail]; 
            list[head] -= list[tail]; 
        }

        head += tail; 
        tail = head - tail; 
        head -= tail; 
    }
    else {
        // 三点取中; 
        int pivot = findMid(list[head], list[tail], list[head + (tail - head) / 2]);

        while (head < tail) {
            while (head <= tail && list[tail] > pivot) {
                --tail;
            }
            while (head <= tail && list[head] < pivot) {
                ++head;
            }

            if (head < tail) {
                int cache = list[head];
                list[head] = list[tail];
                list[tail] = cache;
                --tail;
                ++head;
            }

            if (head == tail) {
                if (list[head] < pivot) {
                    ++head;
                }
                else {
                    --tail;
                }
            }
        }
    }

    return; 
}

void quickSort(int* list, size_t n)
{
    typedef struct stackNode {
        size_t head = 0; 
        size_t tail = 0; 
        stackNode* next = nullptr; 
    } stackNode, *stack;

    stack stk = new stackNode; 
    stk->next = new stackNode; 
    stk->next->head = 0;
    stk->next->tail = n - 1;

    size_t backHead = 0; 
    size_t frontTail = n - 1;
    stackNode* newNode = nullptr; 
    stackNode* cache = nullptr; 

    while (stk->next != nullptr) {
        // save top node; 
        cache = stk->next;
        // pop top; 
        stk->next = stk->next->next;

        backHead = cache->head;
        frontTail = cache->tail;
        partition(list, backHead, frontTail);

        // 先右半再左半; 
        if (backHead < cache->tail) {
            newNode = new stackNode;
            newNode->head = backHead;
            newNode->tail = cache->tail;

            // push into stack;
            newNode->next = stk->next;
            stk->next = newNode;
        }
        if (cache->head < frontTail) {
            newNode = new stackNode; 
            newNode->head = cache->head; 
            newNode->tail = frontTail; 

            // push into stack;
            newNode->next = stk->next; 
            stk->next = newNode;
        }

        delete cache; 
    }

    return; 
}