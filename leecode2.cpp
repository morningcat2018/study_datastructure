#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct ListNode *get_list(int *data, int data_length)
    {
        struct ListNode *head = nullptr;
        struct ListNode *p = nullptr;
        for (int i = 0; i < data_length; i++)
        {
            ListNode *node = new ListNode(data[i]);
            // struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
            // node->val = data[i];
            // node->next = nullptr;
            if (head == nullptr)
            {
                p = node;
                head = p;
            }
            else
            {
                p->next = node;
                p = node;
            }
        }
        return head;
    };
    void print(struct ListNode *head)
    {
        struct ListNode *p = head;
        while (p != nullptr)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    };
    ListNode *reverse(ListNode *head)
    {
        ListNode *reverse_linked = nullptr;
        ListNode *p = head;
        while (p != nullptr)
        {
            ListNode *next = p->next;
            p->next = reverse_linked;
            reverse_linked = p;
            p = next;
        }
        return reverse_linked;
    };
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *reverse_l1 = l1;
        ListNode *reverse_l2 = l2;

        ListNode *head = nullptr;
        ListNode *p = nullptr;
        int flag = 0;
        while (reverse_l1 != nullptr || reverse_l2 != nullptr || flag > 0)
        {
            int val = flag;
            if (reverse_l1 != nullptr)
            {
                val += reverse_l1->val;
                reverse_l1 = reverse_l1->next;
            }
            if (reverse_l2 != nullptr)
            {
                val += reverse_l2->val;
                reverse_l2 = reverse_l2->next;
            }
            if (val > 9)
            {
                flag = 1;
                val = val - 10;
            }
            else
                flag = 0;
            ListNode *node = new ListNode(val);
            if (head == nullptr)
            {
                p = node;
                head = p;
            }
            else
            {
                p->next = node;
                p = node;
            }
        }
        return head;
    };
};

// g++ -std=c++11 leecode2.cpp && ./a.out
int main()
{

    Solution solu;
    int nums[] = {2, 4, 9};
    int nums2[] = {5, 6, 4, 9};

    ListNode *l1 = solu.get_list(nums, sizeof(nums) / sizeof(nums[0]));
    // solu.print(l1);
    // ListNode *reverse_l1 = solu.reverse(l1);
    // solu.print(reverse_l1);
    
    ListNode *l2 = solu.get_list(nums2, sizeof(nums2) / sizeof(nums2[0]));
    ListNode *sum_list = solu.addTwoNumbers(l1, l2);
    solu.print(sum_list);

    return 0;
}