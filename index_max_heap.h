#ifndef INDEX_MAX_HEAP_H
#define INDEX_MAX_HEAP_H

#include <cassert>
#include "index0_none.h"

// 索引最大堆
template <typename Item>
class IndexMaxHeap
{
private:
    Item *data;
    int *indexes;
    int *reverse;
    int count;
    int capacity;
    void shiftUp(int index);
    void shiftDown(int index);
    void __print()
    {
        for (int i = INDEX_0_FLAG; i < count + INDEX_0_FLAG; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }

public:
    IndexMaxHeap(int capacity);
    IndexMaxHeap(Item arr[], int arr_length);
    ~IndexMaxHeap();
    int size();
    bool isEmpty();
    void insert(int i, Item item);
    Item extractTop();
    int extractTopIndex();
    Item getTop();
    Item getItem(int index);
    void change(int index, Item newItem);
};

template <typename Item>
IndexMaxHeap<Item>::IndexMaxHeap(int capacity)
{
    data = new Item[capacity + INDEX_0_FLAG];
    indexes = new int[capacity + INDEX_0_FLAG];

    reverse = new int[capacity + INDEX_0_FLAG];
    for (int i = 0; i < capacity + INDEX_0_FLAG; i++)
    {
        reverse[i] = -1;
    }

    count = 0;
    this->capacity = capacity;
}

template <typename Item>
IndexMaxHeap<Item>::IndexMaxHeap(Item arr[], int arr_length)
{
    // TODO 
    data = new Item[arr_length + INDEX_0_FLAG];
    // indexes = new int[capacity + INDEX_0_FLAG];
    // reverse = new int[capacity + INDEX_0_FLAG];
    capacity = arr_length;

    for (int i = 0; i < arr_length; i++)
        data[i] = arr[i];
    count = arr_length;

    for (int i = getNotLeaf(count); i >= INDEX_0_FLAG; i--)
        this->shiftDown(i);
}

template <typename Item>
IndexMaxHeap<Item>::~IndexMaxHeap()
{
    delete[] data;
    delete[] indexes;
    delete[] reverse;
}

template <typename Item>
int IndexMaxHeap<Item>::size()
{
    return count;
}

template <typename Item>
bool IndexMaxHeap<Item>::isEmpty()
{
    return count == 0;
}

// index 为插入索引,从0开始
template <typename Item>
void IndexMaxHeap<Item>::insert(int index, Item item)
{
    if (count + INDEX_0_FLAG > capacity)
    {
        capacity = capacity * 2;
        Item *dataNew = new Item[capacity + INDEX_0_FLAG];
        for (int i = INDEX_0_FLAG; i < count + INDEX_0_FLAG; i++)
        {
            dataNew[i] = data[i];
        }
        delete data;
        data = dataNew;
    }
    assert(index >= 0 && index < capacity);

    index = index + INDEX_0_FLAG;
    data[index] = item;

    indexes[count + INDEX_0_FLAG] = index;
    // reverse[index] = count + INDEX_0_FLAG;

    count++;
    this->shiftUp(count - 1 + INDEX_0_FLAG);
    // __print();
}

template <typename Item>
Item IndexMaxHeap<Item>::extractTop()
{
    assert(count > 0);
    Item heapTop = data[indexes[INDEX_0_FLAG]];
    std::swap(indexes[INDEX_0_FLAG], indexes[count - 1 + INDEX_0_FLAG]);

    // reverse[indexes[INDEX_0_FLAG]] = INDEX_0_FLAG;
    // reverse[indexes[count - 1 + INDEX_0_FLAG]] = -1;

    count--;
    this->shiftDown(INDEX_0_FLAG);
    // __print();
    return heapTop;
}

template <typename Item>
int IndexMaxHeap<Item>::extractTopIndex()
{
    assert(count > 0);
    int heapTop = indexes[INDEX_0_FLAG] - INDEX_0_FLAG;
    std::swap(indexes[INDEX_0_FLAG], indexes[count - 1 + INDEX_0_FLAG]);
    // reverse[indexes[INDEX_0_FLAG]] = INDEX_0_FLAG;
    // reverse[indexes[count - 1 + INDEX_0_FLAG]] = -1;

    count--;
    this->shiftDown(INDEX_0_FLAG);
    // __print();
    return heapTop;
}

template <typename Item>
Item IndexMaxHeap<Item>::getTop()
{
    assert(count > 0);
    return data[INDEX_0_FLAG];
}

template <typename Item>
Item IndexMaxHeap<Item>::getItem(int index)
{
    return data[index + INDEX_0_FLAG];
}

template <typename Item>
void IndexMaxHeap<Item>::change(int index, Item newItem)
{
    index = index + INDEX_0_FLAG;
    data[index] = newItem;

    // 找到indexes[k] = index , k 表示data[index]在堆中的位置
    // 之后 shiftUp(k) 和 shiftDown(k)
    // for (int k = INDEX_0_FLAG; k < count + INDEX_0_FLAG; k++)
    // {
    //     if (indexes[k] == index)
    //     {
    //         shiftUp(k);
    //         shiftDown(k);
    //     }
    // }

    // 使用 reverse 数组的优化版
    int rev = reverse[index];
    shiftUp(rev);
    shiftDown(rev);
}

template <typename Item>
void IndexMaxHeap<Item>::shiftUp(int index)
{
    // 索引0位置是根节点
    while (index > INDEX_0_FLAG && data[indexes[getParent(index)]] < data[indexes[index]])
    {
        std::swap(indexes[getParent(index)], indexes[index]);
        // reverse[indexes[getParent(index)]] = getParent(index);
        // reverse[indexes[index]] = index;
        index = getParent(index); // 父节点
    }
}

template <typename Item>
void IndexMaxHeap<Item>::shiftDown(int index)
{
    // 左孩子节点索引 <= count 表示索引index节点有左孩子节点
    while (getLeftChird(index) < count + INDEX_0_FLAG)
    {
        int temp = getLeftChird(index); // 初始化为左孩子节点
        if (getRightChird(index) < count + INDEX_0_FLAG)
        {
            // 当有右孩子节点时
            if (data[indexes[getRightChird(index)]] > data[indexes[getLeftChird(index)]])
            {
                temp = getRightChird(index);
            }
        }
        if (data[indexes[index]] >= data[indexes[temp]])
        {
            break;
        }
        std::swap(indexes[temp], indexes[index]);
        // reverse[indexes[temp]] = temp;
        // reverse[indexes[index]] = index;
        index = temp;
    }
}

#endif // INDEX_MAX_HEAP_H