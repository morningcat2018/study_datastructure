
#include <iostream>
using namespace std;

template <typename T>
int binary_search1(T arr[], int arr_length, const T target)
{
    int l = 0;
    int r = arr_length - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target)
            return mid;
        if (target < arr[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

template <typename T>
int floor(T arr[], int arr_length, const T target) {}

template <typename T>
int ceil(T arr[], int arr_length, const T target) {}

// g++ binary_search.cpp && ./a.out
int main()
{
    int arr[] = {1, 5, 7, 9, 10, 14, 18, 23, 26, 29, 31, 37, 38, 41, 43, 47, 56};
    int index = binary_search1(arr, 17, 29);
    cout << index << endl;
    return 0;
}