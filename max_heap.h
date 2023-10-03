#ifndef MAX_HEAP_H
#define MAX_HEAP_H

// #include <algorithm>
#include <cassert>

using namespace std;

// 最大堆
template <typename Item>
class MaxHeap
{
private:
    Item *data;
    int count;
    int capacity;
    void shiftUp(int index);
    void shiftDown(int index);
    void print()
    {
        for (int i = 1; i <= count; i++)
            cout << data[i] << " ";
        cout << endl;
    }

public:
    MaxHeap(int capacity);
    MaxHeap(Item arr[], int arr_length);
    ~MaxHeap();
    int size();
    bool isEmpty();
    void insert(Item item);
    // 从最大堆中取出堆顶元素, 即堆中所存储的最大数据
    Item extractMax();
    // 获取最大堆中的堆顶元素
    Item getMax();
};

template <typename Item>
MaxHeap<Item>::MaxHeap(int capacity)
{
    // 索引0位置不存储数据
    data = new Item[capacity + 1];
    count = 0;
    this->capacity = capacity;
}

template <typename Item>
MaxHeap<Item>::MaxHeap(Item arr[], int arr_length)
{
    data = new Item[arr_length + 1];
    capacity = arr_length;

    for (int i = 0; i < arr_length; i++)
        data[i + 1] = arr[i];
    count = arr_length;

    for (int i = count / 2; i >= 1; i--)
        this->shiftDown(i);
}

template <typename Item>
MaxHeap<Item>::~MaxHeap()
{
    delete[] data;
}

template <typename Item>
int MaxHeap<Item>::size()
{
    return count;
}

template <typename Item>
bool MaxHeap<Item>::isEmpty()
{
    return count == 0;
}

template <typename Item>
void MaxHeap<Item>::insert(Item item)
{
    // assert(count + 1 <= capacity);
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
        // cout << "data grew" << endl;
    }
    data[count + 1] = item;
    count++;
    this->shiftUp(count);
    // print();
}

template <typename Item>
Item MaxHeap<Item>::extractMax()
{
    assert(count > 0);
    Item heapTop = data[1];
    std::swap(data[1], data[count]);
    count--;
    this->shiftDown(1);
    // print();
    return heapTop;
}

template <typename Item>
Item MaxHeap<Item>::getMax()
{
    assert(count > 0);
    return data[1];
}

template <typename Item>
void MaxHeap<Item>::shiftUp(int index)
{
    // 索引1位置是根节点
    while (index > 1 && data[index / 2] < data[index])
    {
        std::swap(data[index / 2], data[index]);
        index = index / 2; // 父节点
    }
}

template <typename Item>
void MaxHeap<Item>::shiftDown(int index)
{
    // index*2 <= count 表示索引index节点有左孩子节点
    while (index * 2 <= count)
    {
        int temp = index * 2; // 初始化为左孩子节点
        if (index * 2 + 1 <= count)
        {
            // 当有右孩子节点时
            if (data[index * 2 + 1] > data[index * 2])
            {
                temp = index * 2 + 1;
            }
        }
        if (data[index] >= data[temp])
        {
            break;
        }
        std::swap(data[temp], data[index]);
        index = temp;
    }
}

#endif // MAX_HEAP_H