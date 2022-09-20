#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_6.h"

LNode<int>** buildPList(LinkedList<int>& list, size_t& len)
{
    if (len == 0) {
        return nullptr; 
    }

    LNode<int>* pre = list; 
    LNode<int>* mov = list->next; 
    LNode<int>** pList = new LNode<int>*[len];
    len = 0; 

    pList[len] = mov;
    pre = pre->next; 
    mov = mov->next;
    ++len;

    while (mov != nullptr) {
        if (pre->data > mov->data) {
            pList[len] = mov;
            ++len;
        }

        pre = pre->next;
        mov = mov->next;
    }

    return pList; 
}

void mergeSort(LinkedList<int>& list, size_t n)
{
    size_t len = n; 
    LNode<int>** pList = buildPList(list, len); 
    LNode<int>** cacheList = nullptr; 
    LNode<int>* head = nullptr; 
    LNode<int>* rear = nullptr; 

    size_t index = 0; 
    while (len != 1) {
        index = 0; 
        cacheList = new LNode<int>*[len / 2 + len % 2];
        while (2 * index + 1 < len) {
            size_t jndex = 0;
            size_t kndex = 0;
            head = new LNode<int>; 
            rear = head;
            LNode<int>* mov1 = pList[2 * index];
            LNode<int>* mov2 = pList[2 * index + 1];

            // merge pList[2 * index] and pList[2 * index + 1]; 
            while (mov1 != nullptr && mov1 != pList[2 * index + 1] && mov2 != nullptr && mov2 != pList[2 * index + 2]) {
                if (mov1->data <= mov2->data) {
                    rear->next = new LNode<int>; 
                    rear->next->data = mov1->data;
                    mov1 = mov1->next; 
                    rear = rear->next; 
                }
                else {
                    rear->next = new LNode<int>;
                    rear->next->data = mov2->data;
                    mov2 = mov2->next;
                    rear = rear->next;
                }
            }
            while (mov1 != nullptr && mov1 != pList[2 * index + 1]) {
                rear->next = new LNode<int>;
                rear->next->data = mov1->data;
                mov1 = mov1->next;
                rear = rear->next;
            }
            while (mov2 != nullptr && mov2 != pList[2 * index + 2]) {
                rear->next = new LNode<int>;
                rear->next->data = mov2->data;
                mov2 = mov2->next;
                rear = rear->next;
            }

            // update new section to cache; 
            cacheList[index] = head->next; 
            delete head; 

            ++index; 
        }
        if (2 * index < len) {
            cacheList[index] = pList[2 * index];
        }

        // update len; 
        len = len / 2 + len % 2;

        // update cache to pList; 
        delete[] pList; 
        pList = new LNode<int>*[len];
        for (size_t qndex = 0; qndex < len; ++qndex) {
            pList[qndex] = cacheList[qndex];
        }
        delete[] cacheList; 
    }

    // update pList to list; 
    for (size_t qndex = 0; qndex < len; ++qndex) {
        list[qndex] = pList[0][qndex];
    }

    delete[] pList; 
    return; 
}