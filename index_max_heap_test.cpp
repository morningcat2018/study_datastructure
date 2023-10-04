#include <iostream>
#include "index_max_heap.h"

using namespace std;

void print(IndexMaxHeap<int> &indexHeap)
{
    while (!indexHeap.isEmpty())
    {
        cout << indexHeap.extractTop() << " ";
    }
    cout << endl;
}

// g++ index_max_heap_test.cpp && ./a.out
int main()
{
    IndexMaxHeap<int> indexHeap(10);
    srand(time(NULL));
    for (int i = 0; i < 15; i++)
        indexHeap.insert(i, rand() % 100);
    print(indexHeap);

    indexHeap.insert(0, 5);
    indexHeap.insert(1, 7);
    indexHeap.insert(2, 1);
    indexHeap.change(0, 100);
    print(indexHeap);

    return 0;
}