#include <iostream>

using namespace std;

namespace first_space
{
    void func()
    {
        cout << "Inside first_space func" << endl;
    }
}
namespace second_space
{
    void func()
    {
        cout << "Inside second_space func" << endl;
    }
}

// g++ lib_namespace_test.cpp && ./a.out
int main()
{
    first_space::func();
    return 0;
}