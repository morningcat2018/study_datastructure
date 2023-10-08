#include <iostream>
#include <list>

using namespace std;

// g++ -std=c++11 stl_list_test.cpp
int main()
{
    list<int> lst;             // 创建一个空的int类型list
    list<string> lst2(10);     // 创建一个包含10个空字符串的list
    list<double> lst3(5, 2.5); // 创建一个包含5个值为2.5的double类型list

    lst.push_back(10);          // 向list尾部添加一个元素
    lst.push_front(5);          // 向list头部添加一个元素
    lst.insert(lst.begin(), 3); // 在list头部插入一个元素

    int x = lst.front(); // 获取list中第一个元素的值
    int y = lst.back();  // 获取list中最后一个元素的值

    lst.front() = 20; // 修改list中第一个元素的值为20
    lst.back() = 30;  // 修改list中最后一个元素的值为30

    int size = lst.size(); // 获取list中元素的个数

    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }

    lst.pop_front();        // 删除list头部的元素
    lst.pop_back();         // 删除list尾部的元素
    lst.erase(lst.begin()); // 删除list头部的元素

    lst.clear(); // 删除list中所有的元素
    return 0;
}