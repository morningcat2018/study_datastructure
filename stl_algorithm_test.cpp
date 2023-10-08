#include <iostream>
// #include <vector>

// #include <algorithm> // 算法头文件
// #include <iterator>  // 迭代器头文件
#include <numeric>   // 数值算法头文件
// #include <random>    // 随机数生成器头文件
// #include <chrono>    // 日期和时间算法头文件
// #include <ctime>     // 时间头文件

using namespace std;

// g++ -std=c++11 stl_algorithm_test.cpp && ./a.out
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = find(v.begin(), v.end(), 3); // 查找值为3的元素
    if (it != v.end())
    {
        cout << "3 exists" << endl;
    }

    vector<int> v2 = {3, 1, 4, 1, 5, 9, 2, 6};
    sort(v2.begin(), v2.end()); // 对序列进行排序
    for (auto x : v2)
    {
        cout << x << " ";
    }
    cout << "v2 over" << endl;

    vector<int> v3(5);                    // 创建一个包含5个元素的空vector
    copy(v.begin(), v.end(), v3.begin()); // 将v中的元素拷贝到v2中
    for (auto x : v3)
    {
        cout << x << " ";
    }
    cout << "v3 over" << endl;

    int sum = accumulate(v.begin(), v.end(), 0); // 计算v中所有元素的和
    cout << "sum = " << sum << endl;

    vector<int> v4 = {1, 2, 3, 4, 5};
    random_shuffle(v4.begin(), v4.end()); // 生成随机排列
    for (auto x : v4)
    {
        cout << x << " ";
    }
    cout << "v4 over" << endl;

    return 0;
}