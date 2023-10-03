#include <iostream>
#include "max_heap.h"

using namespace std;

// g++ max_heap_test.cpp && ./a.out
int main()
{
    MaxHeap<int> maxHeap(10);
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
        maxHeap.insert(rand() % 100);

    // maxHeap.insert(46);
    // maxHeap.insert(10);
    // maxHeap.insert(59);
    // maxHeap.insert(82);
    // maxHeap.insert(50);
    // maxHeap.insert(22);

    while (!maxHeap.isEmpty())
    {
        // maxHeap.extractMax();
        cout << maxHeap.extractMax() << " ";
    }
    cout << endl;
    return 0;
}