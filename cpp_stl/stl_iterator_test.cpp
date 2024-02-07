#include <iostream>
#include <vector>

using namespace std;

// g++ -std=c++11 stl_iterator_test.cpp
int main()
{
    vector<int> v = {1, 2, 3, 4, 5}; // C++11特性, 编译时: g++ -std=c++11 source.cpp
    auto it = v.begin(); // 获取vector的起始迭代器

    // 迭代器的比较：
    auto end = v.end();
    while (it != end)
    {
        int x = *it; // 获取迭代器指向的元素的值
        cout << x << " ";
        it++; // 将迭代器指向下一个元素
    }

    // 迭代器的逆向遍历：
    auto it2 = v.rbegin(); // 获取vector的逆向迭代器
    auto end2 = v.rend();
    while (it2 != end2)
    {
        cout << *it2 << " ";
        it2++;
    }

    return 0;
}
