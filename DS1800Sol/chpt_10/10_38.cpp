#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_38.h" 

void radixSort(LinkedList<unsigned int> list, size_t sortDigit, size_t digitNum)
{
    // init buckets; 
    LinkedList<unsigned int>* buckets = new LinkedList<unsigned int>[digitNum];
    LNode<unsigned int>** rears = new LNode<unsigned int>*[digitNum];
    for (size_t index = 0; index < digitNum; ++index) {
        buckets[index] = new LNode<unsigned int>;
        rears[index] = buckets[index]; 
    }

    size_t countSortedDigit = 0; 
    while (countSortedDigit < sortDigit) {
        while (list->next != nullptr) {
            // find the digit to be sorted; 
            size_t tarDigit = list->next->data; 
            for (size_t index = 0; index < countSortedDigit; ++index) {
                tarDigit /= digitNum;
            }
            tarDigit %= digitNum;

            // push into corresponding queue; 
            rears[tarDigit]->next = list->next;

            list->next = list->next->next;
            rears[tarDigit] = rears[tarDigit]->next;
            
            rears[tarDigit]->next = nullptr; 
        }

        // recombine list; 
        LNode<unsigned int>* rear = list; 
        for (size_t index = 0; index < digitNum; ++index) {
            rear->next = buckets[index]->next;
            if (rear->next != nullptr) {
                rear = rears[index]; 
            }
        }

        // clear buckets and rears; 
        for (size_t index = 0; index < digitNum; ++index) {
            buckets[index]->next = nullptr;
            rears[index] = buckets[index];
        }

        ++countSortedDigit; 
    }



    // del buckets; 
    for (size_t index = 0; index < digitNum; ++index) {
        delete buckets[index]; 
    }
    delete[] buckets; 

    return; 
}