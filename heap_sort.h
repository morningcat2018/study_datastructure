#ifndef HEAP_SORT_H
#define HEAP_SORT_H

// #include <iostream>
#include "max_heap.h"

// using namespace std;

template <typename T>
void heap_sort1(T arr[], int arr_length)
{
    MaxHeap<T> maxHeap(arr_length);
    for (int i = 0; i < arr_length; i++)
        maxHeap.insert(arr[i]);

    for (int i = arr_length - 1; i >= 0; i--)
        // for(int i=0;i<arr_length;i++)
        arr[i] = maxHeap.extractMax();
}

template <typename T>
void heap_sort2(T arr[], int arr_length)
{
    MaxHeap<T> maxHeap(arr, arr_length);
    for (int i = arr_length - 1; i >= 0; i--)
        arr[i] = maxHeap.extractMax();
}

template <typename T>
void __shiftDown(T arr[], int arr_length, int index)
{
    // index*2+1 < arr_length 表示索引index节点有左孩子节点
    while (index * 2 + 1 < arr_length)
    {
        int temp = index * 2 + 1; // 初始化为左孩子节点
        if (index * 2 + 2 < arr_length)
        {
            // 当有右孩子节点时
            if (arr[index * 2 + 2] > arr[index * 2 + 1])
            {
                temp = index * 2 + 2;
            }
        }
        if (arr[index] >= arr[temp])
        {
            break;
        }
        std::swap(arr[temp], arr[index]);
        index = temp;
    }
}

template <typename T>
void heap_sort(T arr[], int arr_length)
{
    // heapify
    for (int i = (arr_length - 1) / 2; i >= 0; i--)
        __shiftDown(arr, arr_length, i);
    for (int i = arr_length - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

#endif // HEAP_SORT_H