#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "10_25.h"

void sort3Colors(int* list, size_t n)
{
    // whiteHead == 0 means no red;
    // whiteHead == blueHead means no white;
    // blueHead == n means no blue;

    size_t whiteHead = 0;
    while (whiteHead < n && list[whiteHead] == 1) {
        ++whiteHead;
    }

    size_t blueHead = whiteHead;
    while (blueHead < n && list[blueHead] == 2) {
        ++blueHead;
    }

    size_t mov = blueHead;
    while (mov < n) {
        switch (list[mov]) {
            case 1: 
                ++whiteHead;
                list[whiteHead - 1] = 1;
            case 2:
                ++blueHead;
                list[blueHead - 1] = 2;
            case 3:
                list[mov] = 3; 
                ++mov;
                break;
        }
    }

    return;
}
