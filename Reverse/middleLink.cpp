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
    /*
     ListNode *getMiddle(ListNode *head){

       if(head == nullptr || head->next || nullptr)
         return head;

   //     if only two node exist;

       // if(head->next->next == nullptr)
       //   return head->next;

       ListNode*slow = head;
       ListNode*fast = head->next;

       while(fast != nullptr){

         fast = fast->next;

         if(fast != nullptr){
           fast = fast->next;
         }

         slow = slow->next;
       }

       return slow;

     }

     */

    /*
    int getlen( ListNode*head){

      int len = 0;

      while(head != nullptr){

        len++;

        head = head->next;
      }

      return len;
    }

    */
    // ListNode* middleNode(ListNode* head) {

    // return getMiddle(head);

    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    /*
    int len = getlen(head);

      int ans = len/2;
      int count = 0;

      ListNode*temp = head;

      while(count < ans){

        temp = temp->next;
        count++;
      }

      return temp;

      */
    // }
};
int main()
{

    return 0;
}