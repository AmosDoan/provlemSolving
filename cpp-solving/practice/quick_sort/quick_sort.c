#include "quick_sort.h"

void quick_sort(int *arr, int start, int last)
{
    int pivot = last;
    int left = start, right = last - 1; 

    if(start >= last)
        return;

    while(left <= right)
    {
        while((arr[left] <= arr[pivot]) &&
              (left <= right))
            left++;

        while((arr[right] >= arr[pivot]) &&
              (left <= right))
            right--;

        // RIGHT가 나중에 계산되므로, LEFT를 넘어가는 생기는 경우가 생겨버림
        if(left <= right)
            SWAP(arr[left], arr[right]);
    }

    if(arr[left] > arr[right])
    {
        SWAP(arr[left], arr[pivot]);
        // Left Side
        quick_sort(arr, start, left - 1);
        // Right Side
        quick_sort(arr, left + 1, last);
    }
    else
    {
        SWAP(arr[right], arr[pivot]);
        quick_sort(arr, start, right - 1);
        // Right Side
        quick_sort(arr, right + 1, last);
    }
}
