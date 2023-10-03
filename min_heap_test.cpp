#include <iostream>
#include "min_heap.h"

using namespace std;

// g++ min_heap_test.cpp && ./a.out
int main()
{
    MinHeap<int> minHeap(10);
    srand(time(NULL));
    for (int i = 0; i < 12; i++)
        minHeap.insert(rand() % 100);

    while (!minHeap.isEmpty())
    {
        cout << minHeap.extractTop() << " ";
    }
    cout << endl;
    return 0;
}