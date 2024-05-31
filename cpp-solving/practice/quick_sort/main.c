#include <stdio.h>

#include "quick_sort.h"

//#define SIZE_ARR 7
#define SIZE_ARR 9

int main(int argc, char **argv)
{
    //int test[SIZE_ARR] = {5, 3, 7, 6, 2, 1, 4};
    int test[SIZE_ARR] = {17, 89, 71, 113, 47, 59, 5, 101, 29};
    int test2[SIZE_ARR] = {17, 113, 47, 89, 71, 59, 29, 101, 5};

    quick_sort(test, 0, SIZE_ARR - 1);

    for(int i = 0; i < SIZE_ARR; i++)
        printf("%dth %d\n", i, test[i]);

    quick_sort(test2, 0, SIZE_ARR - 1);

    for(int i = 0; i < SIZE_ARR; i++)
        printf("%dth %d\n", i, test2[i]);



    return 0;
}
