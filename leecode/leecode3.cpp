#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string str)
    {
        unordered_set<char> existSet;
        int max_length = 0;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (max_length == 0 || existSet.find(ch) != existSet.end())
            {
                existSet.insert(ch);
                max_length++;
                continue;
            }

            cout << ch << endl;
        }

        return 0;
    };
};

// g++ -std=c++11 leecode3.cpp && ./a.out
int main()
{

    Solution solu;
    string str = "abcabcaa";
    solu.lengthOfLongestSubstring(str);

    return 0;
}