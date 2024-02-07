#include <iostream>
#include <deque>

using namespace std;

// g++ -std=c++11 stl_deque_test.cpp
int main()
{
    deque<int> dq;             // 创建一个空的int类型deque
    deque<string> dq2(10);     // 创建一个包含10个空字符串的deque
    deque<double> dq3(5, 2.5); // 创建一个包含5个值为2.5的double类型deque

    dq.push_back(10); // 向deque尾部添加一个元素
    dq.push_front(5); // 向deque头部添加一个元素

    int x = dq.front(); // 获取deque中第一个元素的值
    int y = dq.back();  // 获取deque中最后一个元素的值

    dq.front() = 20; // 修改deque中第一个元素的值为20
    dq.back() = 30;  // 修改deque中最后一个元素的值为30

    dq.pop_front(); // 删除deque头部的元素
    dq.pop_back();  // 删除deque尾部的元素

    int size = dq.size(); // 获取deque中元素的个数

    for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }

    dq.clear(); // 删除deque中所有的元素
}