#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <iostream>
#include "max_heap.h"

using namespace std;

template <typename T>
void heap_sort1(T arr[], int arr_length)
{
    // MaxHeap<T> maxHeap(arr_length);
    // for (int i = 0; i < arr_length; i++)
    //     maxHeap.insert(arr[i]);

    MaxHeap<T> maxHeap(arr, arr_length);
    // for (int i = arr_length - 1; i >= 0; i--)
    for(int i=0;i<arr_length;i++)
        arr[i] = maxHeap.extractMax();
}

#endif // HEAP_SORT_H