#include <iostream>
using namespace std;

//   Definition for singly-linked list.
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

ListNode * reverse(ListNode*head){
    
//     base case;
    
    if(head == nullptr || head->next == nullptr){
      return head;
    }
    
    
    ListNode* Chotahead = reverse(head->next);
    
    head->next->next = head;
    head->next = nullptr;
    
    return Chotahead;
  }



    void solve(ListNode *&head, ListNode *curr, ListNode *prev)
    {

        //     base case;
        if (curr == nullptr)
        {
            head = prev;
            return;
        }

        //    Recursive part ;

        ListNode *forward = curr->next;
        solve(head, forward, curr);
        curr->next = prev;
    }
    ListNode *reverseList(ListNode *head)
    {

        //       Recursive call ;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        solve(head, curr, prev);
        return head;

        /*

           if(head == nullptr || head->next == nullptr)

             return head;


           ListNode* prev = nullptr;
           ListNode* curr = head;
           ListNode*forward = nullptr;

           while(curr != nullptr){

             forward = curr->next;
             curr->next = prev;

             prev = curr;
             curr = forward;

           }
           return prev;
           */
    }
};
int main()
{

    return 0;
}