#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        //       base case;

        ListNode *temp = head;

        for (int i = 0; i < k; i++)
        {

            if (temp == nullptr)
                return head;
            temp = temp->next;
        }

        //       step 1;

        ListNode *next = nullptr;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        int count = 0;

        while (curr != nullptr && count < k)
        {

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        //       step 2; recursion;

        if (next != nullptr)
        {

            head->next = reverseKGroup(next, k);
        }

        //       step 3; return head of reverse list;

        return prev;
    }
};

int main()
{

    return 0;
}