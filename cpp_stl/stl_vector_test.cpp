#include <iostream>
#include <vector>

using namespace std;

// g++ -std=c++11 stl_vector_test.cpp
int main()
{
    vector<int> v;             // 创建一个空的int类型vector
    vector<string> v2(10);     // 创建一个包含10个空字符串的vector
    vector<double> v3(5, 2.5); // 创建一个包含5个值为2.5的double类型vector

    v.push_back(10);        // 向vector尾部添加一个元素
    v.insert(v.begin(), 5); // 在vector头部插入一个元素

    int x = v[0];    // 获取vector中第一个元素的值
    int y = v.at(1); // 获取vector中第二个元素的值

    v[0] = 20;    // 修改vector中第一个元素的值为20
    v.at(1) = 30; // 修改vector中第二个元素的值为30

    v.pop_back();       // 删除vector尾部的元素
    v.erase(v.begin()); // 删除vector头部的元素

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    vector<int>::iterator iter = v.begin();
    while (iter != v.end())
    {
        cout << *iter << endl;
        iter++;
    }

    v.clear(); // 删除vector中所有的元素
    return 0;
}