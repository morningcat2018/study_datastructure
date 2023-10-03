#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <cassert>
#include "index0_none.h"

// using namespace std;

// 最小堆
template <typename Item>
class MinHeap
{
private:
    Item *data;
    int count;
    int capacity;
    void shiftUp(int index);
    void shiftDown(int index);

public:
    MinHeap(int capacity);
    MinHeap(Item arr[], int arr_length);
    ~MinHeap();
    int size();
    bool isEmpty();
    void insert(Item item);
    Item extractTop();
    Item getTop();
};

template <typename Item>
MinHeap<Item>::MinHeap(int capacity)
{
    
    data = new Item[capacity + INDEX_0_FLAG];
    count = 0;
    this->capacity = capacity;
}

template <typename Item>
MinHeap<Item>::MinHeap(Item arr[], int arr_length)
{
    data = new Item[arr_length + INDEX_0_FLAG];
    capacity = arr_length;

    // 索引0不存储数据
    for (int i = 0; i < arr_length; i++)
        data[i + 1] = arr[i];
    count = arr_length;

    for (int i = getNotLeaf(count); i >= 1; i--)
        this->shiftDown(i);
}

template <typename Item>
MinHeap<Item>::~MinHeap()
{
    delete[] data;
}

template <typename Item>
int MinHeap<Item>::size()
{
    return count;
}

template <typename Item>
bool MinHeap<Item>::isEmpty()
{
    return count == 0;
}

template <typename Item>
void MinHeap<Item>::insert(Item item)
{
    if (count + 1 > capacity)
    {
        capacity = capacity * 2;
        Item *dataNew = new Item[capacity + 1];
        for (int i = 1; i <= count; i++)
        {
            dataNew[i] = data[i];
        }
        delete data;
        data = dataNew;
    }
    data[count + 1] = item;
    count++;
    this->shiftUp(count);
}

template <typename Item>
Item MinHeap<Item>::extractTop()
{
    assert(count > 0);
    Item heapTop = data[1];
    std::swap(data[1], data[count]);
    count--;
    this->shiftDown(1);
    return heapTop;
}

template <typename Item>
Item MinHeap<Item>::getTop()
{
    assert(count > 0);
    return data[1];
}

template <typename Item>
void MinHeap<Item>::shiftUp(int index)
{
    // 索引1位置是根节点
    while (index > 1 && data[getParent(index)] > data[index])
    {
        std::swap(data[getParent(index)], data[index]);
        index = getParent(index); // 父节点
    }
}

template <typename Item>
void MinHeap<Item>::shiftDown(int index)
{
    // 左孩子节点索引 <= count 表示索引index节点有左孩子节点
    while (getLeftChird(index) <= count)
    {
        int temp = getLeftChird(index); // 初始化为左孩子节点
        if (getRightChird(index) <= count)
        {
            // 当有右孩子节点时
            if (data[getRightChird(index)] < data[getLeftChird(index)])
            {
                temp = getRightChird(index);
            }
        }
        if (data[index] <= data[temp])
        {
            break;
        }
        std::swap(data[temp], data[index]);
        index = temp;
    }
}

#endif // MIN_HEAP_H