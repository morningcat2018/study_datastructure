#include <queue>
#include <iostream>

using namespace std;

// g++ -std=c++11 stl_queue_test.cpp
int main()
{
    queue<int> q;      // 创建一个空的int类型queue
    q.push(10);        // 向queue尾部添加一个元素
    int x = q.front(); // 获取queue头部的元素
    int y = q.back();  // 获取queue尾部的元素
    // q.pop();             // 删除queue头部的元素
    int size = q.size(); // 获取queue中元素的个数
    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    while (!q.empty())
    {
        int x = q.front();
        cout << x << " ";
        q.pop();
    }
}