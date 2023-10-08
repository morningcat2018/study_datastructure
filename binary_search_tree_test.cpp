#include "binary_search_tree.h"
#include "FileOps.h"

// g++ binary_search_tree_test.cpp && ./a.out
int main()
{
    time_t start_time = clock();
    string file_name = "1.txt";
    vector<string> words;
    if (FileOps::readFile(file_name, words))
    {
        cout << "总词数:" << words.size() << endl;
        // time_t start_time = clock();
        BST<string, int> bst;
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
        {
            // cout << *iter << endl;
            int *count = bst.search(*iter);
            if (count == NULL)
            {
                bst.insert(*iter, 1);
                // cout << bst.size() << endl;
            }

            else
            {
                (*count)++;
                // int c = (*count) + 1;
                // cout << "----->" << c << endl;
                // bst.insert(*iter, c);
            }
        }
        time_t end_time = clock();

        string search_word = "god";
        int count = bst.contain(search_word) ? *bst.search(search_word) : 0;
        cout << "出现次数:" << count << endl;
        cout << "花费时间:" << (end_time - start_time) / 1000 << " ms." << endl;
    }
    return 0;
}