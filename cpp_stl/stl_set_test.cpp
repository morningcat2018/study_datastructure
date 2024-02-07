#include <iostream>
#include <set>

using namespace std;

// g++ -std=c++11 stl_set_test.cpp
int main()
{
    set<int> s;   // 创建一个空的int类型set
    s.insert(10); // 向set中插入一个元素

    set<int>::iterator it = s.find(10); // 查找set中是否存在值为10的元素
    if (it != s.end())
    {
        cout << "item exists" << endl;
    }
    s.erase(10);         // 删除set中值为10的元素
    int size = s.size(); // 获取set中元素的个数
    if (s.empty())
    {
        cout << "set is empty" << endl;
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}