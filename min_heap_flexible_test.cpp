#include <iostream>
#include "min_heap_flexible.h"

using namespace std;

// g++ min_heap_flexible_test.cpp && ./a.out
int main()
{
    MinHeap<int> minHeap(10);
    srand(time(NULL));
    for (int i = 0; i < 15; i++)
        minHeap.insert(rand() % 100);

    // minHeap.insert(3);
    // minHeap.insert(1);
    // minHeap.insert(5);

    while (!minHeap.isEmpty())
    {
        // minHeap.extractTop();
        cout << minHeap.extractTop() << " ";
    }
    cout << endl;
    return 0;
}