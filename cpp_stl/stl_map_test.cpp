#include <iostream>
#include <map>

using namespace std;

// g++ -std=c++11 stl_map_test.cpp
int main()
{
    map<string, int> m; // 创建一个空的string到int的map

    m["apple"] = 10;                   // 将键"apple"映射到值10
    m.insert(make_pair("banana", 20)); // 将键"banana"映射到值20

    int x = m["apple"];     // 获取键"apple"对应的值
    int y = m.at("banana"); // 获取键"banana"对应的值

    m["apple"] = 20;     // 将键"apple"对应的值修改为20
    m.at("banana") = 30; // 将键"banana"对应的值修改为30

    m.erase("apple"); // 删除键为"apple"的元素

    int size = m.size(); // 获取map中元素的个数

    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    if (m.count("apple"))
    {
        cout << "apple exists" << endl;
    }
    return 0;
}