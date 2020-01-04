#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <stdio.h>

#define SWAP(A, B)      \
do{                     \
    typeof(A) TEMP = A; \
    A = B;              \
    B = TEMP;           \
} while(0)

void quick_sort(int *arr, int start, int last);

#endif
