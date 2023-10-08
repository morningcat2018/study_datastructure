#include <iostream>
#include <stack>

using namespace std;

// g++ -std=c++11 stl_stack_test.cpp
int main()
{
    stack<int> s;        // 创建一个空的int类型stack
    s.push(10);          // 向stack顶部添加一个元素
    int x = s.top();     // 获取stack顶部的元素
    s.pop();             // 删除stack顶部的元素
    int size = s.size(); // 获取stack中元素的个数
    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }
    
    while (!s.empty())
    {
        int x = s.top();
        cout << x << " ";
        s.pop();
    }
    return 0;
}