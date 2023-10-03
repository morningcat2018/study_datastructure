#include <iostream>
#include "heap_sort.h"

using namespace std;

// g++ heap_sort_test.cpp && ./a.out
int main()
{
    const int n = 10;
    int arr[n];// = {10,3,23,12,34,65,43,23,54,11};
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
    

    // heap_sort1(arr, n);
    // heap_sort2(arr, n);
    heap_sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}