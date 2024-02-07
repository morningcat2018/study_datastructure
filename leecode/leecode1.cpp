#include <iostream>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++)
    {
        int other_num = target - nums[i];
        if (numMap.count(other_num) > 0)
        {
            int other_index = numMap[other_num];
            if (other_index != i)
                return {i, other_index};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

// g++ -std=c++11 leecode1.cpp && ./a.out
int main()
{
    vector<int> v{2, 7, 11, 11};

    vector<int> x = twoSum(v, 22);
    cout << x.size() << endl;

    return 0;
}